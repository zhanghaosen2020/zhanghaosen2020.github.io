#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stddef.h>

//struct Point
//{
//	int n;
//	int ch;
//};
//struct Stu//全局变量
//{
//	//学生的相关属性(成员列表)
//	char name[20];
//	int age;
//	struct Point n;
//
//}s1, s2;//(s1，s2是利用这个结构体类型Stu创建的变量)
////s1，s2是全局变量
//
//struct //这里没有tag标签，属于匿名结构体类型，只能使用一次，在创建变量的同时使用
//{
//	char name[20];
//	int age;
//
//}s3;//之后不能再创建了
//
////1
//typedef struct Node {
//	int data;
//	struct Node* next;
//}* linklist;
////上下一样
////2
////struct Node {
////	int data;
////	struct Node* next;
////};
////typedef struct Node* linklist;
//
//int main()
//{
//	//结构体类型的定义
//
//	//学生
//	//struct Stu//局部变量
//	//{
//	//	//学生的相关属性(成员列表)
//	//	char name[20];
//	//	int age;
//	//};//(这里还可以写变量列表)
//	struct Stu s3;//在主函数里边声明的s3是局部变量
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
	char a : 3;//分配一个字节，a用了3个比特位

	char b : 4;//用a剩下的五个比特位，后剩下1个bit

	char c : 5;//这里再开辟一个字节，用这里的五个
	
	char d : 4;//再开辟一个字节

	//共开辟三字节
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