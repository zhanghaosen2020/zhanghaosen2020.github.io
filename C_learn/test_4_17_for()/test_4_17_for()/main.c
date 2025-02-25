#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//找出十个数字中的最大值，并输出出来。
//int main()
//{
//	int arr[] = { 10,20,1,19,100,101,22,4,2,200 };
//	int i = 0;
//	int max = 0;
//	max = arr[0] < arr[1] ? arr[1] : arr[0];
//	for (i = 0; i < 9; i++)
//	{
//		//max = arr[i] < arr[i + 1] ? arr[i + 1] : arr[i];	
//		max = max > arr[i + 1] ? max : arr[i + 1];
//	}
//	printf("max = %d \n", max);
//	return 0;
//}


//输出九九乘法表
int main()
{
	int i, j;
	i = j = 1;
	for (i = 1; i <= 9; i++)//打印九行
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %-2d  ", i, j, i * j);//%2d是右对齐，%-2d是左对齐
		}
		printf("\n");
	}
	return 0;
}


//交换两个函数值的函数
//void Swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a, b;
//	a = b = 0;
//	printf("请输入两个数字:>");
//	scanf("%d %d", &a, &b);
//
//	Swap(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}