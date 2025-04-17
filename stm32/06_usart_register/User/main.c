#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

//#include "./BSP/LED/led.h"
//#include "./BSP/KEY/key.h"

#include "./BSP/USART1/usart1.h"


int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    


//    LED_Init();//上边的步骤封装到这个函数里边了
//    KEY_Init();

    //初始化串口
    USART1_Init();
    
    //发送单个字符
    USART1_SendChar('a');
    USART1_SendChar('t');
    USART1_SendChar('\n');
    

    while(1)
    {
        // USART1_SendChar('b');
        // USART1_SendChar('\n');
        // delay_ms(1000);

        //接收字符,再发送回来
        uint8_t ch = USART1_ReceiveChar();
        USART1_SendChar(ch-32);//发送小写字符,-32,变化为大写字符
    }
}

