#include "./BSP/USART1/usart1.h"

//��ʼ������
void USART1_Init(void)
{
    //1.����ʱ��
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//����Ҫ�ȿ���GPIOA��Ӧ��ʱ��
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;//����usart1��ʱ��,F407��usart1/6�ǹ�����apb2�������ϵ�84Mhz
    
    //2.GPIO����ģʽ
    //PA9(TX):MODER�������(10),����(0)   
    //PA10(RX):����(00) ����(00)
    
    //PA9(Tx)������
    GPIOA->MODER &= ~(GPIO_MODER_MODER9);
    GPIOA->MODER |= GPIO_MODER_MODER9_1;//����   
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR9);
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1;//����    
    GPIOA->OTYPER &=~(GPIO_OTYPER_OT9);//����
    GPIOA->PUPDR   &= ~GPIO_PUPDR_PUPD9;    
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD9_0;//����
    GPIOA->AFR[1]  |=  (7 << (4 * 1)); // AFRH[1]��ӦPA9������AF7 (0111)
    
    //PA10(Rx)������
    GPIOA->MODER &= ~(GPIO_MODER_MODER10);
    GPIOA->MODER |= GPIO_MODER_MODER10_1;//����
    GPIOA->PUPDR   &= ~GPIO_PUPDR_PUPD10;    
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD10_0;//����
    GPIOA->AFR[1]  |=  (7 << (4 * 2));  // AFRH[2]��ӦPA10������AF7(0111)
    
    // 3. ����USART1�Ĵ���
    USART1->BRR = 0x2D9; //16MHzʱ��ʱ115200�����ʣ����㹫ʽ���·�˵����
    USART1->CR1 = 0;//CR1��CR2��Ĭ�ϸ�λֵ����0
    USART1->CR2 = 0;
    
     // CR1����
    USART1->CR1 |= USART_CR1_TE;       // ʹ�ܷ���
    USART1->CR1 |= USART_CR1_RE;       // ʹ�ܽ���
    USART1->CR1 |= USART_CR1_UE;       // ʹ��USART
    
    
}

//����һ���ַ�(��ѯ)
void USART1_SendChar(uint8_t ch)
{
    //�ж�SR���TXE�Ƿ�Ϊ1,�� TDR �Ĵ����������Ѵ��䵽��λ�Ĵ���ʱ����λ��Ӳ���� 1
    while((USART1->SR & USART_SR_TXE) == 0)//˵�����ͻ�������������,whileѭ����ֻ��Ҫ�ȴ�����
    {
    }
    //��DR��д���µ�Ҫ���͵�����
    USART1->DR = ch;//��DR����д����֮��,�ͻ��Լ���TXE����  

}

//����һ���ַ�
uint8_t USART1_ReceiveChar(void)
{
    //�� RDR ��λ�Ĵ����������Ѵ��䵽 USART_DR �Ĵ���ʱ����λ��Ӳ���� 1��
    while((USART1->SR & USART_SR_RXNE) == 0)
    {
        //�����жϿ���֡������
        if(USART1->SR & USART_SR_IDLE)
        {
            return 0;//\0
        }
    }    
    //��ȡ�Ѿ����ܵ�������,�ȴ�������һ������
    return USART1 -> DR;//���������һ���µ�����,RXNE��һλӲ����λ,������ô��λ��,ֻ�и�λ�˲�����һ������
    //��ʵ�ڼĴ�����������,�����Ƕ�DR��ʱ��Ϳ��Խ��临λ(Ϊ0),��return USART1->DR;
}

//�����ַ���
void USART1_SendString(uint8_t *str ,uint8_t size)
{
    for(uint8_t i=0; i < size ;i++)
    {
        USART1_SendChar(str[i]);
    }
}

// �����ַ���
void USART1_ReceiveString(uint8_t buffer[],uint8_t *size)
{
    //����һ������,���������Ѿ����յ����ַ�����
    uint8_t i = 0;
    while((USART1->SR & USART_SR_IDLE) == 0)
    {
        buffer[i]  = USART1_ReceiveChar();
/*��������������һ��,�ϱߵ��߼��൱��whileѭ����Ƕ��,���һ���ַ�������ѭ��֮��,IDLE�����־λ
  ��û����λ(��Ϊ����Ҫһ���ֽڵĿ���֡),��˻��ٴν������һ���ַ�����ѭ��,���Ǵ�ʱ�Ѿ�û���ַ�������,
  �ͻ�һֱ������ѭ����*/
        i++;
    }
    //���IDLEλ
    USART1->SR;
    USART1->DR;

    *size = --i;
}


//�������Ǹ����õ���ȷ����,�����߼�������һ��
// void USART1_ReceiveString(uint8_t buffer[],uint8_t *size)//������߼�Ҫ��΢����һ��,���������֮��Ҳ�ͻ���
// {
//     //����һ������,���������Ѿ����յ����ַ�����
//     uint8_t i = 0;

//     //���,��ͣ�Ľ�����һ���ַ�
//     while(1)//���һ��Ҫ��������ѭ��
//     {
//         //�ڲ�ѭ��,�жϵ�ǰ����֡�Ƿ�������
//         while((USART1->SR & USART_SR_RXNE) == 0)
//         {
//             //�ڵȴ��ڼ�,�ж��Ƿ��յ�����֡
//             if(USART1->SR & USART_SR_IDLE)
//             {
//                 //�ַ����������
//                 *size = i;
//                 return;
//             }
//         }
//         //�ѽ��յ����ַ����뻺������
//         buffer[i] = USART1->DR;
//         i++;
//     }
// }