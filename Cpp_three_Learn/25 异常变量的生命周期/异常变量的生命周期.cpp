#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�쳣��������������

class myException {
public:
	myException()
	{
		cout << "�쳣�Ĺ��캯��" << endl;
	}

	myException(const myException& e)
	{
		cout << "�쳣�Ŀ������캯��" << endl;
	}
	~myException()
	{
		cout << "�쳣����������" << endl;
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
		cout << "�ҵ��쳣����" << endl;
	}
}
int main() {

	test01();

	system("pause");
	return EXIT_SUCCESS;
}
