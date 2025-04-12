#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"


void KEY_Init(void)
{
//    //����ʱ��
//    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;//����gpioe�˿�ʱ��
//    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;// // 3. ʹ��SYSCFGʱ�ӣ����������ⲿ�жϣ�

//    //����GPIO����ģʽ
//    //��GPIOE_Pin2��������--->0(����ģʽ)
//    // ������ģʽ(��ͨ����/ģ������)��, OTYPE��OSPEED������Ч!!
//    GPIOE->MODER &= ~(GPIO_MODER_MODER2_Msk);//���PIN2��ģʽ����,pin2����Ϊ00,����ģʽ(Ĭ��)
//    GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPDR2);//���ԭ��������(��λ)
//    GPIOE->PUPDR |= GPIO_PUPDR_PUPDR2_1;//����

//    //����PE2���ӵ�EXTI2    //  �������Ÿ���ѡ��
//    SYSCFG->EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI2_Msk);
//    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PE;

//    //����EXTI
//    EXTI->FTSR |= EXTI_FTSR_TR2;//ʹ�������Ӵ���
//    EXTI->IMR |= EXTI_IMR_MR2;//����EXTI2�����ж�

//    //����NVIC
//    NVIC_SetPriorityGrouping(3);//ȫ������Ϊ��ռ���ȼ�
//    NVIC_SetPriority(EXTI2_IRQn ,3);
//    NVIC_EnableIRQ(EXTI2_IRQn);

    // 1. ʹ��GPIOEʱ��
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;

    // 2. ����PE2Ϊ��������ģʽ
    GPIOE->MODER &= ~(3U << (2 * 2));       // ���ģʽλ������ģʽ��
    GPIOE->PUPDR = (GPIOE->PUPDR & ~(3U << (2 * 2))) | (1U << (2 * 2)); // ����

    // 3. ʹ��SYSCFGʱ�ӣ����������ⲿ�жϣ�
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // 4. ����PE2���ӵ�EXTI2
    SYSCFG->EXTICR[0] &= ~(0xFU << 8);      // ���EXTI2��ԭ������
    SYSCFG->EXTICR[0] |= (0x4U << 8);       // EXTI2ѡ��PE2��0x4��ʾGPIOE��

    // 5. ����EXTI2Ϊ�½��ش���
    EXTI->FTSR |= EXTI_FTSR_TR2;            // ʹ���½��ش���
    EXTI->RTSR &= ~EXTI_RTSR_TR2;           // ���������ش���

    // 6. ʹ��EXTI2�ж�����
    EXTI->IMR |= EXTI_IMR_MR2;              // ����EXTI2�����ж�


    NVIC_SetPriorityGrouping(3);//ȫ������Ϊ��ռ���ȼ�
    NVIC_SetPriority(EXTI2_IRQn ,3);
    // 7. ��NVIC��ʹ��EXTI2�ж�
    NVIC_EnableIRQ(EXTI2_IRQn);             // ʹ��CMSIS�����򻯲���
    // �Ĵ�����ʽ��NVIC->ISER[EXTI2_IRQn / 32] |= (1U << (EXTI2_IRQn % 32));
    

}

//�жϷ������//��f407.s�����
void EXTI2_IRQHandler(void)
{
    // ������жϹ����־λ
    EXTI->PR |= EXTI_PR_PR2;

    //��С�Ƶķ�ת�����
    // ����
    delay_ms(10);
    
    //�ж������Ȼ���ֵ͵�ƽ�ͷ�תLED��
    if((GPIOE->IDR & GPIO_IDR_ID2)!=1)
    {
        LED0_Toggle();
    }
}

