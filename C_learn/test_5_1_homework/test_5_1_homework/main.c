#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//写一个函数返回二进制参数中1的个数

//法1、位操作符来判断
//int Count(int n)
//{
//	int count = 0;//统计1的个数
//	int i = 0;//循环变量
//	for (i = 0; i < 32; i++)
//	{
//	//	if((n>>i)&1 == 1)//效果同下
//		if ((n & (1 << i)) != 0)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//法2、取出每一位来判断
//缺点是，当计算负数的二进制1的个数时，会出错

//int Count(int n)
//改进版本
//int Count(unsigned int n)
//{
//	int count = 0;//统计1的个数
//	while (n / 2 != 0)//这里的判断条件写的有问题，总会漏统计一位
//	while(n)//当n为0之后，n的二进制位就不可能有1了
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}

//法3、十分NB的一种算法
//int Count(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);//应当细细琢磨这里边的门道//Google面试题目
//		count++;
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int count = Count(num);
//	printf("%d\n", count);
//
//
//	return 0;
//}


//计算俩整数的二进制数对应位的不同个数  (但是函数的模块化做的不好，该让这个模块直接接收两个数，就能比较出不同的二进制位数才好)
// 借助上一题来解决此题目
//int Count(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);//应当细细琢磨这里边的门道//Google面试题目
//		count++;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n,&m);
//	int count = Count(n^m);
//	printf("%d\n", count);
//	return 0;
//}
// 
//取出每一位，然后一一比较也是一种解决方法
//int Count_Diff_Bit(int m, int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((m & (1 << i)) != (n & (1 << i))))
//		{
//			count++;
//
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int count = Count_Diff_Bit(m, n);
//	printf("%d\n", count);
//	return 0;
//}

//打印一个二进制位的奇数位和偶数位
int main()
{
	//输入
	int num = 0;
	scanf("%d", &num);

	//获取奇数位
	int i = 0;
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	printf("\n");
	//获取偶数位
	for (i = 32; i >= 2; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	//此处让我弄清楚了，(num>>i)和(num<<i)这两种方式取出每一位的方法是不同的，前者取出的就是1或0后者并不是

	return 0;
}