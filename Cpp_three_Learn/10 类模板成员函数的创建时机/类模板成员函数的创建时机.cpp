#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1 {
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2 {
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;
	
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	MyClass<Person1>m;
	m.func1();
	//m.func2();//func2()����Person1�ĳ�Ա,���ϱ��Ѿ���ʽָ���˲����б�ΪPerson1,��T�ᱻ�Ƶ�ΪPerson1
	//Ҳ����˵���������òŻ�ȥ������Ա����(������ģ���Ա�����Ĵ�����˵)
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
