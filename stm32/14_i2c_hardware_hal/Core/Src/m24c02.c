#include "m24c02.h"

//初始化
void M24C02_Init(void)
{
    MX_I2C1_Init();
}

//向EEPROM写入一个字节
void M24C02_WriteByte(uint8_t innerAddr , uint8_t byte)
{
    HAL_I2C_Mem_Write(&hi2c1, W_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, &byte, 1, 2000);
   
    //延迟等待写周期结束,写入数据需要一个周期
    HAL_Delay(5);
}

//读取EEPROM的一个字节
uint8_t M24C02_ReadByte(uint8_t innerAddr)
{
    
    uint8_t byte;
    HAL_I2C_Mem_Read(&hi2c1, R_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, &byte, 1, 2000);
    return byte;


}

//连续写入多个字节(页写)
void M24C02_WriteBytes(uint8_t innerAddr , uint8_t *bytes, uint8_t size)
{
     HAL_I2C_Mem_Write(&hi2c1, W_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, bytes, size, 1000);
   
    //延迟等待写周期结束,写入数据需要一个周期
    HAL_Delay(5);
}


//连续读取多个字节
void M24C02_ReadBytes(uint8_t innerAddr , uint8_t *buffer, uint8_t size)
{
  

 HAL_I2C_Mem_Read(&hi2c1, R_ADDR, innerAddr, I2C_MEMADD_SIZE_8BIT, buffer, size, 2000);


}
