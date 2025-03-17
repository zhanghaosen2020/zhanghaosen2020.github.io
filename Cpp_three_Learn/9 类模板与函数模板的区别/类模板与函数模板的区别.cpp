#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//区别
//1. 类模板没有自动类型推导的使用方式
//2. 类模板在模板参数列表中可以有默认参数
template<class NameType , class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showInfo()
	{
		cout << "name = " << this->m_Name << " age = " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test01()
{
	//Person p1("悟空", 999);//错误,类模板没有自动类型推导

	Person<string, int>p2("悟空", 999);//类模板只能显示指定类型
	p2.showInfo();
}

//2. 类模板在模板参数列表中可以有默认参数
void test02()
{
	//声明时的参数列表已经指定了一个参数类型,如果你没有传递,就用默认的,传递了就用你传递的
	Person<string>p1("wuneng", 999);
	p1.showInfo();
}

int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
