#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"


void KEY_Init(void)
{
    //����ʱ��
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;//����gpioe�˿�ʱ��
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;// // 3. ʹ��SYSCFGʱ�ӣ����������ⲿ�жϣ�

    //����GPIO����ģʽ
    //��GPIOE_Pin2��������--->0(����ģʽ)
    // ������ģʽ(��ͨ����/ģ������)��, OTYPE��OSPEED������Ч!!
    GPIOE->MODER &= ~(GPIO_MODER_MODER2_Msk);//���PIN2��ģʽ����,pin2����Ϊ00,����ģʽ(Ĭ��)
    GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPDR2);//���ԭ��������(��λ)
    GPIOE->PUPDR |= GPIO_PUPDR_PUPDR2_1;//����

    //����PE2���ӵ�EXTI2    //  �������Ÿ���ѡ��
    SYSCFG->EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI2_Msk);
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PE;

    //����EXTI
    EXTI->FTSR |= EXTI_FTSR_TR2;//ʹ�������Ӵ���
    EXTI->IMR |= EXTI_IMR_MR2;//����EXTI2�����ж�

    //����NVIC
    NVIC_SetPriorityGrouping(3);//ȫ������Ϊ��ռ���ȼ�
    NVIC_SetPriority(EXTI2_IRQn ,3);
    NVIC_EnableIRQ(EXTI2_IRQn);
}

//�жϷ������//��f407.s�����
void EXTI2_IRQHandler(void)
{
    // ������жϹ����־λ
    EXTI->PR |= EXTI_PR_PR2;

    //��С�Ƶķ�ת�����
    // ����
    delay_ms(20);
    //�ж������Ȼ���ֵ͵�ƽ�ͷ�תLED��
    if((GPIOE->IDR & GPIO_IDR_ID2)!=0)
    {
        LED0_Toggle();
    }
}

