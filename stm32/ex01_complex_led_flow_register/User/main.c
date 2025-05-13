#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"

#include <string.h>
#include "./BSP/USART1/usart1.h"
#include "./BSP/EEPROM/m24c02.h"
#include "./BSP/KEY/key.h"
#include "./BSP/LED/led.h"

//先定义全局变量
// uint16_t leds[] = {led0,led1};

uint8_t buffer[100];
uint8_t size;
uint8_t isOver;//接收完成的标志位

//用二维数组保存三组流水灯方案
uint16_t plans[3][2];

int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    
    //1.初始化
    LED_Init();
    KEY_Init();
    USART1_Init();
    M24C02_Init();
    printf("欢迎使用花式流水灯!\n");

    
    
    while(1)
    {
        if(isOver)
        {
            //1.保存到eeprom
            M24C02_WriteBytes(0x00,buffer,size);
            
            //2.清除标志位和size
            size = 0;
            isOver = 0;

            M24C02_ReadBytes(0x00,buffer,11);
            printf("buffer:%s\n",buffer);
            //3.解析当前的字符串

            //4.采用第一套方案展示流水灯
        }
    }
}

