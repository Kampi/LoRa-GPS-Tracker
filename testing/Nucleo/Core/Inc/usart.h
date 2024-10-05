/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef hlpuart1;

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
typedef enum
{
	NMEA_PMTK_TEST = 0,
	NMEA_PMTK_ACK = 1,
	NMEA_PMTK_SYS_MSG = 10,
	NMEA_PMTK_CMD_HOT_START = 101,
	NMEA_PMTK_CMD_WARM_START = 102,
	NMEA_PMTK_CMD_COLD_START = 103,
	NMEA_PMTK_CMD_FULL_COLD_START = 104,
	NMEA_PMTK_API_SET_DGPS_MODE = 301,
	NMEA_PMTK_API_SET_SBAS_ENABLED = 313,
	NMEA_PMTK_API_SET_NMEA_OUTPUT = 314,
	NMEA_PMTK_API_SET_PWR_SAV_MODE = 320,
	NMEA_PMTK_API_Q_DGPS_MODE = 401,
	NMEA_PMTK_API_Q_SBAS_ENABLED = 413,
	NMEA_PMTK_API_Q_NMEA_OUTPUT = 414,
	NMEA_PMTK_API_Q_PWR_SAV_MODE = 420,
	NMEA_PMTK_DT_DGPS_MODE = 501,
	NMEA_PMTK_DT_SBAS_ENABLED = 513,
	NMEA_PMTK_DT_NMEA_OUTPUT = 514,
	NMEA_PMTK_DT_PWR_SAV_MODE = 520,
	NMEA_PMTK_Q_VERSION = 604,
	NMEA_PMTK_DT_VERSION = 704,
}NMEA_PMTK_Packet_t;

typedef struct {
	char utc[11];
	char lat[10];
	char lat_dir;
	char lon[11];
	char lon_dir;
	uint8_t quality;
	uint8_t satellites;
	char hdop[8];
	char altitude[8];
	char unit_altitude;
	char geoid[8];
	char unit_geoid;
} NMEA_GPS_GPGGA_t;

typedef struct {
	NMEA_GPS_GPGGA_t GPGGA;
} NMEA_GPS_t;
/* USER CODE END Private defines */

void MX_LPUART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */
int32_t MX_USART1_GPS_Init(void);

void MX_USART1_GPS_Sleep(void);
void MX_USART1_GPS_WakeUp(void);

int32_t MX_USART1_GPS_SendCommand(const char* command, uint16_t length);

int32_t MX_USART1_GPS_Get(NMEA_GPS_t *gps, uint32_t timeout);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

