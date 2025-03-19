#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//异常变量的生命周期

class myException {
public:
	myException()
	{
		cout << "异常的构造函数" << endl;
	}

	myException(const myException& e)
	{
		cout << "异常的拷贝构造函数" << endl;
	}
	~myException()
	{
		cout << "异常的析构函数" << endl;
	}
};

void func1()
{
	throw myException();
		 
}

void test01()
{
	try
	{
		func1();
	}
	catch (myException e)
	{
		cout << "我的异常捕获" << endl;
	}
}
int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}
