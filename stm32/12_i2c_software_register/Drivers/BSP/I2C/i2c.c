#include "./BSP/I2C/i2c.h"

//��ʼ��
void I2C_Init(void)
{
    //1.����ʱ��
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    //2.GPIO����ģʽ����:ͨ�ÿ�©�������
    GPIOB->MODER &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9); // ���ԭ��ģʽ
    GPIOB->MODER |= (GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0);//ͨ�����

    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR8_1 |GPIO_OSPEEDER_OSPEEDR9_1);//50Mhz

    GPIOB->OTYPER |= (GPIO_OTYPER_OT_8 | GPIO_OTYPER_OT_9);//��©

    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD8 | GPIO_PUPDR_PUPD9); // ���ԭ������
    GPIOB->PUPDR |= (GPIO_PUPDR_PUPD8_0 | GPIO_PUPDR_PUPD9_0);//����

    // ��ʼ��Ϊ�ߵ�ƽ���ͷ����ߣ�

}

//������ʼ�ź�
void I2C_Start(void)
{
    //1.����SCL,SDA
    SCL_HIGHT;
    SDA_HIGHT;
    I2C_DELAY;
    
    //2.SCL���ֲ���,SDA����
    SDA_LOW;
    I2C_DELAY;

}

//����ֹͣ�ź�
void I2C_Stop(void)
{
    //1.����SCL,����SDA
    SCL_HIGHT;
    SDA_LOW;
    I2C_DELAY;
    
    //2.SCL���ֲ���,SDA����
    SDA_HIGHT;
    I2C_DELAY;
}

//��������Ӧ���ź�
void I2C_Ack(void)
{
    //1.SCL����,SDA����,׼������Ӧ���ź�
    SCL_LOW;
    SDA_HIGHT;
    I2C_DELAY;
    //2.SCL���ֲ���,SDA����,���Ӧ���ź�
    SDA_LOW;
    I2C_DELAY;    
    //3.SDA���ֲ���,SCL����,��ʼ�������ϵ��źŲ���
    SCL_HIGHT;
    I2C_DELAY;
    //4.SDA���ֲ���,SCL����,�����������ϵ��źŲ���
    SCL_LOW;
    I2C_DELAY;
    //5.SDA����,�ͷ���������
    SDA_HIGHT;
    I2C_DELAY;
}

//����������Ӧ���ź�
void I2C_Nack(void)
{
    //1.scl����,sda����,׼�������ź�
    SCL_LOW;
    SDA_HIGHT;
    I2C_DELAY;
    //2.SCL����,SDA����,
    SCL_HIGHT;
    I2C_DELAY;
    //3.SCL����,SDA���ֲ���,����
    SCL_LOW;
    I2C_DELAY;
}
    

//�����ȴ����豸����Ӧ���ź�
uint8_t I2C_Wait4Ack(void)
{
    //1.SCL����,SDA����,�ͷ���������
    SCL_LOW;
    SDA_HIGHT;
    I2C_DELAY;
    //2.SCL����,��ʼ���ݲ���
    SCL_HIGHT;
    I2C_DELAY;
    //3.��ȡSDA�������ϵĵ�ƽ
    uint16_t ack = READ_SDA;
    //4.scl����,�������ݲ���
    SCL_LOW;
    I2C_DELAY;
    return ack ? NACK : ACK;
}

//��������һ���ֽ�����(д��,��eepromд��)
void I2C_SendByte(uint8_t byte)
{
    //��һ���ֽ���,һ��bitһ��bit��������
    for(uint8_t i=0 ; i<8 ; i++)
    {
    //1.SCL\SDA����
        SCL_LOW;
        SDA_LOW;
        I2C_DELAY;
    
        //2.ȡ�ֽڵĸ�λ,��SDAд������
        if(byte&0x80)
        {
            SDA_HIGHT;
        }
        else
        {
            SDA_LOW;
        }
        I2C_DELAY;
        //3.SCL����,���ݲ���
        SCL_HIGHT;
        I2C_DELAY;
        
        //4.SCL����,��������
        SCL_LOW;
        I2C_DELAY;
        
        //5.����һλ
        byte <<= 1 ;                  
    }
    
}

//������EEPROM����һ���ֽڵ�����(��ȡ)
uint8_t I2C_Read_Byte(void)
{
    //����һ����������������յ�����
    uint8_t data = 0;
    //ѭ������ÿһλ
    for(uint8_t i = 0;i<8;i++)
    {
        //1.SCL����,�ȴ����ݷ�ת
        SCL_LOW;
        I2C_DELAY;
        
        //2.SCL����,��ʼ����
        SCL_HIGHT;
        I2C_DELAY;
        
        //3.���ݲ�����ȡSDA�ϵĵ�ƽ
        data <<= 1;//��������,�����´����Ϊ��Զ�����λ
        if(READ_SDA)
        {
            data |= 0x01;//�Ȱѷ��͹��������λ,����data�����λ.Ȼ��ÿ�ζ�����1λ
        }
        //����else��0��,��ΪĬ�Ͼ���data��λĬ��Ϊ0,��������Ĭ��Ҳ�ǲ�0
        
        //4.SCL����,��������
        SCL_LOW;
        I2C_DELAY;
        
    }
    return data;
}
