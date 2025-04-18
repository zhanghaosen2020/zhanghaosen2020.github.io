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

    //4.开启中断使能(我们往往用中断的方式来接受外部发送给单片机的不定长数据(用轮询来发送))
    USART1->CR1 |= (USART_CR1_IDLEIE | USART_CR1_RXNEIE);

    //5.设置中断优先级NVIC
    NVIC_SetPriorityGrouping(3);
    NVIC_SetPriority(USART1_IRQn,2);
    NVIC_EnableIRQ(USART1_IRQn);

}

//发送一个字符(轮询)
void USART1_SendChar(uint8_t ch)
{
    //判断SR里的TXE是否为1,当 TDR 寄存器的内容已传输到移位寄存器时，该位由硬件置 1
    while((USART1->SR & USART_SR_TXE) == 0)//说明发送缓冲区还有数据,while循环中只需要等待即可
    {
    }
    //向DR中写入新的要发送的数据
    USART1->DR = ch;//对DR进行写操作之后,就会自己将TXE清零
}

//发送字符串
void USART1_SendString(uint8_t *str ,uint8_t size)
{
    for(uint8_t i = 0; i < size ;i++)
    {
        USART1_SendChar(str[i]);
    }
}


//中断服务程序
void USART1_IRQHandler(void)
{
    //有很多事件都可以产生中断,但是你需要判断
    //首先判断中断类型
    if(USART1->SR & USART_SR_RXNE)//寄存器
    {
        //接受完成一个字符
        buffer[size] = USART1->DR;//接收一个字符的时候,放入0号位置
        size++;
    }
    else if(USART1->SR & USART_SR_IDLE)
    {
        //字符串整体接收完成
        //清除IDLE标志位
        USART1->SR ;
        USART1->DR;

        //直接发送字符串到电脑
        USART1_SendString(buffer,size);

        //清0 size
        size = 0;
    }
}
