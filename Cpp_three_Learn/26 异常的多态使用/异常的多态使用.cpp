#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常的基类
class BaseException
{
public:
	virtual void printError() = 0;
};

//空指针异常
class NULLPointer :public BaseException
{
public:
	virtual void printError()
	{
		cout << "空指针异常" << endl;
	}
};

//越界异常
class OUTOfRange :public BaseException
{
public:
	virtual void printError()
	{
		cout << "数组越界异常" << endl;
	}
};

void func1()
{
	throw NULLPointer();
}

void  test01()
{
	try
	{
		func1();
	}
	/*catch (NULLPointer& e)*/
	catch(BaseException &e)//这里用基类引用去接收子类对象,构成多态
	{
		e.printError();
	}
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
