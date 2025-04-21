#include"./BSP/KEY/key.h"

 void KEY_Init(void)
 {
     //1.开启时钟
     RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;//GPIOE时钟
     RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;//SYSCFG时钟

     //2.将KEY0的GPIO设置为上拉输入模式
     GPIOE->MODER &= ~(GPIO_MODER_MODE4);//00：输入（复位状态）
     GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPD4);//清除原有模式
     GPIOE->PUPDR |= GPIO_PUPDR_PUPD4_0;//设置为上拉(因为默认按键不按下的时候为高电平)

     //3.将PE4映射到EXTI4
     SYSCFG->EXTICR[1] |=SYSCFG_EXTICR2_EXTI4_PE;

     //4.EXTI的想干配置,设置下降沿并开启中断屏蔽寄存器
     EXTI->FTSR |=EXTI_FTSR_TR4;
     EXTI->IMR |= EXTI_IMR_MR4;

     //5.NVIC的相关配置,设置优先级,开启中断
     NVIC_SetPriorityGrouping(3);
     NVIC_SetPriority(EXTI4_IRQn,3);
     NVIC_EnableIRQ( EXTI4_IRQn );
 }


 void EXTI4_IRQHandler(void)
 {
     EXTI->PR |= EXTI_PR_PR4;//清除中断标志位
     delay_ms(10);
     if(!(GPIOE->IDR & GPIO_IDR_IDR_4))
     {
         LED0_Toggle();
     }
 }


//void KEY_Init(void) {
//    // 1. 开启时钟
//    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;    // GPIOE时钟
//    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;   // SYSCFG时钟

//    // 2. 配置PE4为上拉输入
//    GPIOE->MODER &= ~GPIO_MODER_MODER4_Msk; // 输入模式
//    GPIOE->PUPDR &= ~GPIO_PUPDR_PUPD4_Msk;  // 清除原有配置
//    GPIOE->PUPDR |= (0x1 << GPIO_PUPDR_PUPD4_Pos); // 上拉

//    // 3. 映射PE4到EXTI4
//    SYSCFG->EXTICR[1] &= ~SYSCFG_EXTICR2_EXTI4_Msk;
//    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PE;

//    // 4. 配置EXTI4
//    EXTI->FTSR |= EXTI_FTSR_TR4;            // 下降沿触发
//    EXTI->IMR |= EXTI_IMR_MR4;              // 使能中断

//    // 5. 配置NVIC
//    NVIC_SetPriority(EXTI4_IRQn, 3);
//    NVIC_EnableIRQ(EXTI4_IRQn);
//}

//void EXTI4_IRQHandler(void) {
//     // 先清除中断挂起标志位
//     EXTI->PR |= EXTI_PR_PR4;

//     //做小灯的翻转这件事
//     // 防抖
//     delay_ms(10);
//     
//     //判断如果依然保持低电平就反转LED灯
//     if((GPIOE->IDR & GPIO_IDR_ID4)!=1)
//     {
//         LED0_Toggle();
//     }
//}

