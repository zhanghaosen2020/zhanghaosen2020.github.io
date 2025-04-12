#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"


void KEY_Init(void)
{
//    //配置时钟
//    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;//开启gpioe端口时钟
//    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;// // 3. 使能SYSCFG时钟（用于配置外部中断）

//    //配置GPIO工作模式
//    //对GPIOE_Pin2进行配置--->0(输入模式)
//    // 在输入模式(普通输入/模拟输入)下, OTYPE和OSPEED参数无效!!
//    GPIOE->MODER &= ~(GPIO_MODER_MODER2_Msk);//清除PIN2的模式设置,pin2设置为00,输入模式(默认)
//    GPIOE->PUPDR &= ~(GPIO_PUPDR_PUPDR2);//清除原有上下拉(置位)
//    GPIOE->PUPDR |= GPIO_PUPDR_PUPDR2_1;//上拉

//    //配置PE2连接到EXTI2    //  配置引脚复用选择
//    SYSCFG->EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI2_Msk);
//    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PE;

//    //配置EXTI
//    EXTI->FTSR |= EXTI_FTSR_TR2;//使能上升延触发
//    EXTI->IMR |= EXTI_IMR_MR2;//允许EXTI2产生中断

//    //配置NVIC
//    NVIC_SetPriorityGrouping(3);//全部设置为抢占优先级
//    NVIC_SetPriority(EXTI2_IRQn ,3);
//    NVIC_EnableIRQ(EXTI2_IRQn);

    // 1. 使能GPIOE时钟
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;

    // 2. 配置PE2为上拉输入模式
    GPIOE->MODER &= ~(3U << (2 * 2));       // 清除模式位（输入模式）
    GPIOE->PUPDR = (GPIOE->PUPDR & ~(3U << (2 * 2))) | (1U << (2 * 2)); // 上拉

    // 3. 使能SYSCFG时钟（用于配置外部中断）
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // 4. 配置PE2连接到EXTI2
    SYSCFG->EXTICR[0] &= ~(0xFU << 8);      // 清除EXTI2的原有配置
    SYSCFG->EXTICR[0] |= (0x4U << 8);       // EXTI2选择PE2（0x4表示GPIOE）

    // 5. 配置EXTI2为下降沿触发
    EXTI->FTSR |= EXTI_FTSR_TR2;            // 使能下降沿触发
    EXTI->RTSR &= ~EXTI_RTSR_TR2;           // 禁用上升沿触发

    // 6. 使能EXTI2中断请求
    EXTI->IMR |= EXTI_IMR_MR2;              // 允许EXTI2产生中断


    NVIC_SetPriorityGrouping(3);//全部设置为抢占优先级
    NVIC_SetPriority(EXTI2_IRQn ,3);
    // 7. 在NVIC中使能EXTI2中断
    NVIC_EnableIRQ(EXTI2_IRQn);             // 使用CMSIS函数简化操作
    // 寄存器方式：NVIC->ISER[EXTI2_IRQn / 32] |= (1U << (EXTI2_IRQn % 32));
    

}

//中断服务程序//在f407.s里边找
void EXTI2_IRQHandler(void)
{
    // 先清除中断挂起标志位
    EXTI->PR |= EXTI_PR_PR2;

    //做小灯的翻转这件事
    // 防抖
    delay_ms(10);
    
    //判断如果依然保持低电平就反转LED灯
    if((GPIOE->IDR & GPIO_IDR_ID2)!=1)
    {
        LED0_Toggle();
    }
}

