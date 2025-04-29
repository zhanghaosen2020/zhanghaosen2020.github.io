#include "./BSP/I2C/i2c.h"

//初始化
void I2C_Init(void)
{
    //1.配置时钟
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    //2.GPIO工作模式设置:通用开漏输出上拉
    GPIOB->MODER &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9); // 清除原有模式
    GPIOB->MODER |= (GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0);//通用输出

    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8_1 |GPIO_OSPEEDER_OSPEEDR9_1);//50Mhz

    GPIOB->OTYPER |= (GPIO_OTYPER_OT_8 | GPIO_OTYPER_OT_9);//开漏

    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD8 | GPIO_PUPDR_PUPD9); // 清除原有配置
    GPIOB->PUPDR |= (GPIO_PUPDR_PUPD8_0 | GPIO_PUPDR_PUPD9_0);//上拉

    // 初始化为高电平（释放总线）

}

//发出起始信号
void I2C_Start(void)
{
    //1.拉高SCL,SDA
    SCL_HIGHT;
    SDA_HIGHT;
    I2C_DELAY;
    
    //2.SCL保持不变,SDA拉低
    SDA_LOW;
    I2C_DELAY;

}

//发出停止信号
void I2C_Stop(void)
{
    //1.拉高SCL,拉低SDA
    SCL_HIGHT;
    SDA_LOW;
    I2C_DELAY;
    
    //2.SCL保持不变,SDA拉高
    SDA_HIGHT;
    I2C_DELAY;
}

//主机发出应答信号
void I2C_Ack(void)
{
    //1.SCL拉低,SDA拉高,准备发出应答信号
    SCL_LOW;
    SDA_HIGHT;
    I2C_DELAY;
    //2.SCL保持不变,SDA拉低,输出应答信号
    SDA_LOW;
    I2C_DELAY;    
    //3.SDA保持不变,SCL拉高,开始数据线上的信号采样
    SCL_HIGHT;
    I2C_DELAY;
    //4.SDA保持不变,SCL拉低,结束数据线上的信号采样
    SCL_LOW;
    I2C_DELAY;
    //5.SDA拉高,释放数据总线
    SDA_HIGHT;
    I2C_DELAY;
}

//主机发出非应答信号
void I2C_Nack(void)
{
    //1.scl拉低,sda拉高,准备发出信号
    SCL_LOW;
    SDA_HIGHT;
    I2C_DELAY;
    //2.SCL拉高,SDA不变,
    SCL_HIGHT;
    I2C_DELAY;
    //3.SCL拉低,SDA保持不变,结束
    SCL_LOW;
    I2C_DELAY;
}
    

//主机等待从设备发来应答信号
uint8_t I2C_Wait4Ack(void)
{
    //1.SCL拉低,SDA拉高,释放数据总线
    SCL_LOW;
    SDA_HIGHT;
    I2C_DELAY;
    //2.SCL拉高,开始数据采样
    SCL_HIGHT;
    I2C_DELAY;
    //3.读取SDA数据线上的电平
    uint16_t ack = READ_SDA;
    //4.scl拉低,结束数据采样
    SCL_LOW;
    I2C_DELAY;
    return ack ? NACK : ACK;
}

//主机发送一个字节数据(写入,往eeprom写入)
void I2C_SendByte(uint8_t byte)
{
    //从一个字节中,一个bit一个bit的拿数据
    for(uint8_t i=0 ; i<8 ; i++)
    {
    //1.SCL\SDA拉低
        SCL_LOW;
        SDA_LOW;
        I2C_DELAY;
    
        //2.取字节的高位,向SDA写入数据
        if(byte&0x80)
        {
            SDA_HIGHT;
        }
        else
        {
            SDA_LOW;
        }
        I2C_DELAY;
        //3.SCL拉高,数据采样
        SCL_HIGHT;
        I2C_DELAY;
        
        //4.SCL拉低,采样结束
        SCL_LOW;
        I2C_DELAY;
        
        //5.左移一位
        byte <<= 1 ;                  
    }
    
}

//主机从EEPROM接收一个字节的数据(读取)
uint8_t I2C_Read_Byte(void)
{
    //定义一个变量用来保存接收的数据
    uint8_t data = 0;
    //循环处理每一位
    for(uint8_t i = 0;i<8;i++)
    {
        //1.SCL拉低,等待数据翻转
        SCL_LOW;
        I2C_DELAY;
        
        //2.SCL拉高,开始采样
        SCL_HIGHT;
        I2C_DELAY;
        
        //3.数据采样读取SDA上的电平
        data <<= 1;//先做左移,这样新存入的为永远在最低位
        if(READ_SDA)
        {
            data |= 0x01;//先把发送过来的最高位,存入data的最低位.然后每次都左移1位
        }
        //不用else给0了,因为默认就是data的位默认为0,并且左移默认也是补0
        
        //4.SCL拉低,结束采样
        SCL_LOW;
        I2C_DELAY;
        
    }
    return data;
}
