#ifndef __USART_H
#define __USART_H

#include "stm32f4xx.h"
//#include "./BSP/LED/led.h"
//#include "./SYSTEM/delay/delay.h"


//��ʼ������
void USART1_Init(void);

//����һ���ַ�
void USART1_SendChar(uint8_t ch);

//����һ���ַ�
uint8_t USART1_ReceiveChar(void);

#endif
