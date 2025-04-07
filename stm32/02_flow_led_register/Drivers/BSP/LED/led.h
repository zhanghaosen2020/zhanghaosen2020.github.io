#ifndef __LED_H
#define __LED_H
// #include "stm32f4xx.h"
// #include "stm32f407xx.h"
// #include "./SYSTEM/sys/sys.h"
#include "stm32f4xx.h"


#define LED0_GPIO_PIN       1<<9
#define LED1_GPIO_PIN       1<<10
//初始化
void LED_Init(void);

//控制某个LED的开关(传1给高电平->灭;传0给第电平亮)
void LED0(uint8_t led);

void LED1(uint8_t led);

//翻转LED状态
void LED0_Toggle(void);
void LED1_Toggle(void);

#endif
