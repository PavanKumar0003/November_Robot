/*
 * PWM_CHANNELS.c
 *
 *  Created on: 23-MARCH-2025
 *  Author: Pavan Kumar
 *
 */
#include "main.h"

extern TIM_HandleTypeDef htim5;


void PWM_CHANNELS_Init(void)
{
	/*Start PWM Generation*/
	HAL_TIM_PWM_Start (&htim5, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start (&htim5, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start (&htim5, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start (&htim5, TIM_CHANNEL_4);
}

void PWM_CHANNEL_1_SET_SPEED(int Speed, int Direction)
{
	if(Direction == 1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
	}
	else if(Direction == 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
	}
	/*Limit the PWM Prescaler to 255*/
	(Speed>255) ? __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, 255) : __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_1, Speed);		//Update Prescaler value
}

void PWM_CHANNEL_2_SET_SPEED(int Speed, int Direction)
{
	if(Direction == 1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
	}
	else if(Direction == 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
	}
	/*Limit the PWM Prescaler to 255*/
	(Speed>255) ? __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, 255) : __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_2, Speed);		//Update Prescaler value
}

void PWM_CHANNEL_3_SET_SPEED(int Speed, int Direction)
{
	if(Direction == 1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
	}
	else if(Direction == 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
	}
	/*Limit the PWM Prescaler to 255*/
	(Speed>255) ? __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 255) : __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, Speed);		//Update Prescaler value
}

void PWM_CHANNEL_4_SET_SPEED(int Speed, int Direction)
{
	if(Direction == 1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
	}
	else if(Direction == 0)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
	}
	/*Limit the PWM Prescaler to 255*/
	(Speed>255) ? __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 255) : __HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, Speed);		//Update Prescaler value
}
