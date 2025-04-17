#ifndef __USART_H
#define __USART_H

#include "stm32f4xx.h"
//#include "./BSP/LED/led.h"
//#include "./SYSTEM/delay/delay.h"


//初始化函数
void USART1_Init(void);

//发送一个字符
void USART1_SendChar(uint8_t ch);

//接受一个字符
uint8_t USART1_ReceiveChar(void);

#endif
