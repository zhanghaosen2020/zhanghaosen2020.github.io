#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

//#include "./BSP/LED/led.h"
//#include "./BSP/KEY/key.h"

#include "./BSP/USART1/usart1.h"
#include "string.h"


int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    USART1_Init();
    
    uint16_t a = 100;
    printf("a = %d\n",a);
    printf("hellow\n");
  
    while(1)
    {

    }
}

