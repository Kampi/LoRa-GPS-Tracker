/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
#include "usart.h"

/* USER CODE BEGIN 0 */
#include <string.h>
#include <stdlib.h>

#include "sys_app.h"

/* USER CODE END 0 */

UART_HandleTypeDef hlpuart1;
UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_tx;

/* LPUART1 init function */

void MX_LPUART1_UART_Init(void)
{

  /* USER CODE BEGIN LPUART1_Init 0 */

  /* USER CODE END LPUART1_Init 0 */

  /* USER CODE BEGIN LPUART1_Init 1 */

  /* USER CODE END LPUART1_Init 1 */
  hlpuart1.Instance = LPUART1;
  hlpuart1.Init.BaudRate = 9600;
  hlpuart1.Init.WordLength = UART_WORDLENGTH_8B;
  hlpuart1.Init.StopBits = UART_STOPBITS_1;
  hlpuart1.Init.Parity = UART_PARITY_NONE;
  hlpuart1.Init.Mode = UART_MODE_TX_RX;
  hlpuart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  hlpuart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  hlpuart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  hlpuart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT|UART_ADVFEATURE_DMADISABLEONERROR_INIT;
  hlpuart1.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
  hlpuart1.AdvancedInit.DMADisableonRxError = UART_ADVFEATURE_DMA_DISABLEONRXERROR;
  hlpuart1.FifoMode = UART_FIFOMODE_DISABLE;
  if (HAL_UART_Init(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&hlpuart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&hlpuart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&hlpuart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LPUART1_Init 2 */

  /* USER CODE END LPUART1_Init 2 */

}
/* USART2 init function */

void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_EnableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(uartHandle->Instance==LPUART1)
  {
  /* USER CODE BEGIN LPUART1_MspInit 0 */

  /* USER CODE END LPUART1_MspInit 0 */

  /** Initializes the peripherals clocks
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LPUART1;
    PeriphClkInitStruct.Lpuart1ClockSelection = RCC_LPUART1CLKSOURCE_LSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* LPUART1 clock enable */
    __HAL_RCC_LPUART1_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**LPUART1 GPIO Configuration
    PC1     ------> LPUART1_TX
    PC0     ------> LPUART1_RX
    */
    GPIO_InitStruct.Pin = GPS_TX_Pin|GPS_RX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF8_LPUART1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* LPUART1 interrupt Init */
    HAL_NVIC_SetPriority(LPUART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(LPUART1_IRQn);
  /* USER CODE BEGIN LPUART1_MspInit 1 */

  /* USER CODE END LPUART1_MspInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */

  /** Initializes the peripherals clocks
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART2;
    PeriphClkInitStruct.Usart2ClockSelection = RCC_USART2CLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA3     ------> USART2_RX
    PA2     ------> USART2_TX
    */
    GPIO_InitStruct.Pin = USARTx_RX_Pin|USARTx_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 DMA Init */
    /* USART2_TX Init */
    hdma_usart2_tx.Instance = DMA1_Channel5;
    hdma_usart2_tx.Init.Request = DMA_REQUEST_USART2_TX;
    hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_tx.Init.Mode = DMA_NORMAL;
    hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
    {
      Error_Handler();
    }

    if (HAL_DMA_ConfigChannelAttributes(&hdma_usart2_tx, DMA_CHANNEL_NPRIV) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmatx,hdma_usart2_tx);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==LPUART1)
  {
  /* USER CODE BEGIN LPUART1_MspDeInit 0 */

  /* USER CODE END LPUART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LPUART1_CLK_DISABLE();

    /**LPUART1 GPIO Configuration
    PC1     ------> LPUART1_TX
    PC0     ------> LPUART1_RX
    */
    HAL_GPIO_DeInit(GPIOC, GPS_TX_Pin|GPS_RX_Pin);

    /* LPUART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(LPUART1_IRQn);
  /* USER CODE BEGIN LPUART1_MspDeInit 1 */

  /* USER CODE END LPUART1_MspDeInit 1 */
  }
  else if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA3     ------> USART2_RX
    PA2     ------> USART2_TX
    */
    HAL_GPIO_DeInit(GPIOA, USARTx_RX_Pin|USARTx_TX_Pin);

    /* USART2 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmatx);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
static int32_t MX_USART1_GPS_GetLine(char *buffer, uint8_t *length, uint32_t timeout)
{
	uint8_t Temp;
	uint32_t ReceivedByte = 0;
	uint32_t Timeout_Temp = 0;

	// Wait for the beginning of a new line
	do
	{
		HAL_UART_Receive(&hlpuart1, &Temp, 1, 10);
		Timeout_Temp += 10;

		if (Timeout_Temp >= timeout)
		{
			return HAL_TIMEOUT;
		}
	} while (Temp != '$');

	Timeout_Temp = 0;
	buffer[ReceivedByte++] = Temp;

	// Get the rest of the line
	do
	{
		HAL_UART_Receive(&hlpuart1, &Temp, 1, 10);
		Timeout_Temp += 10;

		buffer[ReceivedByte++] = Temp;

		if (Timeout_Temp >= timeout)
		{
			return HAL_TIMEOUT;
		}
	} while (Temp != '\n');

	// Remove the line end
	buffer[ReceivedByte - 1] = '\0';

  return HAL_OK;
}

int32_t MX_USART1_GPS_Init(void)
{
	// Set the NMEA output fields
	//	- Disable all fields
	//	- Enable the GGA field
	const char* PMTK314 = "$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n";
	if (MX_USART1_GPS_SendCommand(PMTK314, strlen(PMTK314)) != HAL_OK)
	{
		return HAL_ERROR;
	}

	/*
	//
	const char* PMTK223 = "$PMTK223,1,25,180000,60000*38\r\n";
	if (MX_USART1_GPS_SendCommand(PMTK223, strlen(PMTK223)) != HAL_OK)
	{
		return HAL_ERROR;
	}

	// Enter perodic standby mode
	//	Type 2 -> Periodic standby mode
	//	Run time ->  ms
	//	Sleep time ->  ms
	const char* PMTK225 = "$PMTK225,2,3000,12000,18000,72000*15\r\n";
	if (MX_USART1_GPS_SendCommand(PMTK225, strlen(PMTK225)) != HAL_OK)
	{
		return HAL_ERROR;
	}
*/
	return HAL_OK;
}

int32_t MX_USART1_GPS_SendCommand(const char* command, uint16_t length)
{
	static char _UART_NMEA_MTK_Buffer[64];
	uint8_t _UART_NMEA_MTK_Length;

	memset(_UART_NMEA_MTK_Buffer, 0, sizeof(_UART_NMEA_MTK_Buffer));

 	if (HAL_UART_Transmit(&hlpuart1, (const uint8_t*)command, length, 100) != HAL_OK)
	{
		return HAL_ERROR;
	}

  if (MX_USART1_GPS_GetLine(_UART_NMEA_MTK_Buffer, &_UART_NMEA_MTK_Length, 1000) != HAL_OK)
  {
  	return HAL_ERROR;
  }

  // Format: $PMTK001,314,3*36
  if (strstr(_UART_NMEA_MTK_Buffer, "$PMTK") != NULL)
  {
  	static char* Token;
  	char PacketType[4];
  	char Ack[2];

	  // Fetch the packet type
  	Token = strtok(_UART_NMEA_MTK_Buffer, ",");
	  memcpy(PacketType, &Token[5], strlen(Token));
	  PacketType[3] = '\0';

  	strtok(NULL, ",");

	  // Fetch the acknowledge packet
  	Token = strtok(NULL, "*");
	  memcpy(Ack, Token, strlen(Token));

	  if ((atoi(PacketType) != NMEA_PMTK_ACK) || (atoi(Ack) != 3))
	  {
	  	return HAL_ERROR;
	  }
  }

	return HAL_OK;
}

void MX_USART1_GPS_Sleep(void)
{
  // Make sure that no LPUART transfer is on-going
  while (__HAL_UART_GET_FLAG(&hlpuart1, USART_ISR_BUSY) == SET);

  // Make sure that LPUART is ready to receive
  while (__HAL_UART_GET_FLAG(&hlpuart1, USART_ISR_REACK) == RESET);

  __HAL_UART_ENABLE_IT(&hlpuart1, UART_IT_WUF);

  HAL_UARTEx_EnableStopMode(&hlpuart1);
}

void MX_USART1_GPS_WakeUp(void)
{
  HAL_UARTEx_DisableStopMode(&hlpuart1);
}

int32_t MX_USART1_GPS_Get(NMEA_GPS_t *gps, uint32_t timeout)
{
	static char _UART_NMEA_Buffer[80];
	uint8_t Length;
	int32_t Status;

	memset(_UART_NMEA_Buffer, 0, sizeof(_UART_NMEA_Buffer));

	Status = MX_USART1_GPS_GetLine(_UART_NMEA_Buffer, &Length, 1000);
	if (Status != HAL_OK)
	{
		return HAL_ERROR;
	}
  APP_LOG(TS_OFF, VLEVEL_M, "Message: %s\n\r", _UART_NMEA_Buffer);

	memset(gps, 0, sizeof(NMEA_GPS_t));

  // Format: $GPGGA,174857.000,4932.1285,N,01046.6422,E,2,9,0.90,388.3,M,47.9,M,,*5E
  if (strstr(_UART_NMEA_Buffer, "$GPGGA") != NULL)
  {
  	char* Token;

	  // Fetch and discard the header
	  strtok(_UART_NMEA_Buffer, ",");

	  Token = strtok(NULL, ",");
	  memcpy(gps->GPGGA.utc, Token, strlen(Token));
	  Token = strtok(NULL, ",");
	  memcpy(gps->GPGGA.lat, Token, strlen(Token));
	  Token = strtok(NULL, ",");
	  memcpy(&gps->GPGGA.lat_dir, Token, 1);
	  Token = strtok(NULL, ",");
	  memcpy(gps->GPGGA.lon, Token, strlen(Token));
	  Token = strtok(NULL, ",");
	  memcpy(&gps->GPGGA.lon_dir, Token, 1);
	  Token = strtok(NULL, ",");
	  gps->GPGGA.quality = atoi(Token);
	  Token = strtok(NULL, ",");
	  gps->GPGGA.satellites = atoi(Token);
	  Token = strtok(NULL, ",");
	  memcpy(gps->GPGGA.hdop, Token, strlen(Token));
	  Token = strtok(NULL, ",");
	  memcpy(gps->GPGGA.altitude, Token, strlen(Token));
	  Token = strtok(NULL, ",");
	  memcpy(&gps->GPGGA.unit_altitude, Token, 1);
	  Token = strtok(NULL, ",");
	  memcpy(gps->GPGGA.geoid, Token, strlen(Token));
	  Token = strtok(NULL, ",");
	  memcpy(&gps->GPGGA.unit_geoid, Token, 1);

	  return HAL_OK;
  }

  return HAL_ERROR;
}

/* USER CODE END 1 */
