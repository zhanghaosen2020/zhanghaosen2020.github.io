#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"test.h"

//解决方式1:告诉编译器利用C语言的方式链接show函数(但是要注释掉头文件),该方法不太好
//#include"test.h"//test.h已经声明show函数了,注释掉,不让会重复
//extern "C" void show();

//extern "C"的主要用途:让C++调用C代码,(因为cpp中的函数重载特性,会导致函数被修饰,从而找不到c中的函数实现,导致链接错误)

//解决方式2:在.h文件中添加代码


void test01()
{
	show();//无法解析的外部命令,是在编译链接阶段出现的错误
	//你的show()函数是在.c下声明的,会导致cpp和c对同一函数的修饰不同,找不到对应的函数实现
}

int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
