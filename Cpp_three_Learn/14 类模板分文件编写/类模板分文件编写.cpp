#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//#include"person.h"
#include"person.hpp"

//#include"person.cpp"//如此可以解决编译阶段链接不到的问题,但是我们通常并不会将源码展示给别人看


//template<class T1, class T2 >
//class Person {
//public:
//	Person(T1 name, T2 age);
//	void showPerson();
//
//	T2 m_Age;
//	T1 m_Name;
//};



//template<class T1, class T2>
//Person<T1, T2>::Person(T1 name, T2 age)//在类外实现的时候注意:1,作用域;2,注意将类模板函数的类外实现和普通类的类外实现区分开
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	cout << "姓名: " << this->m_Name << endl;
//}

void test01()
{
	Person<string, int>p("Tom", 18);
	p.showPerson();//这样子会导致出现无法解析的外部命令这种问题的出现
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
