#ifndef __M24C02_H
#define __M24C02_H

#include "./BSP/I2C/i2c.h"//������Ѿ������˺ܶ�ͷ�ļ�

//�궨��
#define W_ADDR 0xA0
#define R_ADDR 0xA1

//��ʼ��
void M24C02_Init(void);

//��EEPROMд��һ���ֽ�
void M24C02_WriteByte(uint8_t innerAddr , uint8_t byte);

//��ȡEEPROM��һ���ֽ�
uint8_t M24C02_ReadByte(uint8_t innerAddr);

//����д�����ֽ�(ҳд)
void M24C02_WriteBytes(uint8_t innerAddr , uint8_t *bytes, uint8_t size);

//������ȡ����ֽ�
void M24C02_ReadBytes(uint8_t innerAddr , uint8_t *buffer, uint8_t size);

#endif
