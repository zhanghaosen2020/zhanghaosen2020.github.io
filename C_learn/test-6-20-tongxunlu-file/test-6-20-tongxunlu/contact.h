#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<stdlib.h>

#define DEFAULT_SZ 3
#define INC_SZ 2
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30




//���͵�����(��Ϊ�����Ϳ����� .c�ļ���ʹ��)

//�˵���Ϣ
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;//����������

//ͨѶ¼
//��̬�汾
//typedef struct Contact 
//{
//	PeoInfo data[MAX];//�������100���˵���Ϣ
//	int count;//��¼��ǰͨѶ¼��ʵ���˵ĸ���
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo* data;//����˵���Ϣ
	int count;//��¼��ǰͨѶ¼��ʵ���˵ĸ���
	//��ǰͨѶ¼������
	int capacity;
}Contact;

int InitContact(Contact* pc);//��ʼ��ͨѶ¼

void AddContact(Contact* pc);//������ϵ�˵�ͨѶ¼

void ShowContact(const Contact* pc);//��ӡͨѶ¼�е���Ϣ

void DelContact(Contact* pc);//ɾ��ָ����ϵ��

void SearchContact(Contact* pc);//����ָ����ϵ��

void ModifyContact(Contact* pc);//�޸�ָ����ϵ��

void SortContact(Contact*pc);//������ϵ��/������/����ȵ�����

void DestroyContact(Contact*pc);//����ͨѶ¼(�����ڴ�)

void SaveContact(const Contact*pc);//����ͨѶ¼���ļ�

void LoadContact(Contact*pc);//�����ļ�����Ϣ��ͨѶ¼



