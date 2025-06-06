#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30




//类型的声明(因为该类型可能在 .c文件中使用)

//人的信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;//类型重命名

//通讯录
typedef struct Contact 
{
	PeoInfo data[MAX];//用来存放100个人的信息
	int count;//记录当前通讯录中实际人的个数
}Contact;

void InitContact(Contact* pc);//初始化通讯录

void AddContact(Contact* pc);//增加联系人到通讯录

void ShowContact(const Contact* pc);//打印通讯录中的信息

void DelContact(Contact* pc);//删除指定联系人

void SearchContact(Contact* pc);//查找指定联系人

void ModifyContact(Contact* pc);//修改指定联系人

void SortContact(Contact*pc);//排序联系人/按名字/年龄等等排序



