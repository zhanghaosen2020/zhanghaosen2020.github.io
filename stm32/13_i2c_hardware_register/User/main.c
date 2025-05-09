#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"


#include "./BSP/USART1/usart1.h"
#include <string.h>
#include "./BSP/EEPROM/m24c02.h"

int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* ����ʱ��,168Mhz */
    delay_init(168);                        /* ��ʱ��ʼ�� */
    
    //1.��ʼ��
    USART1_Init();
    M24C02_Init();
    printf("IIC���ģ�⿪ʼ!\n");

    //2.��eepromһ��д�뵥���ֽ�
    M24C02_WriteByte(0x00,'a');
//    M24C02_WriteByte(0x01,'b');
//    M24C02_WriteByte(0x02,'c');
//    M24C02_WriteByte(0x03,'d');


    //3.һ�ζ�ȡ�ַ�
    uint8_t byte1 = M24C02_ReadByte(0x00);
//    uint8_t byte2 = M24C02_ReadByte(0x01);
//    uint8_t byte3 = M24C02_ReadByte(0x03);
//    uint8_t byte4 = M24C02_ReadByte(0x02);

    //4.���������ӡ
//    printf("byte1 = %c\t byte2 = %c\t byte3 = %c\t byte4 = %c\n",byte1,byte2,byte3,byte4);
    printf("byte1 = %c",byte1);
//    //5.д�����ַ�
//    M24C02_WriteBytes(0x00,"12345af",7);

//    //6.��ȡ����ַ�
//    uint8_t buffer[100] = {0};
//    M24C02_ReadBytes(0x00,buffer,7);

//    //7.���ڴ�ӡ
//    printf("buffer1 = %s\n",buffer);


//    //8.���Գ���16���ӽڵ�д��  (������һҳ��16���ӽ�,m24c02��������ǰ����)
//    //ATM24C02��һҳ8���ֽ�
//    // memset(buffer ,0 ,sizeof(buffer));//��buffer���������
//    M24C02_WriteBytes(0x00,"1234567890abc",13);
//    M24C02_ReadBytes(0x00,buffer,13);
//    printf("buffer2 = %s\n",buffer);
//    
//    //9.ҳд
//    memset(buffer ,0 ,sizeof(buffer));//��buffer���������
//    M24C02_WriteBytes(0x00,"1234567890abcdef",16);
//    M24C02_ReadBytes(0x00,buffer,16);
//    printf("buffer3 = %s\n",buffer);
    
    
    while(1)
    {

    }
}

