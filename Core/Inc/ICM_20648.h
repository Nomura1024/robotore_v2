/*
 * ICM_20648.h
 *
 *  Created on: Jun 21, 2021
 *      Author: Owner
 */

#ifndef INC_ICM_20648_H_
#define INC_ICM_20648_H_

#include "main.h"
extern SPI_HandleTypeDef hspi3;
// IMUから取得したデータ
extern volatile int16_t 	xa, ya, za; // 加速度(16bitデータ)
extern volatile int16_t 	xg, yg, zg;	//  角加速度(16bitデータ)

#define CS_RESET HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET)
#define CS_SET   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET)

uint8_t read_byte( uint8_t );
void write_byte( uint8_t, uint8_t);
uint8_t IMU_init(void);
void read_gyro_data(void);
void read_accel_data(void);

/*
Gyro		レンジ(dps)	スケールファクター(LSB/dps)　dps = 生/スケールファクター
					±250				131
					±500				65.5
					±1000				32.8
					±2000				16.4
Accel		レンジ(g)		スケールファクター(LSB/g)
					±2					16384
					±4					8192
					±8					4096
					±16					2048
*/



#endif /* INC_ICM_20648_H_ */
