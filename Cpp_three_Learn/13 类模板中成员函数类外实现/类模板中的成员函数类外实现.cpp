#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//类模板中的成员函数类外实现
template<class T1,class T2 >
class Person {
public:
	Person(T1 name ,T2 age);
	void showPerson();

	T2 m_Age;
	T1 m_Name;
};



template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)//在类外实现的时候注意:1,作用域;2,注意将类模板函数的类外实现和普通类的类外实现区分开
{
	this->m_Name = name;
	this->m_Age = age;
}

//void showPerson();//注意观察类外实现类模板成员函数究竟多加了哪些东西呢?
//1,作用域;2,类模板,3,模板参数列表
template<class T1, class T2>
void Person<T1, T2>:: showPerson() {
	cout << "姓名: " << this->m_Name << endl;
}

void test01()
{
	Person<string, int >p("八戒", 18);
	p.showPerson();
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
