#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#include "./BSP/LED/led.h"


int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */

        // RCC->AHB1ENR = RCC_AHB1ENR_GPIOFEN;//开启时钟
    
    //对GPIOF_Pin9/10进行配置--->01
    // GPIOF->MODER &= ~(GPIO_MODER_MODER9_Msk);  // 清除Pin 9的模式位
    // GPIOF->MODER |= GPIO_MODER_MODER9_0;       // 设置Pin 10为通用输出模式

    // GPIOF->MODER &= ~(GPIO_MODER_MODER10_Msk);  // 清除Pin 10的模式位
    // GPIOF->MODER |= GPIO_MODER_MODER10_0;       // 设置Pin 10为通用输出模式

    // GPIOF->OTYPER &= ~(GPIO_OTYPER_OT9_Msk);
    // GPIOF->OTYPER &= ~(GPIO_OTYPER_OT10_Msk);//将9/10配置为推挽输出(0)

    // GPIOF->OSPEEDR &=~(GPIO_OSPEEDR_OSPEED9_Msk);
    // GPIOF->OSPEEDR &=~(GPIO_OSPEEDR_OSPEED10_Msk);
    // GPIOF->OSPEEDR |= GPIO_OSPEEDR_OSPEED9_1;
    // GPIOF->OSPEEDR |= GPIO_OSPEEDR_OSPEED10_1; 

    // //让灯泡处于熄灭的状态(高电平)
    // GPIOF->ODR |= GPIO_ODR_OD9_Msk;
    // GPIOF->ODR |= GPIO_ODR_OD10_Msk;
    LED_Init();//上边的步骤封装到这个函数里边了



    while(1)
    {
        // LED0(0);//测试函数
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

