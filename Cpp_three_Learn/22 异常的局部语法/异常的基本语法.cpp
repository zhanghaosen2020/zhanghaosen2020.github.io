#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class myException
{
public:
	void printError()
	{
		cout << "我自己的异常" << endl;
	}
};
//异常的基本语法
int myDivision(int a, int b)
{
	if (b == 0)
	{
	//	return -1;//C语言返回值只有一个,无法区分(是除数为0,还是结果为-1),可能会出现二义性,其次没有一个统一的标志(有人返回0表示异常,每个人都不同)
		//throw - 1;//一般都是底层抛出
		//throw 3.14;
		//throw 'a';
		throw myException();//抛出一个myException的  匿名异常对象
	}
	return a / b;
}
void test01()
{
	int a = 10;
	int b = 0;

	//if (ret == -1)
	//{
	//	cout << "程序出现异常" << endl;
	//}
	
	//在可能出现异常的地方,写入到try代码块里
	try
	{
		int ret = myDivision(a, b);
	}
	catch (int)
	{
		cout << "int类型异常捕获" << endl;
	}
	catch (double)
	{
		throw;//cpp中的程序异常可以跳级处理,终归要处理,如若不处理就会导致程序崩溃
		cout << "double类型异常捕获" << endl;
	}
	catch (myException e)
	{
		e.printError();
	}
	catch (...)// ...代表除去int,double之外的其他类型的异常捕获
	{
		cout << "其他类型异常捕获" << endl;
	}
}


int main() {

	try {
		test01();
	}
	catch (double)
	{
		cout << "main函数中的double异常捕获" << endl;
	}
	//程序中没有任何地方处理异常,系统会自动调用terminate函数,使程序终止
	system("pause");
	return EXIT_SUCCESS;
}
