/*
 * ENCODER_SETUP.c
 *
 *  Created on: Apr 1, 2025
 *      Author: Pavan
 */
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

uint32_t Counter_new_1=0, Counter_new_2=0, Counter_new_3=0,Counter_new_4=0;
int16_t Count_1=0, Count_2=0,Count_3=0,Count_4=0;

volatile int16_t position_1=0, position_2=0, position_3=0, position_4=0;
int speed_1=0, speed_2=0, speed_3=0, speed_4=0;
int trig=0;


/*
 * Encoder_Init(); Initializes all 4 TIM channels required for 4 encoders
 */
void Encoder_Init(void)
{
	  HAL_TIM_Encoder_Start_IT(&htim1, TIM_CHANNEL_ALL);
	  HAL_TIM_Encoder_Start_IT(&htim2, TIM_CHANNEL_ALL);
	  HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
	  HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);
}

/*
 * HAL_TIM_IC_CaptureCallback(); is a Interrupt controller.
 * It is called when an interrupt generated in TIM channels
 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim1)
	{
		Counter_new_1= __HAL_TIM_GetCounter(htim);
		Count_1 = (int16_t)Counter_new_1/4;
		position_1 = Count_1;

		//itoa(Counter_1, ENC_DMA_DATA_BUFF,7);
		//sprintf(ENC_DMA_DATA_BUFF,"%-5ld, %-5ld, %-5ld, %-5ld\n",Counter_1,Counter_1,Counter_1,Counter_1);
		//HAL_Delay(1000);
		//ENC_DMA_DATA_BUFF[6] = '\0';
		//ENC_DMA_DATA_BUFF[6] = '\n';
		//snprintf(ENC_DMA_DATA_BUFF, sizeof(ENC_DMA_DATA_BUFF), "%ld\n", Counter_1);
		//if(Counter_1 == 65535)
		//{
			//for(int i=0;ENC_DMA_DATA_BUFF[i]!=0;i++) {ENC_DMA_DATA_BUFF[i]=0;}
			//memset(ENC_DMA_DATA_BUFF, 0, sizeof(ENC_DMA_DATA_BUFF));
			//HAL_Delay(1000);
		//}
		//ROBOT_SENSOR_DATA.ENC_1 = Counter_1;
	}

	else if(htim == &htim2)
	{
		Counter_new_2 = __HAL_TIM_GetCounter(htim);
		//uint8_t ENC_DMA_DATA_BUFF[]= ;
		Count_2 = (int16_t)Counter_new_2/4;
		position_2 = Count_2;
	}
	else if(htim == &htim3)
	{
		Counter_new_3 = __HAL_TIM_GetCounter(htim);
		//uint8_t ENC_DMA_DATA_BUFF[]= ;
		Count_3 = (int16_t)Counter_new_3/4;
		position_3 = Count_3;
	}
	else if(htim == &htim4)
	{
			Counter_new_4 = __HAL_TIM_GetCounter(htim);
			//uint8_t ENC_DMA_DATA_BUFF[]= ;
			Count_4 = (int16_t)Counter_new_4/4;
			position_4 = Count_4;
	}

}
