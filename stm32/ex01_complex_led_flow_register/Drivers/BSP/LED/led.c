#include "./BSP/LED/led.h"
#include "stm32f407xx.h"



//��ʼ��
void LED_Init(void)
{

    RCC->AHB1ENR = RCC_AHB1ENR_GPIOFEN;//����ʱ��
    //�����Ƕ��ϱߵ�����,���ٴ�������
       //��GPIOF_Pin9/10��������--->01
       GPIOF->MODER &= ~(GPIO_MODER_MODER9_Msk | GPIO_MODER_MODER10_Msk);  // ���Pin 9/10��ģʽλ
       GPIOF->MODER |= (GPIO_MODER_MODER9_0 | GPIO_MODER_MODER10_0);       // ����Pin 9/10Ϊͨ�����ģʽ
   

   
       GPIOF->OTYPER &= ~(GPIO_OTYPER_OT9_Msk|GPIO_OTYPER_OT10_Msk);//��9/10����Ϊ�������(0)

       GPIOF->OSPEEDR &=~(GPIO_OSPEEDR_OSPEED9_Msk|GPIO_OSPEEDR_OSPEED10_Msk);

       GPIOF->OSPEEDR |= (GPIO_OSPEEDR_OSPEED9_1|GPIO_OSPEEDR_OSPEED10_1);
   
       //�õ��ݴ���Ϩ���״̬(�ߵ�ƽ)
       GPIOF->ODR |= (GPIO_ODR_OD9_Msk|GPIO_ODR_OD10_Msk) ;
}

//����ĳ��LED�Ŀ���
void LED0(uint8_t led)
{
    if(led == 0)
    {
        GPIOF->BSRR |= GPIO_BSRR_BR9_Msk;//����
    }
    else if (led == 1)
    {
        GPIOF->BSRR |= GPIO_BSRR_BS9_Msk;//����
    }
    
}

void LED1(uint8_t led)
{
    if(led == 0)
    {
        GPIOF->BSRR |= GPIO_BSRR_BR10_Msk;//����
    }
    else if (led==1)
    {
        GPIOF->BSRR |= GPIO_BSRR_BS10_Msk;//����
    }
}

//��תLED״̬
void LED0_Toggle(void)
{
    GPIOF->ODR ^= LED0_GPIO_PIN;
}

void LED1_Toggle(void)
{
    GPIOF->ODR ^= LED1_GPIO_PIN;
}

