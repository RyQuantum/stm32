/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
#include <usbd_custom_hid_if.h>
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC6 PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    uint8_t hid_test[64], i;
    if (GPIO_Pin == GPIO_PIN_0)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 2;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_1)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 63 - i;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_2)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 1;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_3)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = i;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_4)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 3;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_5)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 4;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_6)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 6;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
    if (GPIO_Pin == GPIO_PIN_7)
    {
        for(i = 0; i < 64; i++)
        {
            hid_test[i] = 5;
        }
        USBD_CUSTOM_HID_SendReport_FS(hid_test, 64);
    }
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
