#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//编写自己的一个异常类,拓展一些自己的功能
//我的异常类-->对底层进行扩展     (这节课干货太多了)
class MyOutOfRange :public exception
{
public:
	MyOutOfRange(const char* errInfo)
	{
		this->m_errInfo = errInfo;//cpp中允许const char*隐式转换为string类型,所以这里可以直接接受
	}
	MyOutOfRange(string& errInfo)
	{

		this->m_errInfo = errInfo;
	}
	virtual char const* what() const //重写该底层的函数时,什么都是不能改变的(返回值,常函数标志等)
	{
	//但是cpp中不允许string类型隐士转化为const char*的原始类型的,需要调用函数
//std::string 不能隐式转换为 const char* , std::string 是一个类，而const char* 是一个原始指针类型。
//从std::string到const char* 的转换是不安全的，因为std::string内部的实现细节（如动态内存分配）不能直接暴露为一个
//简单的指针。因此，C++标准库不允许std::string隐式转换为const char* 。如果需要将std::string转换为const char* ，
//必须显式地调用std::string的c_str()或data()成员函数。
		return this->m_errInfo.c_str();
	}

	string  m_errInfo;//记录错误信息
};

class Person
{
public:
	Person(int age)
	{
		if (age > 100 || age < 0)
		{
			//throw out_of_range("超出年龄范围!");
			throw MyOutOfRange("我的异常,年龄大于0~150之间");
		}
		else
		{
			this->m_Age = age;
		}
	}

	int m_Age;
};

void test01()
{
	try {
		Person(1000);
	}
	//所有标准异常的父类对象都是exception
	catch (exception& e)//这里一定要记住,(用多态)就需要用父类的引用去接子类对象
	{
		cout << e.what() << endl;//用e.what()去输出对应的错误提示信息
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
