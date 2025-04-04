/**
 ****************************************************************************************************
 * @file        led.h
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2021-12-30
 * @brief       LED ��������
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32F407������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20211230
 * ��һ�η���
 *
 ****************************************************************************************************
 */

#ifndef __LED_H
#define __LED_H

#include "./SYSTEM/sys/sys.h"


/******************************************************************************************/
/* ���� ���� */

#define LED0_GPIO_PORT                  GPIOF
#define LED0_GPIO_PIN                   SYS_GPIO_PIN9
#define LED0_GPIO_CLK_ENABLE()          do{ RCC->AHB1ENR |= 1 << 5; }while(0)   /* PF��ʱ��ʹ�� */

#define LED1_GPIO_PORT                  GPIOF
#define LED1_GPIO_PIN                   SYS_GPIO_PIN10
#define LED1_GPIO_CLK_ENABLE()          do{ RCC->AHB1ENR |= 1 << 5; }while(0)   /* PF��ʱ��ʹ�� */

/******************************************************************************************/


/* LED�˿ڶ��� */
#define LED0(x)         sys_gpio_pin_set(LED0_GPIO_PORT, LED0_GPIO_PIN, x)      /* LED0 = RED */
#define LED1(x)         sys_gpio_pin_set(LED1_GPIO_PORT, LED1_GPIO_PIN, x)      /* LED1 = GREEN */

/* LEDȡ������ */
#define LED0_TOGGLE()   do{ LED0_GPIO_PORT->ODR^=LED0_GPIO_PIN; }while(0)       /* LED0 = !LED0 */
#define LED1_TOGGLE()   do{ LED1_GPIO_PORT->ODR^=LED1_GPIO_PIN; }while(0)       /* LED1 = !LED1 */



/* �ⲿ�ӿں���*/
void led_init(void);        /* ��ʼ�� */



#endif






















