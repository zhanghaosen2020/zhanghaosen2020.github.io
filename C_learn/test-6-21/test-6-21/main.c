#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//enum Day
//{
//	Mon,//0
//	Tues,//1
//	Wed,//2
//	Thur,//3
//	Fir,//4
//	Sat,//5
//	Sun//6
//	//默认的可能取值是从0到后
//};
//
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//
//int Check_sys()//这方法太过巧妙
//{
//	union Un
//	{
//		int a;
//		char c;
//	}u;
//	u.a = 1;
//	return u.c;//这个思路和上边的方法本质上一样
//	//返回1就是小端，返回0就是大端
//
//}
//
//
//int main()
//{
//	//union Un u;
//	//printf("%u\n", sizeof(u));//4
//
//	//判断计算机的存储是大端存储还是小端存储
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端存储");
//	}
//	else
//	{
//		printf("大端存储");
//	}
//
//	union Un2
//	{
//		short c[7];
//		int i;
//	};
//	//下面输出的结果是什么？
//	//printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	return 0;
//}

#include<string.h>
#include<errno.h>
#include<stdlib.h>
//int main()
//{
//
//	//动态内存开辟
//	//malloc的返回值一定要进行一个有效性的判断，否则造成野指针
//	int* p = (int*)malloc(40);//向内存空间申请40字节空间，并以int*的方式读取接收
//	if (p == NULL)//这里是确保申请的内存空间是成功的
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//如若打印错误信息就终止程序，主函数里给一个异常返回值1
//	}
//	//使用刚刚开辟的空间
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	free(p);//这里把内存指向的空间归还了，但是p仍然包含那块空间的地址
//	//所以需要手动释放
//	p = NULL;//将p置空，让它失忆
//
//	//开辟10个整型的空间
//	int* ptr = calloc(10, sizeof(int));
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//打印
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%d\n", *(ptr+i));
//		printf("%d ", ptr[i]);
//		
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//使用，将这块空间调整为1，2，3，4，...10
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	//空间不够用了
	int*ptr = (int*)realloc(p, 80);
	if (ptr != NULL)
	{
		p = ptr;
		ptr = NULL;//这一步不可缺少哦，若后边p被释放掉了，还能通过ptr找到之前的空间，存在危险
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;
	return 0;
}