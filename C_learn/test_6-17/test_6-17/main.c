#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>

//struct Point
//{
//	int n;
//	int ch;
//};
//struct Stu//ȫ�ֱ���
//{
//	//ѧ�����������(��Ա�б�)
//	char name[20];
//	int age;
//	struct Point n;
//
//}s1, s2;//(s1��s2����������ṹ������Stu�����ı���)
////s1��s2��ȫ�ֱ���
//
//struct //����û��tag��ǩ�����������ṹ�����ͣ�ֻ��ʹ��һ�Σ��ڴ���������ͬʱʹ��
//{
//	char name[20];
//	int age;
//
//}s3;//֮�����ٴ�����
//
////1
//typedef struct Node {
//	int data;
//	struct Node* next;
//}* linklist;
////����һ��
////2
////struct Node {
////	int data;
////	struct Node* next;
////};
////typedef struct Node* linklist;
//
//int main()
//{
//	//�ṹ�����͵Ķ���
//
//	//ѧ��
//	//struct Stu//�ֲ�����
//	//{
//	//	//ѧ�����������(��Ա�б�)
//	//	char name[20];
//	//	int age;
//	//};//(���ﻹ����д�����б�)
//	struct Stu s3;//�����������������s3�Ǿֲ�����
//	struct Stu s4 = { "zhanghaosen",20,{99,100} };
//	printf("%s %d %d %c",s4.name,s4.age,s4.n.n,s4.n.ch);
//	return 0;
//}

struct S1 {
	char c1;
	int i;
	char c2;
};

struct S2 {
	char c1;
	char c2;
	int i;
};

struct S3 {
	double d;
	char c;
	int i;
};

struct S4
{
	char c1;
	struct S3 s3;
	double d;
};
struct S
{
	char a : 3;//����һ���ֽڣ�a����3������λ

	char b : 4;//��aʣ�µ��������λ����ʣ��1��bit

	char c : 5;//�����ٿ���һ���ֽڣ�����������
	
	char d : 4;//�ٿ���һ���ֽ�

	//���������ֽ�
};
int main()
{
	printf("%u\n", sizeof(struct S1));
	printf("%u\n", offsetof(struct S1, c1));
	printf("%u\n", offsetof(struct S1, i));
	printf("%u\n", offsetof(struct S1, c2));
	printf("%u\n", sizeof(struct S2));
	printf("%u\n", offsetof(struct S2, c1));
	printf("%u\n", offsetof(struct S2, c2));
	printf("%u\n", offsetof(struct S2, i));
	printf("%u\n", sizeof(struct S3));
	printf("%u\n", offsetof(struct S3, d));
	printf("%u\n", offsetof(struct S3, c));
	printf("%u\n", offsetof(struct S3, i));

	return 0;
}