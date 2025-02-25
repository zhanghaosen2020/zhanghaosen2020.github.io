#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//用指针的方式打印数组
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	printf("\n");
//	return 0;
//}

//void Print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	return 0;
//}

//逆序一个字符串
//void Reverse(char* p)
//{
//	int left = 0;
//	int right = 0 ;
//	while (*(p + right) != '\0')
//	{
//		right += 1;
//	}
//	while (left < right-1)
//	{
//		char tmp = '0';
//		tmp = *(p + left);
//		*(p + left) = *(p + right-1);
//		*(p + right-1) = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char str[10001] = {0};
//	/*scanf("%s", &str);*/
//	gets(str);//获取输入字符串的方式之一
//
//	Reverse(str);
//	printf("%s\n", str);
//
//	return 0;
//}


//#include<string.h>
//int main()
//{
//	char str[10001] = { 0 };
//	int left = 0;
//	int right = 0;
//	gets(str);
//	right = strlen(str) - 1;
//	while (left < right)
//	{
//		char tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s\n", str);
//	return 0;
//}

//计算求和 Sn = a + aa + aaa + aaaa + aaaaa
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a,&n);
//	
//	int sum = 0;
//	int k = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		k = k * 10 + a;//关键的拆分代码
//		sum += k;
//	}
//	printf("%d", sum);
//	return 0;
//}

//打印水仙花数
//这个题目重要的是分析问题，不要在循环内部改变循环变量，这样会导致死循环;
//#include<math.h>
//int main()
//{
//	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
//	int i;
//	for (i = 0; i <= 100000; i++)
//	{
//		//判断一个数是不是一个水仙花数
//		//1.判断i是个几位数-->n
//		int n = 1;//一个数至少为1位数
//		int tmp = i; //避免循环内部改变循环的值
//		int sum = 0;
//		while (tmp / 10)
//		{
//			n++;
//			tmp /= 10;
//		}
//		//2.计算出个数位的数字及n次方
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}
//#include<math.h>
//int Narcissistic_number(int i)//判断水仙花数的函数封装
//{
//	//判断一个数是不是一个水仙花数
//		//1.判断i是个几位数-->n
//	int n = 1;//一个数至少为1位数
//	int tmp = i; //避免循环内部改变循环的值
//	int sum = 0;
//	while (tmp / 10)
//	{
//		n++;
//		tmp /= 10;
//	}
//	//2.计算出个数位的数字及n次方
//	tmp = i;
//	while (tmp)
//	{
//		sum += pow(tmp % 10, n);
//		tmp /= 10;
//	}
//	if (sum == i)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int i;
//	for (i = 0; i <= 100000; i++)
//	{
//		if (Narcissistic_number(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//打印菱形
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//打印空格
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//打印*号
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	//打印下边
//	for (i = 0; i < line - 1; i++)
//	{
//		//打印空格
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//		//打印 * 号
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)//这一步比较难
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//
//}

//喝汽水问题，一元一瓶汽水，两个空瓶换1瓶汽水，20元可以喝多少汽水
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);

	total = money;
	empty = money;


	//置换
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;//空瓶数为，换的汽水，加剩下的单个汽水瓶子
	}

	printf("%d",total);
	return 0;
}
