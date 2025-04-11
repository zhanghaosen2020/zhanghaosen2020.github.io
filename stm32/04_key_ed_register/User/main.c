#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

#include "./BSP/LED/led.h"
#include "./BSP/KEY/key.h"


int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */


    LED_Init();//上边的步骤封装到这个函数里边了
    KEY_Init();


    while(1)
    {

        

    }
}

