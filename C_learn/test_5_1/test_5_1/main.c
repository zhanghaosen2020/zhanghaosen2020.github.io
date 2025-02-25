#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//描述一个人
//结构体类型的声明
//struct Peo
//{
//	char name[20];
//	char tele[12];
//	char sex[5];//
//	int high;
//}peo1, peo2;//peo1,peo2（且是全局变量）是使用struct Peo结构类型创建的2个变量

struct Peo
{
	char name[20];
	char tele[12];
	char sex[5];//
	int high;
};
struct Peo p1, p2;//这里创建的也是全局变量

//结构体的嵌套
struct st
{
	struct Peo p;
	int num;
	float f;
};

void print2(struct Peo* p)
{
	//结构体指针 -> 成员变量
	//printf("%s %s %s %d\n", p->name, p->tele, p->sex, p->high);
	printf("%s %s %s %d\n", (*p).name, (*p).tele, p->sex, p->high);
}

void print1(struct Peo p)
{
	//结构体变量 . 成员变量
	printf("%s %s %s %d\n", p.name, p.tele, p.sex, p.high);
}

int main()
{
	//结构体变量初始化
	struct Peo p3 = { "张三","123212212","男",181 };//局部变量
	
	//嵌套的结构体的初始化方法
	struct st s = { {"李四","13328126612","女",161},100,3.14 };

	//打印出来观察
	printf("%s %s %s %d\n", p3.name, p3.tele, p3.sex, p3.high);
	printf("%s %s %s %d %d %.2f\n", s.p.name, s.p.tele, s.p.sex, s.p.high,s.num,s.f);

	print1(p3);
	print2(&p3);
	return 0;
}