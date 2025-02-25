#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//1.写一个函数，判断一个数是不是素数

//在解决问题 1 之前，先打印出100-200之间的素数
/*
int main()
{
	int i = 0;//i,j控制循环变量
	int j = 0;
	int count = 0;//统计素数的个数
	
	for (i = 100; i <= 200; i++)//优化一，i=101，i+2从奇数中找素数，从源头减小目标
	{
		int flag = 1;//素数标志位：1-->为素数，0-->非素数
		for (j = 2; j <= i - 1; j++)//j<=sqrt(i),减小循环次数()
		{
			if (i % j == 0)
			{
				flag = 0;
				break;//一旦整除了，便跳出循环判断为非素数，标志位也改变
			}
		}
		if (flag == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n素数个数为：%d\n", count);//通过格式控制符随心输出，想要的格式
	return 0;
}
*/

//接着解决问题1
//判断数是否为素数

//void PrimeNum(int x)//这里涉及到一个函数命名规则的问题（）
//{
//	int i = 0;//控制循环变量（为使其产生2 - i-1个因数）
//	int flag = 1;//素数标志位，1为素，0为非素。
//	for (i = 2; i <= x - 1; i++)
//	{
//		if (x % i == 0)
//		{
//			flag = 0;//此时说明该数x为非素数
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("num = %d 非素数", x);
//	}
//	else
//	{
//		printf("num = %d 为素数", x);
//	}
//}
//
//int main()
//{
//	//输入数字
//	int num = 0;
//	printf("请输入一个数:>");
//	scanf("%d", &num);
//
//	//判断是否为素数
//	PrimeNum(num);
//
//	return 0;
//}

//优化上边代码

int IsPrime(int x)
{
	int j = 0;
	for (j = 2; j <= sqrt(x); j++)//这里是小于等于sqrt(x),才对否则会漏掉121，169这两个数
	{
		if (x % j == 0)
		{
			return 0;//return 0;直接结束这个函数，下结论，而用break的话，没有那么好，简洁。
		}
	}
		return 1;
}
int main()
{
	int i = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		if (IsPrime(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n素数个数为:>%d\n", count);
	return 0;
}