#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//函数的嵌套调用和链式访问
//函数不能嵌套定义
//int main()
//{
//	int len = strlen("abcdef");
//	printf("%d\n", len);
//	printf("%d\n", strlen("abcdefg"));//这一步实际上就链式访问
//
//	//经典链式访问
//
//	//Each of these functions returns the number of characters printed,
//	// or a negative value if an error occurs
//	printf("%d", printf("%d", printf("%d", 43)));
//
//	//结果为4321，内层先打印43，返回一个2，再打印一个2，再返回一个1
//
//	//链式访问的前提是，函数有返回值
//	//函数不写返回值的时候，默认返回类型是int
//	return 0;
//}

//函数的声明和定义
//
//int Add(int, int);//这里有了提前声明，就会让编译器提前知道有这么个函数，只是定义在后边而已
#include "add.h"// ""调用自己写的头文件，这句话就相当于声明了，把add.h中的内容填入其中
#include "sub.h"

//导入静态库的方法
//#pragma comment(lib,"add.lib")

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("请输入两个整数，中间以空格隔开:>");
	scanf("%d %d",&num1,&num2);

	int sum = Add(num1, num2);
	printf("%d\n", sum);

	sum = Sub(num1, num2);
	printf("%d\n", sum);

	return 0;
}



