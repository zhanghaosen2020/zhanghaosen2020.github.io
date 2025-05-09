#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"


#include "./BSP/USART1/usart1.h"
#include <string.h>
#include "./BSP/EEPROM/m24c02.h"

int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    
    //1.初始化
    USART1_Init();
    M24C02_Init();
    printf("IIC软件模拟开始!\n");

    //2.向eeprom一次写入单个字节
    M24C02_WriteByte(0x00,'a');
//    M24C02_WriteByte(0x01,'b');
//    M24C02_WriteByte(0x02,'c');
//    M24C02_WriteByte(0x03,'d');


    //3.一次读取字符
    uint8_t byte1 = M24C02_ReadByte(0x00);
//    uint8_t byte2 = M24C02_ReadByte(0x01);
//    uint8_t byte3 = M24C02_ReadByte(0x03);
//    uint8_t byte4 = M24C02_ReadByte(0x02);

    //4.串口输出打印
//    printf("byte1 = %c\t byte2 = %c\t byte3 = %c\t byte4 = %c\n",byte1,byte2,byte3,byte4);
    printf("byte1 = %c",byte1);
//    //5.写入多个字符
//    M24C02_WriteBytes(0x00,"12345af",7);

//    //6.读取多个字符
//    uint8_t buffer[100] = {0};
//    M24C02_ReadBytes(0x00,buffer,7);

//    //7.串口打印
//    printf("buffer1 = %s\n",buffer);


//    //8.测试超出16个子节的写入  (若超出一页的16个子节,m24c02会重新往前覆盖)
//    //ATM24C02是一页8个字节
//    // memset(buffer ,0 ,sizeof(buffer));//将buffer的数据清空
//    M24C02_WriteBytes(0x00,"1234567890abc",13);
//    M24C02_ReadBytes(0x00,buffer,13);
//    printf("buffer2 = %s\n",buffer);
//    
//    //9.页写
//    memset(buffer ,0 ,sizeof(buffer));//将buffer的数据清空
//    M24C02_WriteBytes(0x00,"1234567890abcdef",16);
//    M24C02_ReadBytes(0x00,buffer,16);
//    printf("buffer3 = %s\n",buffer);
    
    
    while(1)
    {

    }
}

