#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"



//int main(void)
//{
//    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
//    delay_init(168);                        /* 延时初始化 */
//    led_init();                             /* 初始化LED */

//    while(1)
//    {
//        LED0(0);                            /* LED0 亮 */
//        LED1(1);                            /* LED1 灭 */
//        delay_ms(500);
//        LED0(1);                            /* LED0 灭 */
//        LED1(0);                            /* LED1 亮 */
//        delay_ms(500);
//    }
//}

//#include<stdint.h>

////1,时钟配置(STM32配置工程的第一步,为什么要先做这一步,其实可以当做是一个资源分配的问题,你通过时钟树对需要用到的外设进行配置,没有用到的就不开,节能,低功耗)
////2,GPIO配置,上边是打开了对应的GPIOF模块时钟,下边自然地就需要配置GPIO模块

//int main(void)
//{
////    //1,时钟配置(使能GPIOF时钟)
////    *(uint32_t*)(0x40023800 + 0x30)= 32 ;
//    RCC->AHB1ENR = 32;
////    //2,GPIO配置(配置GPIO模式为输出)
////    *(uint32_t*)(0x40221400+0x00)=0x00110000;
//    GPIOF->MODER = 
////    //3,设置输出类型(推完或者开漏)
////     *(uint32_t*)(0x40221400+0x04) =0xf9ff;
////    //4,配置输出速度
////     *(uint32_t*)(0x40221400+0x08)=0x003c0000;
////    //5,关闭上下拉电阻
//    
//    
//}



int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    //上边的时钟配置和延时函数暂时先用正点原子提供的
    
    //下面来尝试点亮  LED0 -- PF9 所控制
    //1.时钟配置,RCC寄存器对应的GPIOF时钟使能
    RCC->AHB1ENR |= 1<<5;
    //2.GPIO输出模式配置
//    GPIOF->MODER |=
       // 2. 配置 Pin9 为输出模式
    GPIOF->MODER &= ~(3 << 18);     // 清除模式
    GPIOF->MODER |= 1 << 18;        // 通用输出模式（01）

    // 3. 配置输出速度为高速
    GPIOF->OSPEEDR &= ~(3 << 18);
    GPIOF->OSPEEDR |= 2 << 18;      // 高速（10）

    // 4. 启用上拉电阻
    GPIOF->PUPDR &= ~(3 << 18);
    GPIOF->PUPDR |= 1 << 18;        // 上拉（01）

    // 5. 配置为推挽输出
    GPIOF->OTYPER &= ~(1 << 9);     // 清除类型（默认为推挽）

    // 6. 点亮 LED（假设低电平点亮）
    //GPIOF->BSRR = 1 << (9 + 16);    // 设置 Pin9 低电平//复位操作
    
//    GPIOF->ODR |= 1<<9;
//    
//    GPIOF->ODR &= ~(1<<9);
    
    while(1)
    {
//        // 6. 点亮 LED（假设低电平点亮）
//        GPIOF->BSRR = 1 << (9 + 16);     // BSRR高16位：Pin9置低
//        
//        delay_ms(500);
//        // 7. 熄灭 LED
//        GPIOF->BSRR = 1 << 9;            // BSRR低16位：Pin9置高
//   delay_ms(500);
        
        
    GPIOF->ODR |= 1<<9;
    delay_ms(500);
    GPIOF->ODR &= ~(1<<9);
    delay_ms(500);//少了这个延时,让灯泡闪亮的效果就出不来

    }
}
