#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#include "./BSP/LED/led.h"


int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* ����ʱ��,168Mhz */
    delay_init(168);                        /* ��ʱ��ʼ�� */

        // RCC->AHB1ENR = RCC_AHB1ENR_GPIOFEN;//����ʱ��
    
    //��GPIOF_Pin9/10��������--->01
    // GPIOF->MODER &= ~(GPIO_MODER_MODER9_Msk);  // ���Pin 9��ģʽλ
    // GPIOF->MODER |= GPIO_MODER_MODER9_0;       // ����Pin 10Ϊͨ�����ģʽ

    // GPIOF->MODER &= ~(GPIO_MODER_MODER10_Msk);  // ���Pin 10��ģʽλ
    // GPIOF->MODER |= GPIO_MODER_MODER10_0;       // ����Pin 10Ϊͨ�����ģʽ

    // GPIOF->OTYPER &= ~(GPIO_OTYPER_OT9_Msk);
    // GPIOF->OTYPER &= ~(GPIO_OTYPER_OT10_Msk);//��9/10����Ϊ�������(0)

    // GPIOF->OSPEEDR &=~(GPIO_OSPEEDR_OSPEED9_Msk);
    // GPIOF->OSPEEDR &=~(GPIO_OSPEEDR_OSPEED10_Msk);
    // GPIOF->OSPEEDR |= GPIO_OSPEEDR_OSPEED9_1;
    // GPIOF->OSPEEDR |= GPIO_OSPEEDR_OSPEED10_1; 

    // //�õ��ݴ���Ϩ���״̬(�ߵ�ƽ)
    // GPIOF->ODR |= GPIO_ODR_OD9_Msk;
    // GPIOF->ODR |= GPIO_ODR_OD10_Msk;
    LED_Init();//�ϱߵĲ����װ��������������



    while(1)
    {
        // LED0(0);//���Ժ���
        // delay_ms(500);
        // LED0(1);
        // delay_ms(500);
        // LED1(0);
        // delay_ms(500);
        // LED1(1);
        // delay_ms(500);
        // LED0_Toggle();
        // delay_ms(500);
        
        
        LED0_Toggle();
        delay_ms(500);
        LED1_Toggle();
        delay_ms(500);
    }
}

