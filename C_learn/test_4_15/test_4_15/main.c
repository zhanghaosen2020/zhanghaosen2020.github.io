#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//接受一个整型值（无符号），按照顺序打印它的每一位。
//例如：
//输入：1234，输出 1 2 3 4
/*
void Print(unsigned int n)
{
	if (n > 9)
	{
		Print(n / 10);
		//n = n / 10;
		//Print(n);
	}
	printf("%u ",n%10);
}
int main()
{
	unsigned int num = 0;
	printf("请输入一个数字:>");
	scanf("%u", &num);
	//while (num)//输入1234 输出4 3 2 1并不是顺序输出
	//{
	//	printf("%u ", num % 10);//%u是指打印无符号整形
	//	num = num / 10;
	//}
	Print(num);//定义一个专门实现功能的打印函数
	return 0;
}
*/
#include<string.h>
//编写函数不允许创建临时变量，求字符串长度
//模拟实现strlen
// //上下两种定义方式
// unsigned int MyStrlen(char str[])//参数部分写入数组的形式
/*
unsigned int MyStrlen(char* str)  //参数部分写入指针的形式
{
	int count = 0;
	while(*str != '\0')
	{
		count += 1;
		str += 1;
	}
	return count;
}
*/

//用递归的方式来实现上述函数(可不创建临时变量)
//unsigned int MyStrlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + MyStrlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	//int len = (unsigned int)strlen("abc");//注意strlen的返回值是一个size_t无符号整型值，反应字符串长度
//	char arr[] = "abcdooo";
//	int len = MyStrlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//写一个n的阶乘函数，迭代实现

//int main()
//{	
//	//创建变量
//	int n = 0;
//	int sum = 1;
//	//输入
//	printf("请输入数字n:>");
//	scanf("%d", &n);
//
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("sum = %d", sum);
//	return 0;
//}

//下面用函数的形式来写N的阶乘
//factorial阶乘函数   n<=1 ret=0;n>1  ret = n * factorail(n-1)
//int Factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Factorial(n - 1);
//	}
//}
//int main()
//{
//	//输入
//	int n = 0;
//	printf("请输入数字n:>");
//	scanf("%d", &n);
//
//	//递归实现
//	int ret = Factorial(n);
//
//	//输出
//	printf("%d! = %d\n", n, ret);
//	return 0;
//}

//求第n个斐波那契数
//斐波那契1 1 2 3 5 8 13 21 34 55...

//有了公式之后 n!, Fabonacci(n)用递归都非常好求(但是时间用的非常多)

//递归(不是好的解法)
//int Fibonacci(int n)//时间复杂度很高（做了大量的重复计算）（n = 50的时候算很久）
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}

//迭代法来解（这样子时间复杂度降低了很多，有时候迭代比递归方便的多）
int Fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;

	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	//输入
	int n = 0;
	printf("请输入数字n:>");
	scanf("%d", &n);

	//计算
	int ret = Fibonacci(n);

	//打印
	printf("\nFabonacci(%d) = %d\n", n, ret);
}