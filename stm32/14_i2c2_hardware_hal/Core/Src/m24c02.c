#include "m24c02.h"

//初始化
void M24C02_Init(void)
{
    MX_I2C2_Init();
}

//向EEPROM写入一个字节
void M24C02_WriteByte(uint8_t innerAddr , uint8_t byte)
{
    HAL_I2C_Mem_Write(&hi2c2,W_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,&byte, 1 , 1000);

    HAL_Delay(5);//

    // //1.发出开始信号
    // I2C_Start();

    // //2.发送写地址
    // I2C_SendAddr(W_ADDR); //3.等待eeprom的应答

   
    // //4.发送内部地址
    // I2C_SendByte(innerAddr);


    // //6.发送具体的数据
    // I2C_SendByte(byte);

    // //8.发出一个停止信号
    // I2C_Stop();
    
    // //延迟等待写周期结束,写入数据需要一个周期
    // delay_ms(5);//
}

//读取EEPROM的一个字节
uint8_t M24C02_ReadByte(uint8_t innerAddr)
{
    uint8_t byte ;
    HAL_I2C_Mem_Read(&hi2c2,R_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,&byte, 1 , 1000);
    HAL_Delay(5);
    return byte;

    // //1.发出起始信号
    // I2C_Start();

    // //2.发送写地址(假写)
    // I2C_SendAddr(W_ADDR);


    // //4.发送内部地址
    // I2C_SendByte(innerAddr);

    
    // //6.发出起始信号
    // I2C_Start();

    // //7.发送读地址(真读)
    // I2C_SendAddr(R_ADDR);

    
    // //10.设置一个非应答信号
    // I2C_Nack();

    // //11.设置一个停止信号
    // I2C_Stop();
    
    // //9.读取一个字节
    // uint8_t byte = I2C_Read_Byte();//注意查看I2C主接收器的序列图
    
    // return byte;


}

//连续写入多个字节(页写)
void M24C02_WriteBytes(uint8_t innerAddr , uint8_t *bytes, uint8_t size)
{
    HAL_I2C_Mem_Write(&hi2c2,W_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,&bytes, size , 1000);

    HAL_Delay(5);//
//         //1.发出开始信号
//         I2C_Start();

//         //2.发送写地址
//         I2C_SendAddr(W_ADDR);
    
// //        //3.等待eeprom的应答
// //        uint8_t ack = I2C_Wait4Ack();
    

//         //4.发送内部地址
//         I2C_SendByte(innerAddr);

// //        //5.等待应答
// //        I2C_Wait4Ack();//这里可以优化,如果等不到应答设置超时,或者判断

//         //利用循环不停发送数据
//         for (uint8_t i = 0; i < size; i++)
//         {
//             //6.发送具体的数据
//             I2C_SendByte(bytes[i]);

// //            //7.等待应答
// //            I2C_Wait4Ack();
//         }               
//         //8.发出一个停止信号
//         I2C_Stop();
        
//         //延迟等待写周期结束,写入数据需要一个周期
//         delay_ms(5);//字节的写入和页写入都是5ms
}


//连续读取多个字节
void M24C02_ReadBytes(uint8_t innerAddr , uint8_t *buffer, uint8_t size)
{

    HAL_I2C_Mem_Read(&hi2c2,R_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,buffer, size , 1000);

//     //1.发出起始信号
//     I2C_Start();

//     //2.发送写地址(假写)
//     I2C_SendAddr(W_ADDR);

// //    //3.等待eeprom的应答
// //    I2C_Wait4Ack();

//     //4.发送内部地址
//     I2C_SendByte(innerAddr);

// //    //5.等待应答
// //    I2C_Wait4Ack();//这里可以优化,如果等不到应答设置超时,或者判断

//     //6.发出起始信号
//     I2C_Start();

//     //7.发送读地址(真读)
//     I2C_SendAddr(R_ADDR);

// //    //8.等待eeprom的应答
// //    I2C_Wait4Ack();

//     //利用循环连续读取多个字节
//     for (uint8_t i = 0; i < size; i++)
//     {
 

//         //10.设置一个非应答或非应答信号
//         if (i <(size -1))
//         {
//             I2C_Ack();
//         }
//         else{
//             I2C_Nack();
            
//                 //11.设置发出一个停止信号
//             I2C_Stop();
//         }
        
//        //9.读取一个字节
//         buffer[i] = I2C_Read_Byte();
    // }




}
