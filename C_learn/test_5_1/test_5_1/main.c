#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����һ����
//�ṹ�����͵�����
//struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];//
//	int high;
//}peo1, peo2;//peo1,peo2������ȫ�ֱ�������ʹ��struct Peo�ṹ���ʹ�����2������

struct Peo
{
	char name[20];
	char tele[12];
	char sex[5];//
	int high;
};
struct Peo p1, p2;//���ﴴ����Ҳ��ȫ�ֱ���

//�ṹ���Ƕ��
struct st
{
	struct Peo p;
	int num;
	float f;
};

void print2(struct Peo* p)
{
	//�ṹ��ָ�� -> ��Ա����
	//printf("%s %s %s %d\n", p->name, p->tele, p->sex, p->high);
	printf("%s %s %s %d\n", (*p).name, (*p).tele, p->sex, p->high);
}

void print1(struct Peo p)
{
	//�ṹ����� . ��Ա����
	printf("%s %s %s %d\n", p.name, p.tele, p.sex, p.high);
}

int main()
{
	//�ṹ�������ʼ��
	struct Peo p3 = { "����","123212212","��",181 };//�ֲ�����
	
	//Ƕ�׵Ľṹ��ĳ�ʼ������
	struct st s = { {"����","13328126612","Ů",161},100,3.14 };

	//��ӡ�����۲�
	printf("%s %s %s %d\n", p3.name, p3.tele, p3.sex, p3.high);
	printf("%s %s %s %d %d %.2f\n", s.p.name, s.p.tele, s.p.sex, s.p.high,s.num,s.f);

	print1(p3);
	print2(&p3);
	return 0;
}