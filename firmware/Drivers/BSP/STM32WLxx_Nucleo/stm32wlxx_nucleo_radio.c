/**
  ******************************************************************************
  * @file    stm32wlxx_nucleo_radio.c
  * @author  Daniel Kampert
  * @brief   This file provides set of firmware functions to manage:
  *          - RF circuitry available on RAK3172
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 Daniel Kampert
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "stm32wlxx_nucleo_radio.h"
#include "radio_driver.h"
  
/**
  * @brief  Init Radio Switch.
  * @retval BSP status
  */
int32_t BSP_RADIO_Init(void)
{
  GPIO_InitTypeDef GPIO_Init = {0};

  RF_SW_CTRL1_GPIO_CLK_ENABLE();
  RF_SW_CTRL2_GPIO_CLK_ENABLE();

  GPIO_Init.Pin   = RF_SW_CTRL1_PIN;
  GPIO_Init.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_Init.Pull  = GPIO_NOPULL;
  GPIO_Init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  
  HAL_GPIO_Init(RF_SW_CTRL1_GPIO_PORT, &GPIO_Init);
  
  GPIO_Init.Pin = RF_SW_CTRL2_PIN;
  HAL_GPIO_Init(RF_SW_CTRL2_GPIO_PORT, &GPIO_Init);
  
  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);

  return BSP_ERROR_NONE;
}

/**
  * @brief  DeInit Radio Switch.
  * @retval BSP status
  */
int32_t BSP_RADIO_DeInit(void)
{
  HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);

  HAL_GPIO_DeInit(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN);
  HAL_GPIO_DeInit(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN);

  return BSP_ERROR_NONE;
}

/**
  * @brief  Configure Radio Switch.
  * @param  Config: Specifies the Radio RF switch path to be set. 
  *         This parameter can be one of following parameters:
  *           @arg RADIO_SWITCH_OFF
  *           @arg RADIO_SWITCH_RX
  *           @arg RADIO_SWITCH_RFO_LP
  *           @arg RADIO_SWITCH_RFO_HP
  * @retval BSP status
  */
int32_t BSP_RADIO_ConfigRFSwitch(BSP_RADIO_Switch_TypeDef Config)
{
  switch (Config)
  {
    case RADIO_SWITCH_OFF:
    {
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET);
      break;      
    }
    case RADIO_SWITCH_RX:
    {
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET); 
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_RESET); 
      break;
    }
    case RADIO_SWITCH_RFO_LP:
    {
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_SET); 
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET); 
      break;
    }
    case RADIO_SWITCH_RFO_HP:
    {
      HAL_GPIO_WritePin(RF_SW_CTRL1_GPIO_PORT, RF_SW_CTRL1_PIN, GPIO_PIN_RESET); 
      HAL_GPIO_WritePin(RF_SW_CTRL2_GPIO_PORT, RF_SW_CTRL2_PIN, GPIO_PIN_SET); 
      break;
    }
    default:
      break;    
  }  

  return BSP_ERROR_NONE;
}

/**
  * @brief  Return Board Configuration.
  * @retval 
  *  RADIO_CONF_RFO_LP_HP
  *  RADIO_CONF_RFO_LP
  *  RADIO_CONF_RFO_HP
  */
int32_t BSP_RADIO_GetTxConfig(void)
{
  return RADIO_CONF_RFO_LP;
}

/**
  * @brief  Get If TCXO is to be present on board.
  * @retval
  *  RADIO_CONF_TCXO_NOT_SUPPORTED
  *  RADIO_CONF_TCXO_SUPPORTED
  */
int32_t BSP_RADIO_IsTCXO(void)
{
  return RADIO_CONF_TCXO_NOT_SUPPORTED;
}

/**
  * @brief  Get If DCDC is to be present on board.
  * @retval
  *  RADIO_CONF_DCDC_NOT_SUPPORTED
  *  RADIO_CONF_DCDC_SUPPORTED  
  */
int32_t BSP_RADIO_IsDCDC(void)
{
  return RADIO_CONF_DCDC_SUPPORTED;
}

/**
  * @brief  Return RF Output Max Power Configuration.
  * @retval
  *    RADIO_CONF_RFO_LP_MAX_15_dBm for LP mode
  *    RADIO_CONF_RFO_HP_MAX_22_dBm for HP mode
  */
int32_t BSP_RADIO_GetRFOMaxPowerConfig(BSP_RADIO_RFOMaxPowerConfig_TypeDef Config)
{
  if(Config == RADIO_RFO_LP_MAXPOWER)
  {
    return RADIO_CONF_RFO_LP_MAX_15_dBm;
  }
  else
  {
    return RADIO_CONF_RFO_HP_MAX_22_dBm;
  }
}
