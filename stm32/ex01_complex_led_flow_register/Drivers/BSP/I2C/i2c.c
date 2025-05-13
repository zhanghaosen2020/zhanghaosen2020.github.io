#include "./BSP/I2C/i2c.h"

//初始化
void I2C_Init(void)
{
    //1.配置时钟// 使能GPIOB和I2C1的时钟    
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;   // 使能GPIOB时钟
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;    // 使能I2C1时钟

    //2.GPIO工作模式设置:复用 开漏 输出上拉    
    // 配置PB6和PB7为复用功能模式（AF4），开漏输出，上拉
    GPIOB->MODER   &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9); // 清除原有模式
    GPIOB->MODER   |= (2 << GPIO_MODER_MODER8_Pos) | (2 << GPIO_MODER_MODER9_Pos); // 设置为复用模式
    GPIOB->OTYPER  |= GPIO_OTYPER_OT8 | GPIO_OTYPER_OT9;        // 开漏输出
    GPIOB->PUPDR   |= (GPIO_PUPDR_PUPD8_0 | GPIO_PUPDR_PUPD9_0); // 上拉电阻
    
    //这步很重要
    GPIOB->AFR[1]  |= (4 << GPIO_AFRH_AFSEL8_Pos) | (4 << GPIO_AFRH_AFSEL9_Pos);    // AF4（I2C1复用功能）
//该功能是在stm32f407data手册 3.7 节alternate function mapping里边
    
    //3.IIC1配置
    //3.1硬件工作模式
    I2C1->CR1 &= ~I2C_CR1_SMBUS;//此位默认也是置位0的
    //3.2复位IIC外设
    I2C1->CR1 |= I2C_CR1_SWRST;    // 进入复位模式
    I2C1->CR1 &= ~I2C_CR1_SWRST;   // 退出复位模式
    //3.3配置时钟控制寄存器（I2C_CR2）//选择输入的时钟频率
    I2C1->CR2 |= 42; // 设置APB1时钟频率（单位：MHz）
    //3.4配置CCR寄存器（时钟控制）,对应数据传输时间100kbit/s,高电平5us
    I2C1->CCR |= 210; // 标准模式，Duty cycle = 2（默认）
    //3.5配置TRISE寄存器（上升时间）,scl上升沿最大时钟周期数 + 1
    I2C1->TRISE = 43;
    
    //3.6使能II2模块
    I2C1->CR1 |= I2C_CR1_PE;
}


//发出起始信号
uint8_t I2C_Start(void)
{
    //1.产生一个起始信号
    I2C1->CR1 |= I2C_CR1_START;
    
    //引入一个超时时间
    uint16_t timeout = 0xffff;
    
    //2.等待起始信号发出
    while((I2C1->SR1 & I2C_SR1_SB) == 0  &&  timeout)//当SB置位为1的时候,起始信号发送已发送
    {
        timeout--;
    }     
    return timeout ? OK : FAIL;

}

//发出停止信号
void I2C_Stop(void)
{
    I2C1->CR1 |= I2C_CR1_STOP;
}


//主机发出应答信号
void I2C_Ack(void)
{
   
    I2C1->CR1 |= I2C_CR1_ACK;
}

//主机发出非应答信号
void I2C_Nack(void)
{
    I2C1->CR1 &= ~I2C_CR1_ACK;
}
    

//发送设备地址,并等待应答
uint8_t I2C_SendAddr(uint8_t addr)
{
    //直接将要发送的地址给到DR(默认DR就为空)
    //—发送模式：在 DR 寄存器中写入第一个字节时自动开始发送字节
    I2C1->DR = addr;
    
    //等待应答
    uint16_t timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_ADDR) == 0 && timeout)//这一位置1之后,说明地址发送结束
    {
        timeout--;
    }
    //访问SR2,清除ADDR标志位,对应数据手册671
    if(timeout)
    {
        I2C1->SR2;
    }        
    return timeout ? OK : FAIL;        
}

//主机发送一个字节数据(写入,往eeprom写入),并且等待应答
uint8_t I2C_SendByte(uint8_t byte)
{
    //1.等待DR为空,即上一个字节数据已经发送完毕
    uint16_t timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_TXE) == 0 && timeout)
    {
        timeout--;
    }
    
    //2.将要发送的字节放入DR中
    I2C1-> DR = byte;
        
    //3.等待应答
    timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_BTF) == 0 && timeout)
    {
        timeout--;
    }   
    return timeout ? OK : FAIL;   
}

//主机从EEPROM接收一个字节的数据(读取)
uint8_t I2C_Read_Byte(void)
{
    //1.先等待DR为满
    uint16_t timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_RXNE) == 0 && timeout)
    {
        timeout--;
    }
    
    //2.将收到的字节数据返回
    uint8_t data =  timeout ? I2C1->DR : FAIL;
    return data;
}
