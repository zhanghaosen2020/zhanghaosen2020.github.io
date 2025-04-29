#ifndef __I2C_H
#define __I2C_H

#include "stm32f407xx.h"
#include "./SYSTEM/delay/delay.h"//因为后续,时钟线和数据线都需要拉高持续一段时间故引入

//宏定义(为了可读性)
#define ACK 0
#define NACK 1

#define SCL_HIGHT (GPIOB->ODR |= GPIO_ODR_ODR_8)
#define SCL_LOW (GPIOB->ODR &= ~GPIO_ODR_ODR_8)
#define SDA_HIGHT (GPIOB->ODR |= GPIO_ODR_ODR_9)
#define SDA_LOW (GPIOB->ODR &= ~GPIO_ODR_ODR_9)//32控制时钟线/写入线

//读取操作
#define READ_SDA (GPIOB->IDR & GPIO_IDR_IDR_9)

//定义操作的延时
#define I2C_DELAY delay_us(10);

//初始化
void I2C_Init(void);

//发出起始信号
void I2C_Start(void);

//发出停止信号
void I2C_Stop(void);

//主机发出应答信号
void I2C_Ack(void);

//主机发出非应答信号
void I2C_Nack(void);

//主机等待从设备发来应答信号
uint8_t I2C_Wait4Ack(void);

//主机发送一个字节数据(写入,往eeprom写入)
void I2C_SendByte(uint8_t byte);

//主机从EEPROM接收一个字节的数据(读取)
uint8_t I2C_Read_Byte(void);
#endif
