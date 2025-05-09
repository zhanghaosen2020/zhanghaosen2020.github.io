#include "m24c02.h"

//��ʼ��
void M24C02_Init(void)
{
    MX_I2C1_Init();
}

//��EEPROMд��һ���ֽ�
void M24C02_WriteByte(uint8_t innerAddr , uint8_t byte)
{
    HAL_I2C_Mem_Write(&hi2c1, W_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, &byte, 1, 2000);
   
    //�ӳٵȴ�д���ڽ���,д��������Ҫһ������
    HAL_Delay(5);
}

//��ȡEEPROM��һ���ֽ�
uint8_t M24C02_ReadByte(uint8_t innerAddr)
{
    
    uint8_t byte;
    HAL_I2C_Mem_Read(&hi2c1, R_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, &byte, 1, 2000);
    return byte;


}

//����д�����ֽ�(ҳд)
void M24C02_WriteBytes(uint8_t innerAddr , uint8_t *bytes, uint8_t size)
{
     HAL_I2C_Mem_Write(&hi2c1, W_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, bytes, size, 1000);
   
    //�ӳٵȴ�д���ڽ���,д��������Ҫһ������
    HAL_Delay(5);
}


//������ȡ����ֽ�
void M24C02_ReadBytes(uint8_t innerAddr , uint8_t *buffer, uint8_t size)
{
  

 HAL_I2C_Mem_Read(&hi2c1, R_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, buffer, size, 2000);


}
