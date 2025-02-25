#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//C的标准主函数写法

//快捷运行代码 ctrl+f5+fn
 
//标准输入输出函数stdio

//main函数是程序的入口(有且唯一)
//int main()
//{
//	printf("hello c world!\n");
//	printf("hello c world!\n");
//	printf("hello c world!\n");
//	printf("hello c world!\n");
//
//	return 0;
//}

//int main()
//{
//	printf("%zu\n",sizeof(char));//用%zu来代替%d表示返回一个无符号的sizeof的函数返回值
//	printf("%zu\n", sizeof(short));
//	printf("%zu\n", sizeof(int));
//	printf("%zu\n", sizeof(long));
//	printf("%zu\n", sizeof(long long));
//	printf("%zu\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//
//
//	return 0;
//}

//int main()
//{
//	int age = 24;//数据类型可以向内存空间申请一部分空间，来存放各种类型的空间
//	double price = 666.6;//类型用来创建变量，创建变量的本质是向内存申请空间
//	return 0;
//}


//1、变量（年龄、体重）和常量（pi）介绍
//2、变量分为局部（大括号内部定义）和全局变量（大括号内部定义）两类
//3、定义一个局部和全局变量相同的变量名（可以,但是不建议名字一样）时，局部优先调用原则

//int b = 20;//全局变量
//
//int main()
//{
//	short age = 24;//年龄
//	int high = 100;//身高
//	float weight = 88.5;//体重
//	int b = 1;
//	printf("b = %d\n",b);
//}


//计算两个整数的和
//int main()
//{
//	int num1 = 0;//要对变量初始化，否则会存有垃圾值
//	int num2 = 0;
//
//	//输入2个整数
//	scanf("%d %d", &num1, &num2);
//	//求和
//	int sum = num1 + num2;
//	//输出
//	printf("sum = %d\n",sum);
//
//	return 0;
//}


//变量的作用域（一个变量可以在那些地方使用，那些地方就是他的作用域）:1、局部变量   2、全部变量
//变量生命周期：1、局部变量

//int a = 10;//全局变量作用域是整个工程
//void test()
//{
//	printf("test-->%d\n", a);
//}
//int main()
//{		//int a = 10;//（此处作为变量比下边的局部变量范围更大，花括号的层级决定作用范围）
//	test();
//
//	{
//		//int a = 10;//(此处作为局部变量使用，同一个花括号里边可以调用该值)
//		printf("a = %d\n",a);
//	}
//	printf("a = %d\n", a);
//	return 0;
//}
 



//1.字面常量 3  3.14  'a'等等
//2.const修饰的常变量
//3.define定义的标识符常量
//4.枚举常量
//int main()
//{
//	const int a = 20;//const修饰的a本质是变量，但不能被修改，有常量的属性。
////	int arr[a] = {10};//此处数组中需要填一个常量，但是填a，却不对，证明本质是变量
//	return 0;
//}
//
//#define MAX 100
//#define STR "abcdef"
//
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	printf("%d\n",a);
//	printf("%s\n", STR);
//	return 0;
//}

//枚举常量
enum Color
{
	//枚举常量
	RED,
	GREEN,
	BLUE
};

enum Sex
{
	MALE,
	FEMALE,
	SECRET
};
int main()
{
	
	//三原色 green red blue
	enum Color c = RED;
	//RED = 20;//错误的，枚举类型不能如此
	return 0;
}

