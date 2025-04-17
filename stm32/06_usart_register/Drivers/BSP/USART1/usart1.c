#include "./BSP/USART1/usart1.h"

//初始化函数
void USART1_Init(void)
{
    //1.配置时钟
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//还是要先开启GPIOA对应的时钟
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;//开启usart1的时钟,F407中usart1/6是挂载在apb2高速线上的84Mhz
    
    //2.GPIO工作模式
    //PA9(TX):MODER复用输出(10),推挽(0)   
    //PA10(RX):浮空(00) 输入(00)
    
    //PA9(Tx)的配置
    GPIOA->MODER &= ~(GPIO_MODER_MODER9);
    GPIOA->MODER |= GPIO_MODER_MODER9_1;//复用   
    GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR9);
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1;//高速    
    GPIOA->OTYPER &=~(GPIO_OTYPER_OT9);//推挽
    GPIOA->PUPDR   &= ~GPIO_PUPDR_PUPD9;    
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD9_0;//上拉
    GPIOA->AFR[1]  |=  (7 << (4 * 1)); // AFRH[1]对应PA9，复用AF7 (0111)
    
    //PA10(Rx)的配置
    GPIOA->MODER &= ~(GPIO_MODER_MODER10);
    GPIOA->MODER |= GPIO_MODER_MODER10_1;//复用
    GPIOA->PUPDR   &= ~GPIO_PUPDR_PUPD10;    
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD10_0;//上拉
    GPIOA->AFR[1]  |=  (7 << (4 * 2));  // AFRH[2]对应PA10，复用AF7(0111)
    
    // 3. 配置USART1寄存器
    USART1->BRR = 0x2D9; //16MHz时钟时115200波特率（计算公式见下方说明）
    USART1->CR1 = 0;//CR1和CR2的默认复位值都是0
    USART1->CR2 = 0;
    
     // CR1配置
    USART1->CR1 |= USART_CR1_TE;       // 使能发送
    USART1->CR1 |= USART_CR1_RE;       // 使能接收
    USART1->CR1 |= USART_CR1_UE;       // 使能USART
    
    
}

//发送一个字符(轮询)
void USART1_SendChar(uint8_t ch)
{
    //判断SR里的TXE是否为1,当 TDR 寄存器的内容已传输到移位寄存器时，该位由硬件置 1
    while((USART1->SR & USART_SR_TXE)==0)//说明发送缓冲区还有数据,while循环中只需要等待即可
    {
    }
    //向DR中写入新的要发送的数据
    USART1->DR = ch;
    

}

//接收一个字符
uint8_t USART1_ReceiveChar(void)
{
    //当 RDR 移位寄存器的内容已传输到 USART_DR 寄存器时，该位由硬件置 1。
    while((USART1->SR & USART_SR_RXNE) == 0)
    {
    }
    
    //读取已经接受到的数据,等待接受下一个数据
    return USART1 -> DR;
}