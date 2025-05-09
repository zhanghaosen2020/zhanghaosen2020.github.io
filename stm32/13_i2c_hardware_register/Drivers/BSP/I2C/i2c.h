#ifndef __I2C_H
#define __I2C_H

#include "stm32f407xx.h"
#include "./SYSTEM/delay/delay.h"//因为后续,时钟线和数据线都需要拉高持续一段时间故引入

#include "./BSP/USART1/usart1.h"
#include <string.h>

//宏定义(为了可读性)
#define OK 0
#define FAIL 1

//初始化
void I2C_Init(void);

//发出起始信号
uint8_t I2C_Start(void);

//设置发出停止信号
void I2C_Stop(void);

//主机设置使能应答信号
void I2C_Ack(void);

//主机设置使能非应答信号
void I2C_Nack(void);

//发送设备地址并等待应答
uint8_t I2C_SendAddr(uint8_t addr);

//主机发送一个字节数据(写入,往eeprom写入),并且等待应答
uint8_t I2C_SendByte(uint8_t byte);

//主机从EEPROM接收一个字节的数据(读取)
uint8_t I2C_Read_Byte(void);
#endif
