#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//从大到小，将三个输入整数，按照从大到小的顺序打印出来
//int main()//这样写代码太蠢了
//{
//	int a, b, c;
//	a = b = c = 0;
//
//	printf("请输入三个数据(中间用空格隔开):>");
//	scanf("%d %d %d", &a, &b, &c);
//
//		if ((a >= b) && (a >= c))
//		{
//			printf("%d ", a);
//			if (b >= c)
//			{
//				printf("%d %d\n", b,c);
//			}
//			else
//			{
//				printf("%d %d\n", c,b);
//			}
//		}
//		if ((b >= a) && (b >= c))
//		{
//			printf("%d ", b);
//			if (a >= c)
//			{
//				printf("%d %d\n", a, c);
//			}
//			else
//			{
//				printf("%d %d\n", c, a);
//			}
//		}
//		if ((c >= a) && (c >= b))
//		{
//			printf("%d ", c);
//			if (a >= b)
//			{
//				printf("%d %d\n", a, b);
//			}
//			else
//			{
//				printf("%d %d\n", b, a);
//			}
//		}
//	return 0;
//}

//int main()
//{
//
//	int a, b, c;
//	a = b = c = 0;
//	int tmp = 0;//这是一个交换变量
//	
//	printf("请输入三个数据(中间用空格隔开):>");
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}


//上边更进一步，把交换两个值的功能，写个函数，顺便复习，传址调用和传值调用
//交换两个值的函数
//void Swap(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//
//	int a, b, c;
//	a = b = c = 0;
//
//	printf("请输入三个数据(中间用空格隔开):>");
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//写一个代码打印1-100之间所有3的倍数
//int main()
//{ 
//	//产生1-100的数字
//	int i = 0;
//	//for (i = 1; i <= 100; i++)
//	//{
//	//	if (i % 3 == 0)
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//}
//	for (i = 3; i <= 100; i+=3)//这是一个简便的方式
//	{
//			printf("%d ", i);
//	}
//
//
//	return 0;
//}

//给定两个数，求两个数字的最大公约数
// 硬算
//int main()
//{
//	int a, b;
//	a = b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
// 
//	int min = (a < b) ?  a : b;//这个三目运算符还是好用
//	int m = min;
//	while (1)
//	{
//		if (a % m == 0 && b % m == 0)
//		{
//			printf("%d\n", m);
//			break;
//		}
//		m--;
//	}
//	//for (m = min; m > 1; m--)
//	//{
//	//	if ((a % m == 0) && (b % m == 0))
//	//	{
//	//		printf("%d\n",m);
//	//		break;
//	//	}				
//	//}		
//	//printf("%d ", b);
//	return 0;
//}

//int main()
//{
//	int a, b;
//	a = b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//
//	//这用辗转相除法
//	//先调整顺序
// 可以用三目运算符来计算，是十分高效的
//	if (a <= b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	//辗转
//	do
//	{
//		c = a % b;
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	while (c != 0);
//	printf("%d ", b);
//	return 0;
//}


//打印1000-2000之间的闰年
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//		{
//			printf("%d\t",i);
//		}
//	}
//	return 0;
//}
//
//#include<math.h>
////打印100-200之间的素数
//int main()
//{
//	产生100-200的数
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;//素数标志位，1为素数，0为非素数
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


//1-100的整数中9的个数
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100;i++)
//	{
//		//这样写会漏掉一部分
//		//if ((i / 9 == 0) || (i % 10 == 9))
//		//{
//		//	count++;
//		//}
//		//判断十位是不是9
//		if (i / 10 == 9)
//			count++;
//		//判断个位是不是9
//		if (i % 10 == 9)
//			count++;
//	}
//	printf("count = %d \n", count);
//	return 0;
//}


//计算1/1-1/2+1/3-1/4+...-1/100
//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 != 0)
//		{
//			sum += (1.0 / i);
//		}
//		else
//		{
//			sum -= (1.0 / i);
//		}
//	}
//	printf("%lf \n", sum);
//	return 0;
//}

//优化上边的代码(使其复杂度降低)
//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + flag * 1.0 / i;
//		flag = -flag;//这里相对于上边，for里边只用到了数值计算，上边还用到了判断，效率会低一些
//	}
//	printf("%lf \n", sum);
//	return 0;
//}

//找出十个数字中的最大值，并输出出来。
int main()
{
	int arr[] = { 10,20,1,19,100,101,22,4,2,200 };
	int i = 0;
	int max = 0;
	max = arr[0] < arr[1] ? arr[1] : arr[0];
	for (i = 0; i < 9; i++)
	{
		//max = arr[i] < arr[i + 1] ? arr[i + 1] : arr[i];	
		max = max > arr[i + 1] ? max : arr[i + 1];
	}
	printf("max = %d \n", max);
	return 0;
}