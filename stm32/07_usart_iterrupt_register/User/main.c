#include "./SYSTEM/sys/sys.h"
//#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

//#include "./BSP/LED/led.h"
//#include "./BSP/KEY/key.h"

#include "./BSP/USART1/usart1.h"
#include "string.h"

//定义全局变量,接收缓冲区和size
uint8_t buffer[100] = { 0 };
uint8_t size = 0;
//定义一个标志位
uint8_t isOver = 0;

int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    
    //初始化串口
    USART1_Init();
    
    //发送单个字符
    USART1_SendChar('a');
    USART1_SendChar('t');
    USART1_SendChar('\n');

    //发送字符串
    uint8_t *str = "hellow wrold\n";
    USART1_SendString(str,strlen((char*)str));//strlen应该传入一个const cahr*的数据,所以我们这里强转一下类型,避免报错
    
    while(1)
    {
        if(isOver == 1)
        {
            USART1_SendString(buffer ,size);

            //清除标志位
            isOver = 0;
            size = 0;
        } 
    }
}

