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
    while((USART1->SR & USART_SR_TXE) == 0)//说明发送缓冲区还有数据,while循环中只需要等待即可
    {
    }
    //向DR中写入新的要发送的数据
    USART1->DR = ch;//对DR进行写操作之后,就会自己将TXE清零  

}

//接收一个字符
uint8_t USART1_ReceiveChar(void)
{
    //当 RDR 移位寄存器的内容已传输到 USART_DR 寄存器时，该位由硬件置 1。
    while((USART1->SR & USART_SR_RXNE) == 0)
    {
        //增加判断空闲帧的条件
        if(USART1->SR & USART_SR_IDLE)
        {
            return 0;//\0
        }
    }    
    //读取已经接受到的数据,等待接受下一个数据
    return USART1 -> DR;//这里引申出一个新的问题,RXNE这一位硬件置位,那他怎么复位呢,只有复位了才能下一步操作
    //其实在寄存器的描述中,当我们读DR的时候就可以将其复位(为0),即return USART1->DR;
}

//发送字符串
void USART1_SendString(uint8_t *str ,uint8_t size)
{
    for(uint8_t i=0; i < size ;i++)
    {
        USART1_SendChar(str[i]);
    }
}

// 接收字符串
void USART1_ReceiveString(uint8_t buffer[],uint8_t *size)
{
    //定义一个变量,用来保存已经接收到的字符个数
    uint8_t i = 0;
    while((USART1->SR & USART_SR_IDLE) == 0)
    {
        buffer[i]  = USART1_ReceiveChar();
/*这里试着来分析一下,上边的逻辑相当于while循环的嵌套,最后一个字符进入内循环之后,IDLE这个标志位
  还没有置位(因为这需要一个字节的空闲帧),因此会再次进入接受一个字符的内循环,但是此时已经没有字符接收了,
  就会一直卡在内循环里*/
        i++;
    }
    //清除IDLE位
    USART1->SR;
    USART1->DR;

    *size = --i;
}


//下面这是个有用的正确函数,不过逻辑复杂了一点
// void USART1_ReceiveString(uint8_t buffer[],uint8_t *size)//这里的逻辑要稍微复杂一点,可是理清楚之后也就还好
// {
//     //定义一个变量,用来保存已经接收到的字符个数
//     uint8_t i = 0;

//     //外层,不停的接受下一个字符
//     while(1)//里边一定要可以跳出循环
//     {
//         //内层循环,判断当前数据帧是否接受完毕
//         while((USART1->SR & USART_SR_RXNE) == 0)
//         {
//             //在等待期间,判断是否收到空闲帧
//             if(USART1->SR & USART_SR_IDLE)
//             {
//                 //字符串接受完毕
//                 *size = i;
//                 return;
//             }
//         }
//         //把接收到的字符放入缓冲区中
//         buffer[i] = USART1->DR;
//         i++;
//     }
// }