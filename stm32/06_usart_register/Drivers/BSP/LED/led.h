#ifndef __LED_H
#define __LED_H
// #include "stm32f4xx.h"
// #include "stm32f407xx.h"
// #include "./SYSTEM/sys/sys.h"
#include "stm32f4xx.h"


#define LED0_GPIO_PIN       1<<9
#define LED1_GPIO_PIN       1<<10
//��ʼ��
void LED_Init(void);

//����ĳ��LED�Ŀ���(��1���ߵ�ƽ->��;��0���ڵ�ƽ��)
void LED0(uint8_t led);

void LED1(uint8_t led);

//��תLED״̬
void LED0_Toggle(void);
void LED1_Toggle(void);

#endif
