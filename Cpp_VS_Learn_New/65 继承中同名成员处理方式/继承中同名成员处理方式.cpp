#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//继承中同名成员处理
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	int m_A;

	void func()
	{
		cout << "Base of func调用" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)调用" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	int m_A;

	void func()
	{
		cout << "Son - func()调用" << endl;
	}
};

//同名成员属性
void test01()
{
	Son s;
	cout << "Son  of m_A = " << s.m_A << endl;
	//如果通过子类对象访问到父类中的同名成员,需要加作用域
	cout << "Base of m_A = " << s.Base::m_A << endl;
}

void test02()
{
	Son s;
	s.func();
	//和上边一样,子类对象想要访问父类中的同名成员,需要加作用域
	s.Base::func();


	//如果子类中出现和父类同名的成员函数,子类的同名函数会隐藏掉父类中所有同名成员函数
	//s.func(100);//错误
	//如果想访问到父类中被隐藏的成员函数,需要加作用域
	s.Base::func(100);

}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
