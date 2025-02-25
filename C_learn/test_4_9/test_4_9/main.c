#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//常见操作符的学习及使用

//int main()
//{
//	// /除号的两端都是整数时，执行的是整数除法，有一个为浮点数，执行的是浮点数的除法
//	int a = 7 / 2;
//	float c = 7 / 2.0 ;
//	int b = 7 % 2;//取模余数   取模操作符的两端只能是整数
//	printf("%d\n", a);
//	printf("%.1f\n", c);//printf("%.2f\n", c);  %.2f意思为保留小数点后2位小数
//	printf("%d\n", b);
//
//	return 0;
//}

//int main()
//{
//	//sizeof是一个单目操作符,用来统计操作数的类型长度
//	int a = 10;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof a );//和上边的效果一样，都是统计a所代表数据类型所占空间大小
//	printf("%d\n", sizeof(int));
//	//printf("%d\n", sizeof int);//错误写法，语法不支持
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));//结果为40，统计的是数组所占字节的大小
//	printf("%d\n", sizeof(arr[0]));//结果为4，统计的是数组第一个元素类型所占的大小
//	printf("%d\n", sizeof(arr) / sizeof(arr[0]));//结果为10，计算的是数组的元素个数
//
//	return 0;
//}

//  前后置--、++的介绍
//int main()
//{
//	int a = 10;
//	int b = a++;//后置++，规则：先使用，后++
//	//int b = a; a = a + 1
//	printf("%d\n", b);//10
//	printf("%d\n", a);//11
//
//	int c = 10;
//	int d = ++c;//此处是前置++，规则：先++，后使用
//	// a = a + 1; b = a;
//	printf("%d\n", c);//11
//	printf("%d\n", d);//11
//
//	//强制类型转换
//	//int f = 3.14;//字面浮点数，编译器会默认理解为double类型
//	int f = (int)3.14;//强制的将浮点数转化为整形int
//	printf("%d\n", f);
//	return 0;
//}

//int main()
//{
//	//int a = 10;
//	//if (a = 3)//这里if内的语句依然会被执行 = 是赋值语句  == 是判断语句
//	//{
//	//	printf("hehe\n");
//	//}
//	// && 逻辑 与 - 并且
//	// || 逻辑 或 - 或者
//	  
//	/*
//	条件操作符：exp1 ? exp2 :exp3   又称之为三目运算符，因为有三个操作数
//				 1真   算2	 不算3       
//				 1假   不算2  算3
//	*/
//	int a = 20;
//	int b = 10;
//	int r = a == b ? a : b;
//	printf("%d\n",r);
//
//	return 0;
//}

//int main()
//{
//	//逗号表达式就是逗号隔开的一串表达式，exp1，exp2,....
//	//会从左往右依次计算，整个表达式的值为最后一个表达式的结果
//	int a = 10;
//	int b = 20;
//	int c = 0;
//	int d = (c = a - 2, a = b + c, c - 3);
//	//       c = 8      a = 28     5--->d=5
//	printf("%d", d);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//    []在定义数组的时候不算操作符
//	//    []在访问数组元素是一个操作符
//	arr[2] = 20;//就是把数组arr的第三个元素赋值为20
//	// arr 和 2 就是 []操作符的操作数 这时候 【】中的数字可以是一个整形变量
//	return 0;
//
//	//函数调用操作符 () 例如  Add(2,3),中的括号就是函数调用操作符 ，Add,2,3都是（）的操作数；
//}


//	typedef类型重命名

//typedef unsigned int uint;
//// 换句话说就是用 uint 这个符号简化 unsigned int这个类型简化代码编写
//int main()
//{
//	unsigned int num1 = 0;
//	uint num2 = 0; //上边和下边的定义是一致的
//	return 0; 
//}


// static静态变量
//1、修饰局部变量
//2、修饰全局变量
//3、修饰函数

//1、修饰局部变量举例
/*void test()
{
	//局部变量a会被放入内存中的栈区，随局部作用域销毁而销毁
//	int a = 1;//当这里为int时，调用一次test函数，都会将a原来的地址重新赋值为1，再a++一次，a变为2，打印10个2
	static int a = 1;//静态变量会被放入内存中的静态区中，整个程序执行完毕，才会销毁
	a++;//static打印的结果是2 3 4 5 6 7 8 9 10 11
	printf("%d ", a);
}
int main()
{
	int i = 0;
	while (i < 10)
	{
		test();
		i++;
	}
	return 0;
}*/

//2、static修饰全局变量举例（是将全局变量的外部连接属性变为了内部连接属性  见add.c注释）
//要使用其他地方的变量要优先声明
/*extern int g_val;//声明外部变量
int main()
{
	printf("%d\n", g_val);
	return 0;
}*/

//static修饰函数举例
//extern Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}


//define定义标识符常量
#define NUM 100  //此时此刻 NUM就是100这个常量，数组中，赋值时，打印时都可以直接使用

//define定义宏（宏有参数）//宏其实是在替换
#define ADD(x,y) ((x)+(y))
//      ADD宏名、x和y宏参数，参数无类型    ((x)+(y))宏体
int main()
{
	printf("%d\n", NUM);
	int n = NUM;
	printf("%d\n", n);
	int arr[NUM] = { 0 };

	int a = 10;
	int b = 20;
	int c = ADD(a, b);//意思是ADD(a,b) 等价于 （（x）+（y））的运算值
	printf("%d", c);
	
	return 0;
}