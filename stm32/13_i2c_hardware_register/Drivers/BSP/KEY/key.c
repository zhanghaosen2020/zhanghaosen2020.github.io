#include"./BSP/KEY/key.h"

 void KEY_Init(void)
 {
     //1.����ʱ��
     RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;//GPIOEʱ��
     RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;//SYSCFGʱ��

     //2.��KEY0��GPIO����Ϊ��������ģʽ
     GPIOE->MODER &= ~(GPIO_MODER_MODE4);//00�����루��λ״̬��
     GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPD4);//���ԭ��ģʽ
     GPIOE->PUPDR |= GPIO_PUPDR_PUPD4_0;//����Ϊ����(��ΪĬ�ϰ��������µ�ʱ��Ϊ�ߵ�ƽ)

     //3.��PE4ӳ�䵽EXTI4
     SYSCFG->EXTICR[1] |=SYSCFG_EXTICR2_EXTI4_PE;

     //4.EXTI���������,�����½��ز������ж����μĴ���
     EXTI->FTSR |=EXTI_FTSR_TR4;
     EXTI->IMR |= EXTI_IMR_MR4;

     //5.NVIC���������,�������ȼ�,�����ж�
     NVIC_SetPriorityGrouping(3);
     NVIC_SetPriority(EXTI4_IRQn,3);
     NVIC_EnableIRQ( EXTI4_IRQn );
 }


 void EXTI4_IRQHandler(void)
 {
     EXTI->PR |= EXTI_PR_PR4;//����жϱ�־λ
     delay_ms(10);
     if(!(GPIOE->IDR & GPIO_IDR_IDR_4))
     {
         LED0_Toggle();
     }
 }


//void KEY_Init(void) {
//    // 1. ����ʱ��
//    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;    // GPIOEʱ��
//    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;   // SYSCFGʱ��

//    // 2. ����PE4Ϊ��������
//    GPIOE->MODER &= ~GPIO_MODER_MODER4_Msk; // ����ģʽ
//    GPIOE->PUPDR &= ~GPIO_PUPDR_PUPD4_Msk;  // ���ԭ������
//    GPIOE->PUPDR |= (0x1 << GPIO_PUPDR_PUPD4_Pos); // ����

//    // 3. ӳ��PE4��EXTI4
//    SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI4_Msk;
//    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PE;

//    // 4. ����EXTI4
//    EXTI->FTSR |= EXTI_FTSR_TR4;            // �½��ش���
//    EXTI->IMR |= EXTI_IMR_MR4;              // ʹ���ж�

//    // 5. ����NVIC
//    NVIC_SetPriority(EXTI4_IRQn, 3);
//    NVIC_EnableIRQ(EXTI4_IRQn);
//}

//void EXTI4_IRQHandler(void) {
//     // ������жϹ����־λ
//     EXTI->PR |= EXTI_PR_PR4;

//     //��С�Ƶķ�ת�����
//     // ����
//     delay_ms(10);
//     
//     //�ж������Ȼ���ֵ͵�ƽ�ͷ�תLED��
//     if((GPIOE->IDR & GPIO_IDR_ID4)!=1)
//     {
//         LED0_Toggle();
//     }
//}

