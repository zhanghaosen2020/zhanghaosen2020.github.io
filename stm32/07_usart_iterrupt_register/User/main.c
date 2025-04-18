#include "./SYSTEM/sys/sys.h"
//#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

//#include "./BSP/LED/led.h"
//#include "./BSP/KEY/key.h"

#include "./BSP/USART1/usart1.h"
#include "string.h"

//����ȫ�ֱ���,���ջ�������size
uint8_t buffer[100] = { 0 };
uint8_t size = 0;
//����һ����־λ
uint8_t isOver = 0;

int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* ����ʱ��,168Mhz */
    delay_init(168);                        /* ��ʱ��ʼ�� */
    
    //��ʼ������
    USART1_Init();
    
    //���͵����ַ�
    USART1_SendChar('a');
    USART1_SendChar('t');
    USART1_SendChar('\n');

    //�����ַ���
    uint8_t *str = "hellow wrold\n";
    USART1_SendString(str,strlen((char*)str));//strlenӦ�ô���һ��const cahr*������,������������ǿתһ������,���ⱨ��
    
    while(1)
    {
        if(isOver == 1)
        {
            USART1_SendString(buffer ,size);

            //�����־λ
            isOver = 0;
            size = 0;
        } 
    }
}

