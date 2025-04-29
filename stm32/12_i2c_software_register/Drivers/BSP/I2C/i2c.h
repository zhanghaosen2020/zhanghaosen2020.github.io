#ifndef __I2C_H
#define __I2C_H

#include "stm32f407xx.h"
#include "./SYSTEM/delay/delay.h"//��Ϊ����,ʱ���ߺ������߶���Ҫ���߳���һ��ʱ�������

//�궨��(Ϊ�˿ɶ���)
#define ACK 0
#define NACK 1

#define SCL_HIGHT (GPIOB->ODR |= GPIO_ODR_ODR_8)
#define SCL_LOW (GPIOB->ODR &= ~GPIO_ODR_ODR_8)
#define SDA_HIGHT (GPIOB->ODR |= GPIO_ODR_ODR_9)
#define SDA_LOW (GPIOB->ODR &= ~GPIO_ODR_ODR_9)//32����ʱ����/д����

//��ȡ����
#define READ_SDA (GPIOB->IDR & GPIO_IDR_IDR_9)

//�����������ʱ
#define I2C_DELAY delay_us(10);

//��ʼ��
void I2C_Init(void);

//������ʼ�ź�
void I2C_Start(void);

//����ֹͣ�ź�
void I2C_Stop(void);

//��������Ӧ���ź�
void I2C_Ack(void);

//����������Ӧ���ź�
void I2C_Nack(void);

//�����ȴ����豸����Ӧ���ź�
uint8_t I2C_Wait4Ack(void);

//��������һ���ֽ�����(д��,��eepromд��)
void I2C_SendByte(uint8_t byte);

//������EEPROM����һ���ֽڵ�����(��ȡ)
uint8_t I2C_Read_Byte(void);
#endif
