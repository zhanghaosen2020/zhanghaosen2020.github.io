#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

//#include "./BSP/LED/led.h"
//#include "./BSP/KEY/key.h"

#include "./BSP/USART1/usart1.h"


int main(void)
{
    sys_stm32_clock_init(336, 8, 2, 7);     /* ����ʱ��,168Mhz */
    delay_init(168);                        /* ��ʱ��ʼ�� */
    


//    LED_Init();//�ϱߵĲ����װ��������������
//    KEY_Init();

    //��ʼ������
    USART1_Init();
    
    //���͵����ַ�
    USART1_SendChar('a');
    USART1_SendChar('t');
    USART1_SendChar('\n');
    

    while(1)
    {
        // USART1_SendChar('b');
        // USART1_SendChar('\n');
        // delay_ms(1000);

        //�����ַ�,�ٷ��ͻ���
        uint8_t ch = USART1_ReceiveChar();
        USART1_SendChar(ch-32);//����Сд�ַ�,-32,�仯Ϊ��д�ַ�
    }
}

