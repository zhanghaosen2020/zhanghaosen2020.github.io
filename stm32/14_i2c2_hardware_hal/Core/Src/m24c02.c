#include "m24c02.h"

//��ʼ��
void M24C02_Init(void)
{
    MX_I2C2_Init();
}

//��EEPROMд��һ���ֽ�
void M24C02_WriteByte(uint8_t innerAddr , uint8_t byte)
{
    HAL_I2C_Mem_Write(&hi2c2,W_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,&byte, 1 , 1000);

    HAL_Delay(5);//

    // //1.������ʼ�ź�
    // I2C_Start();

    // //2.����д��ַ
    // I2C_SendAddr(W_ADDR); //3.�ȴ�eeprom��Ӧ��

   
    // //4.�����ڲ���ַ
    // I2C_SendByte(innerAddr);


    // //6.���;��������
    // I2C_SendByte(byte);

    // //8.����һ��ֹͣ�ź�
    // I2C_Stop();
    
    // //�ӳٵȴ�д���ڽ���,д��������Ҫһ������
    // delay_ms(5);//
}

//��ȡEEPROM��һ���ֽ�
uint8_t M24C02_ReadByte(uint8_t innerAddr)
{
    uint8_t byte ;
    HAL_I2C_Mem_Read(&hi2c2,R_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,&byte, 1 , 1000);
    HAL_Delay(5);
    return byte;

    // //1.������ʼ�ź�
    // I2C_Start();

    // //2.����д��ַ(��д)
    // I2C_SendAddr(W_ADDR);


    // //4.�����ڲ���ַ
    // I2C_SendByte(innerAddr);

    
    // //6.������ʼ�ź�
    // I2C_Start();

    // //7.���Ͷ���ַ(���)
    // I2C_SendAddr(R_ADDR);

    
    // //10.����һ����Ӧ���ź�
    // I2C_Nack();

    // //11.����һ��ֹͣ�ź�
    // I2C_Stop();
    
    // //9.��ȡһ���ֽ�
    // uint8_t byte = I2C_Read_Byte();//ע��鿴I2C��������������ͼ
    
    // return byte;


}

//����д�����ֽ�(ҳд)
void M24C02_WriteBytes(uint8_t innerAddr , uint8_t *bytes, uint8_t size)
{
    HAL_I2C_Mem_Write(&hi2c2,W_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,&bytes, size , 1000);

    HAL_Delay(5);//
//         //1.������ʼ�ź�
//         I2C_Start();

//         //2.����д��ַ
//         I2C_SendAddr(W_ADDR);
    
// //        //3.�ȴ�eeprom��Ӧ��
// //        uint8_t ack = I2C_Wait4Ack();
    

//         //4.�����ڲ���ַ
//         I2C_SendByte(innerAddr);

// //        //5.�ȴ�Ӧ��
// //        I2C_Wait4Ack();//��������Ż�,����Ȳ���Ӧ�����ó�ʱ,�����ж�

//         //����ѭ����ͣ��������
//         for (uint8_t i = 0; i < size; i++)
//         {
//             //6.���;��������
//             I2C_SendByte(bytes[i]);

// //            //7.�ȴ�Ӧ��
// //            I2C_Wait4Ack();
//         }               
//         //8.����һ��ֹͣ�ź�
//         I2C_Stop();
        
//         //�ӳٵȴ�д���ڽ���,д��������Ҫһ������
//         delay_ms(5);//�ֽڵ�д���ҳд�붼��5ms
}


//������ȡ����ֽ�
void M24C02_ReadBytes(uint8_t innerAddr , uint8_t *buffer, uint8_t size)
{

    HAL_I2C_Mem_Read(&hi2c2,R_ADDR,innerAddr,I2C_MEMADD_SIZE_8BIT ,buffer, size , 1000);

//     //1.������ʼ�ź�
//     I2C_Start();

//     //2.����д��ַ(��д)
//     I2C_SendAddr(W_ADDR);

// //    //3.�ȴ�eeprom��Ӧ��
// //    I2C_Wait4Ack();

//     //4.�����ڲ���ַ
//     I2C_SendByte(innerAddr);

// //    //5.�ȴ�Ӧ��
// //    I2C_Wait4Ack();//��������Ż�,����Ȳ���Ӧ�����ó�ʱ,�����ж�

//     //6.������ʼ�ź�
//     I2C_Start();

//     //7.���Ͷ���ַ(���)
//     I2C_SendAddr(R_ADDR);

// //    //8.�ȴ�eeprom��Ӧ��
// //    I2C_Wait4Ack();

//     //����ѭ��������ȡ����ֽ�
//     for (uint8_t i = 0; i < size; i++)
//     {
 

//         //10.����һ����Ӧ����Ӧ���ź�
//         if (i <(size -1))
//         {
//             I2C_Ack();
//         }
//         else{
//             I2C_Nack();
            
//                 //11.���÷���һ��ֹͣ�ź�
//             I2C_Stop();
//         }
        
//        //9.��ȡһ���ֽ�
//         buffer[i] = I2C_Read_Byte();
    // }




}
