/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_subghz_phy.c
  * @author  MCD Application Team
  * @brief
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_subghz_phy.h"
#include "subghz_phy_app.h"
#include "sys_app.h"
#include "stm32_seq.h"

/* USER CODE BEGIN Includes */
#include "main.h"
#include "usart.h"
#include "rtc.h"
#include "app_version.h"
#include "stm32wlxx_hal_rcc.h"
/* USER CODE END Includes */

/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
static char APRS_Callsign[] = "DO2DKH-1";
static char APRS_Destination[] = "APLG01";

static uint8_t APRS_TransmitBuffer[255];
static uint8_t APRS_Header[] = {'<', 0xFF, 0x01};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
static int32_t MX_SubGHz_Phy_APRS_Send(NMEA_GPS_t *position, char *challsign, char *message);
static void MX_SubGHz_Phy_EnterSleep(void);
/* USER CODE END PFP */

/* Exported functions --------------------------------------------------------*/

void MX_SubGHz_Phy_Init(void)
{
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_1 */
	uint32_t InitCounter = 1;
  /* USER CODE END MX_SubGHz_Phy_Init_1 */
  SystemApp_Init();
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_1_1 */
  APP_LOG(TS_OFF, VLEVEL_M, "\n\rAPRS Demo\n\r");

  /* Get SubGHY_Phy APP version*/
  APP_LOG(TS_OFF, VLEVEL_M, "Application version:\tV%X.%X.%X\r\n",
          (uint8_t)(APP_VERSION_MAIN),
          (uint8_t)(APP_VERSION_SUB1),
          (uint8_t)(APP_VERSION_SUB2));
  /* USER CODE END MX_SubGHz_Phy_Init_1_1 */
  SubghzApp_Init();
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_2 */

  // Run the device initialization when a PoR or Pin reset has happened.
  if (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST) || __HAL_RCC_GET_FLAG(RCC_FLAG_PINRST))
  {
    APP_LOG(TS_OFF, VLEVEL_M, "Device reset...\n\r");
    if (MX_USART1_GPS_Init() != HAL_OK)
    {
    	// TODO
    }

    APP_LOG(TS_OFF, VLEVEL_M, "Initialization successful!\n\r");

    __HAL_RCC_CLEAR_RESET_FLAGS();
  }
  else
  {
  	APP_LOG(TS_OFF, VLEVEL_M, "Wake up\n\r");
    MX_USART1_GPS_WakeUp();
  }

  /* USER CODE END MX_SubGHz_Phy_Init_2 */
}

void MX_SubGHz_Phy_Process(void)
{
  /* USER CODE BEGIN MX_SubGHz_Phy_Process_1 */
	int32_t Status;
	NMEA_GPS_t GPS_Data;

/*
  APP_LOG(TS_OFF, VLEVEL_M, "Go\n\r");
	uint8_t Buffer[] = {0x3C, 0xFF, 0x01, 0x44, 0x4F, 0x32, 0x44, 0x4B,
											0x48, 0x2D, 0x37, 0x3E, 0x41, 0x50, 0x4C, 0x47,
											0x30, 0x31, 0x3A, 0x21, 0x34, 0x39, 0x33, 0x32,
											0x2E, 0x30, 0x35, 0x4E, 0x4C, 0x30, 0x31, 0x30,
											0x34, 0x37, 0x2E, 0x35, 0x30, 0x45, 0x26, 0x54,
											0x65, 0x73, 0x74, 0x32};
	SubghzApp_Transmit(Buffer, sizeof(Buffer));
  APP_LOG(TS_OFF, VLEVEL_M, "Done\n\r");
*/
	Status = MX_USART1_GPS_Get(&GPS_Data, 1000);
	if (Status == HAL_OK)
	{
		APP_LOG(TS_OFF, VLEVEL_M, "\tUTC: %s\n\r", GPS_Data.GPGGA.utc);
		APP_LOG(TS_OFF, VLEVEL_M, "\tLatitude: %s\n\r", GPS_Data.GPGGA.lat);
		APP_LOG(TS_OFF, VLEVEL_M, "\tLatitude direction: %c\n\r", GPS_Data.GPGGA.lat_dir);
		APP_LOG(TS_OFF, VLEVEL_M, "\tLongitude: %s\n\r", GPS_Data.GPGGA.lon);
		APP_LOG(TS_OFF, VLEVEL_M, "\tLongitude direction: %c\n\r", GPS_Data.GPGGA.lon_dir);
		//MX_SubGHz_Phy_APRS_Send(&GPS_Data, APRS_Callsign, "Test123");
		//HAL_Delay(100);

		//MX_SubGHz_Phy_EnterSleep();
	}

  /* USER CODE END MX_SubGHz_Phy_Process_1 */
  UTIL_SEQ_Run(UTIL_SEQ_DEFAULT);
  /* USER CODE BEGIN MX_SubGHz_Phy_Process_2 */

  /* USER CODE END MX_SubGHz_Phy_Process_2 */
}

/* USER CODE BEGIN EF */

/* USER CODE END EF */

/* Private Functions Definition -----------------------------------------------*/
/* USER CODE BEGIN PrFD */

void MX_SubGHz_Phy_EnterSleep(void)
{
  UART_WakeUpTypeDef WakeUpSelection;

  SubghzApp_Sleep();

  MX_USART1_GPS_Sleep();

  // Set the wake-up event
  WakeUpSelection.WakeUpEvent = UART_WAKEUP_ON_READDATA_NONEMPTY;
  if (HAL_UARTEx_StopModeWakeUpSourceConfig(&hlpuart1, WakeUpSelection) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
}

int32_t MX_SubGHz_Phy_APRS_Send(NMEA_GPS_t *gps, char *challsign, char *message)
{
	uint8_t TotalLength = 0;

	memcpy(&APRS_TransmitBuffer[TotalLength], APRS_Header, sizeof(APRS_Header));
	TotalLength += sizeof(APRS_Header);

	memcpy(&APRS_TransmitBuffer[TotalLength], challsign, strlen(challsign));
	TotalLength += strlen(challsign);

	APRS_TransmitBuffer[TotalLength] = '>';
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], APRS_Destination, strlen(APRS_Destination));
	TotalLength += strlen(APRS_Destination);

	APRS_TransmitBuffer[TotalLength] = ':';
	TotalLength += 1;

	APRS_TransmitBuffer[TotalLength] = '!';
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], gps->GPGGA.lat, 7);
	TotalLength += 7;

	memcpy(&APRS_TransmitBuffer[TotalLength], &gps->GPGGA.lat_dir, 1);
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], gps->GPGGA.lon, 8);
	TotalLength += 8;

	memcpy(&APRS_TransmitBuffer[TotalLength], &gps->GPGGA.lon_dir, 1);
	TotalLength += 1;

	if (message != NULL)
	{
		APRS_TransmitBuffer[TotalLength] = '&';
		TotalLength += 1;

		memcpy(&APRS_TransmitBuffer[TotalLength], message, strlen(message));
		TotalLength += strlen(message);
	}

	return SubghzApp_Transmit(APRS_TransmitBuffer, TotalLength);
}
/* USER CODE END PrFD */
