/*
 * ENCODER.h
 *
 *  Created on: Apr 1, 2025
 *      Author: Pavan
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

void Encoder_Init(void);
void HAL_TIM_IC_CaptureCallback (TIM_HandleTypeDef *htim);

#endif /* INC_ENCODER_H_ */
