#include "./BSP/I2C/i2c.h"

//��ʼ��
void I2C_Init(void)
{
    //1.����ʱ��// ʹ��GPIOB��I2C1��ʱ��    
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;   // ʹ��GPIOBʱ��
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;    // ʹ��I2C1ʱ��

    //2.GPIO����ģʽ����:���� ��© �������    
    // ����PB6��PB7Ϊ���ù���ģʽ��AF4������©���������
    GPIOB->MODER   &= ~(GPIO_MODER_MODER8 | GPIO_MODER_MODER9); // ���ԭ��ģʽ
    GPIOB->MODER   |= (2 << GPIO_MODER_MODER8_Pos) | (2 << GPIO_MODER_MODER9_Pos); // ����Ϊ����ģʽ
    GPIOB->OTYPER  |= GPIO_OTYPER_OT8 | GPIO_OTYPER_OT9;        // ��©���
    GPIOB->PUPDR   |= (GPIO_PUPDR_PUPD8_0 | GPIO_PUPDR_PUPD9_0); // ��������
    
    //�ⲽ����Ҫ
    GPIOB->AFR[1]  |= (4 << GPIO_AFRH_AFSEL8_Pos) | (4 << GPIO_AFRH_AFSEL9_Pos);    // AF4��I2C1���ù��ܣ�
//�ù�������stm32f407data�ֲ� 3.7 ��alternate function mapping���
    
    //3.IIC1����
    //3.1Ӳ������ģʽ
    I2C1->CR1 &= ~I2C_CR1_SMBUS;//��λĬ��Ҳ����λ0��
    //3.2��λIIC����
    I2C1->CR1 |= I2C_CR1_SWRST;    // ���븴λģʽ
    I2C1->CR1 &= ~I2C_CR1_SWRST;   // �˳���λģʽ
    //3.3����ʱ�ӿ��ƼĴ�����I2C_CR2��//ѡ�������ʱ��Ƶ��
    I2C1->CR2 |= 42; // ����APB1ʱ��Ƶ�ʣ���λ��MHz��
    //3.4����CCR�Ĵ�����ʱ�ӿ��ƣ�,��Ӧ���ݴ���ʱ��100kbit/s,�ߵ�ƽ5us
    I2C1->CCR |= 210; // ��׼ģʽ��Duty cycle = 2��Ĭ�ϣ�
    //3.5����TRISE�Ĵ���������ʱ�䣩,scl���������ʱ�������� + 1
    I2C1->TRISE = 43;
    
    //3.6ʹ��II2ģ��
    I2C1->CR1 |= I2C_CR1_PE;
}


//������ʼ�ź�
uint8_t I2C_Start(void)
{
    //1.����һ����ʼ�ź�
    I2C1->CR1 |= I2C_CR1_START;
    
    //����һ����ʱʱ��
    uint16_t timeout = 0xffff;
    
    //2.�ȴ���ʼ�źŷ���
    while((I2C1->SR1 & I2C_SR1_SB) == 0  &&  timeout)//��SB��λΪ1��ʱ��,��ʼ�źŷ����ѷ���
    {
        timeout--;
    }     
    return timeout ? OK : FAIL;

}

//����ֹͣ�ź�
void I2C_Stop(void)
{
    I2C1->CR1 |= I2C_CR1_STOP;
}


//��������Ӧ���ź�
void I2C_Ack(void)
{
   
    I2C1->CR1 |= I2C_CR1_ACK;
}

//����������Ӧ���ź�
void I2C_Nack(void)
{
    I2C1->CR1 &= ~I2C_CR1_ACK;
}
    

//�����豸��ַ,���ȴ�Ӧ��
uint8_t I2C_SendAddr(uint8_t addr)
{
    //ֱ�ӽ�Ҫ���͵ĵ�ַ����DR(Ĭ��DR��Ϊ��)
    //������ģʽ���� DR �Ĵ�����д���һ���ֽ�ʱ�Զ���ʼ�����ֽ�
    I2C1->DR = addr;
    
    //�ȴ�Ӧ��
    uint16_t timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_ADDR) == 0 && timeout)//��һλ��1֮��,˵����ַ���ͽ���
    {
        timeout--;
    }
    //����SR2,���ADDR��־λ,��Ӧ�����ֲ�671
    if(timeout)
    {
        I2C1->SR2;
    }        
    return timeout ? OK : FAIL;        
}

//��������һ���ֽ�����(д��,��eepromд��),���ҵȴ�Ӧ��
uint8_t I2C_SendByte(uint8_t byte)
{
    //1.�ȴ�DRΪ��,����һ���ֽ������Ѿ��������
    uint16_t timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_TXE) == 0 && timeout)
    {
        timeout--;
    }
    
    //2.��Ҫ���͵��ֽڷ���DR��
    I2C1-> DR = byte;
        
    //3.�ȴ�Ӧ��
    timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_BTF) == 0 && timeout)
    {
        timeout--;
    }   
    return timeout ? OK : FAIL;   
}

//������EEPROM����һ���ֽڵ�����(��ȡ)
uint8_t I2C_Read_Byte(void)
{
    //1.�ȵȴ�DRΪ��
    uint16_t timeout = 0xffff;
    while((I2C1->SR1 & I2C_SR1_RXNE) == 0 && timeout)
    {
        timeout--;
    }
    
    //2.���յ����ֽ����ݷ���
    uint8_t data =  timeout ? I2C1->DR : FAIL;
    return data;
}
