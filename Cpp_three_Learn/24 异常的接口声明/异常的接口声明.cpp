#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常的接口声明//当小括号中没有写任何类型的时候,就代表不允许抛出任何异常	
void func()throw(int,double)//代表只允许抛出int类型的异常,在高版本的VS之中,是允许指定抛出异常的类型的,如若不满足所给定的类型,就会造成程序中断
{
	throw 3.14;
}

int main() {

	try
	{
		func();
	}
	catch (int)
	{
		cout << "int类型异常捕获" << endl;
	}
	catch (double)
	{
		cout << "double类型的异常捕获" << endl;
	}
	catch (...)
	{
		cout << "其他类型的异常捕获" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
