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
#include "usart.h"
/* USER CODE END Includes */

/* External variables ---------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct {
	char utc[11];
	char lat[10];
	char lat_dir[2];
	char lon[11];
	char lon_dir[2];
} GPS_GPGGA_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
static char APRS_Destination[] = "APLG01";

static uint8_t APRS_TransmitBuffer[255];
static uint8_t APRS_Header[] = {'<', 0xFF, 0x01};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
static int32_t MX_SubGHz_Phy_APRS_Send(GPS_GPGGA_t* p_Position, char* p_Challsign, char* p_Message);
/* USER CODE END PFP */

/* Exported functions --------------------------------------------------------*/

void MX_SubGHz_Phy_Init(void)
{
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_1 */

  /* USER CODE END MX_SubGHz_Phy_Init_1 */
  SystemApp_Init();
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_1_1 */

  /* USER CODE END MX_SubGHz_Phy_Init_1_1 */
  SubghzApp_Init();
  /* USER CODE BEGIN MX_SubGHz_Phy_Init_2 */

  UTIL_SEQ_Init();
  /* USER CODE END MX_SubGHz_Phy_Init_2 */
}

void MX_SubGHz_Phy_Process(void)
{
  /* USER CODE BEGIN MX_SubGHz_Phy_Process_1 */
	int32_t Status;
	char LineBuffer[128];
	GPS_GPGGA_t GPGGA_Data;

	memset(&GPGGA_Data, 0, sizeof(GPGGA_Data));

	Status = MX_USART1_GPS_GetLine(LineBuffer, sizeof(LineBuffer));
	if (Status == 0)
	{
	  // Format: $GPGGA,174857.000,4932.1285,N,01046.6422,E,2,9,0.90,388.3,M,47.9,M,,*5E
	  if (strstr(LineBuffer, "$GPGGA") != NULL)
	  {
	  	char* Token;

		  // Fetch and discard the header
		  strtok(LineBuffer, ",");

		  Token = strtok(NULL, ",");
		  memcpy(&GPGGA_Data.utc, Token, strlen(Token));
		  Token = strtok(NULL, ",");
		  memcpy(&GPGGA_Data.lat, Token, strlen(Token));
		  Token = strtok(NULL, ",");
		  memcpy(&GPGGA_Data.lat_dir, Token, strlen(Token));
		  Token = strtok(NULL, ",");
		  memcpy(&GPGGA_Data.lon, Token, strlen(Token));
		  Token = strtok(NULL, ",");
		  memcpy(&GPGGA_Data.lon_dir, Token, strlen(Token));

		  APP_LOG(TS_OFF, VLEVEL_M, "\tUTC: %s\n\r", GPGGA_Data.utc);
		  APP_LOG(TS_OFF, VLEVEL_M, "\tLatitude: %s\n\r", GPGGA_Data.lat);
		  APP_LOG(TS_OFF, VLEVEL_M, "\tLatitude direction: %s\n\r", GPGGA_Data.lat_dir);
		  APP_LOG(TS_OFF, VLEVEL_M, "\tLongitude: %s\n\r", GPGGA_Data.lon);
		  APP_LOG(TS_OFF, VLEVEL_M, "\tLongitude direction: %s\n\r", GPGGA_Data.lon_dir);
		  MX_SubGHz_Phy_APRS_Send(&GPGGA_Data, "DO2DKH-1", "Test123");
	  }
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
int32_t MX_SubGHz_Phy_APRS_Send(GPS_GPGGA_t* p_Position, char* p_Challsign, char* p_Message)
{
	uint8_t TotalLength = 0;

	memcpy(&APRS_TransmitBuffer[TotalLength], APRS_Header, sizeof(APRS_Header));
	TotalLength += sizeof(APRS_Header);

	memcpy(&APRS_TransmitBuffer[TotalLength], p_Challsign, strlen(p_Challsign));
	TotalLength += strlen(p_Challsign);

	APRS_TransmitBuffer[TotalLength] = '>';
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], APRS_Destination, strlen(APRS_Destination));
	TotalLength += strlen(APRS_Destination);

	APRS_TransmitBuffer[TotalLength] = ':';
	TotalLength += 1;

	APRS_TransmitBuffer[TotalLength] = '!';
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], p_Position->lat, 7);
	TotalLength += 7;

	memcpy(&APRS_TransmitBuffer[TotalLength], p_Position->lat_dir, 1);
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], p_Position->lon, 8);
	TotalLength += 8;

	memcpy(&APRS_TransmitBuffer[TotalLength], p_Position->lon_dir, 1);
	TotalLength += 1;

	APRS_TransmitBuffer[TotalLength] = '&';
	TotalLength += 1;

	memcpy(&APRS_TransmitBuffer[TotalLength], p_Message, strlen(p_Message));
	TotalLength += strlen(p_Message);

	return SubghzApp_Transmit(APRS_TransmitBuffer, TotalLength);
}
/* USER CODE END PrFD */
