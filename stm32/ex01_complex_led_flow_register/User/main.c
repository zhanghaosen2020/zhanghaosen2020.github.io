#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"

#include <string.h>
#include "./BSP/USART1/usart1.h"
#include "./BSP/EEPROM/m24c02.h"
#include "./BSP/KEY/key.h"
#include "./BSP/LED/led.h"

//�ȶ���ȫ�ֱ���
// uint16_t leds[] = {led0,led1};

uint8_t buffer[100];
uint8_t size;
uint8_t isOver;//������ɵı�־λ

//�ö�ά���鱣��������ˮ�Ʒ���
uint16_t plans[3][2];

int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* ����ʱ��,168Mhz */
    delay_init(168);                        /* ��ʱ��ʼ�� */
    
    //1.��ʼ��
    LED_Init();
    KEY_Init();
    USART1_Init();
    M24C02_Init();
    printf("��ӭʹ�û�ʽ��ˮ��!\n");

    
    
    while(1)
    {
        if(isOver)
        {
            //1.���浽eeprom
            M24C02_WriteBytes(0x00,buffer,size);
            
            //2.�����־λ��size
            size = 0;
            isOver = 0;

            M24C02_ReadBytes(0x00,buffer,11);
            printf("buffer:%s\n",buffer);
            //3.������ǰ���ַ���

            //4.���õ�һ�׷���չʾ��ˮ��
        }
    }
}

