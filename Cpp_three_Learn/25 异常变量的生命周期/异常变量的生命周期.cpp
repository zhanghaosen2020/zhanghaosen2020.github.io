#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//异常对象的生命周期

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
	//抛出:throw myException();		接收:	catch (myException e) 抛出异常的地方会调用拷贝构造函数,因为匿名对象会及时销毁,产生新的对象
	catch (myException e)
	{
		cout << "我的异常捕获" << endl;
	}
}


void func2()
{
	throw myException();

}

void test02()
{
	try
	{
		func2();
	}
	//抛出:throw myException();		接收:	catch (myException &e) 用引用来接受匿名对象,相当于给匿名对象取了别名,(不调用拷贝构造),将其生命周期延长了
	catch (myException &e)
	{
		cout << "我的异常捕获" << endl;
	}
}


void func3()
{
	throw &myException();//因为用的指针去接收对象,所以需要抛出匿名对象的地址

}

void test03()
{
	try
	{
		func3();
	}
	//抛出:throw myException();		接收:	catch (myException e) 抛出异常的地方会调用拷贝构造函数,因为匿名对象会及时销毁,产生新的对象
	catch (myException *e)
	{
		cout << "我的异常捕获" << endl;
	}
}

int main() {

	//test01();
	//test02();//推荐的方式
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
