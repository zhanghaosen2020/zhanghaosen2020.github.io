#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//���Ը�ϰ��д�Լ����쳣��
class MyOutOfRange :public exception
{
public:

	MyOutOfRange(const string errorinfo)
	{
		this->m_errorInfo = errorinfo;
	}

	MyOutOfRange(const char* errorinfo)
	{
		this->m_errorInfo = errorinfo;
	}
	~MyOutOfRange()
	{

	}

	virtual char const* what() const
	{
		return this->m_errorInfo.c_str();
	}
	string  m_errorInfo;
};


void func()
{
	throw MyOutOfRange("����Խ��");
}

void test01()
{
	try
	{
		func();
	}
	catch (exception& ex)
	{
		cout<<ex.what()<<endl;
	}

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
