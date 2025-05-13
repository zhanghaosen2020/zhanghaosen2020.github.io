#ifndef __I2C_H
#define __I2C_H

#include "stm32f407xx.h"
#include "./SYSTEM/delay/delay.h"//��Ϊ����,ʱ���ߺ������߶���Ҫ���߳���һ��ʱ�������

#include "./BSP/USART1/usart1.h"
#include <string.h>

//�궨��(Ϊ�˿ɶ���)
#define OK 0
#define FAIL 1

//��ʼ��
void I2C_Init(void);

//������ʼ�ź�
uint8_t I2C_Start(void);

//���÷���ֹͣ�ź�
void I2C_Stop(void);

//��������ʹ��Ӧ���ź�
void I2C_Ack(void);

//��������ʹ�ܷ�Ӧ���ź�
void I2C_Nack(void);

//�����豸��ַ���ȴ�Ӧ��
uint8_t I2C_SendAddr(uint8_t addr);

//��������һ���ֽ�����(д��,��eepromд��),���ҵȴ�Ӧ��
uint8_t I2C_SendByte(uint8_t byte);

//������EEPROM����һ���ֽڵ�����(��ȡ)
uint8_t I2C_Read_Byte(void);
#endif
