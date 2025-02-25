#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//结构体	把一些单一类型组合在一起的做法

//描述一个学生
struct Stu
{
	//下面的是结构体的成员
	char name[20];
	int age;
	char sex[10];
	char tele[12];
};

//ps中存放的是结构体变量s1的地址
void print(struct Stu* ps)//结合下边，传入s1的地址给ps指针变量，s1是一个结构体类型变量
{
	//两种打印方式
	// *ps解析即 ps指针变量 所对应的变量类型struct Stu 变量s1   就是指代s1，注意括号不能省略
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);//

	//ps->,指的是ps所指向对象那个成员name
	//  结构体的指针变量 -> 成员名
	printf("%s %d %s %s\n", ps->name ,ps->age,ps->sex ,ps->tele);
}
int main()
{
	struct Stu s1 = {"zhangsan",24,"nan","123456789"};
	//结构体对象访问他里边的成员用的是 .操作符
	//结构体对象.成员名
	printf("%s %d %s %s\n", s1.name, s1.age, s1.sex, s1.tele);//打印类型要一一对应
	print(&s1);
	return 0;
}