#include "./BSP/LED/led.h"
#include "stm32f407xx.h"



//初始化
void LED_Init(void)
{

    RCC->AHB1ENR = RCC_AHB1ENR_GPIOFEN;//开启时钟
    //下面是对上边的提炼,减少代码冗余
       //对GPIOF_Pin9/10进行配置--->01
       GPIOF->MODER &= ~(GPIO_MODER_MODER9_Msk | GPIO_MODER_MODER10_Msk);  // 清除Pin 9/10的模式位
       GPIOF->MODER |= (GPIO_MODER_MODER9_0 | GPIO_MODER_MODER10_0);       // 设置Pin 9/10为通用输出模式
   

   
       GPIOF->OTYPER &= ~(GPIO_OTYPER_OT9_Msk|GPIO_OTYPER_OT10_Msk);//将9/10配置为推挽输出(0)

       GPIOF->OSPEEDR &=~(GPIO_OSPEEDR_OSPEED9_Msk|GPIO_OSPEEDR_OSPEED10_Msk);

       GPIOF->OSPEEDR |= (GPIO_OSPEEDR_OSPEED9_1|GPIO_OSPEEDR_OSPEED10_1);
   
       //让灯泡处于熄灭的状态(高电平)
       GPIOF->ODR |= (GPIO_ODR_OD9_Msk|GPIO_ODR_OD10_Msk) ;
}

//控制某个LED的开关
void LED0(uint8_t led)
{
    if(led == 0)
    {
        GPIOF->BSRR |= GPIO_BSRR_BR9_Msk;//亮灯
    }
    else if (led == 1)
    {
        GPIOF->BSRR |= GPIO_BSRR_BS9_Msk;//灯灭
    }
    
}

void LED1(uint8_t led)
{
    if(led == 0)
    {
        GPIOF->BSRR |= GPIO_BSRR_BR10_Msk;//亮灯
    }
    else if (led==1)
    {
        GPIOF->BSRR |= GPIO_BSRR_BS10_Msk;//灯灭
    }
}

//翻转LED状态
void LED0_Toggle(void)
{
    GPIOF->ODR ^= LED0_GPIO_PIN;
}

void LED1_Toggle(void)
{
    GPIOF->ODR ^= LED1_GPIO_PIN;
}

