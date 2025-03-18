#pragma once
#include <iostream>
using namespace std;


template<class T1, class T2 >
class Person {
public:
	Person(T1 name, T2 age);
	void showPerson();

	T2 m_Age;
	T1 m_Name;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)//在类外实现的时候注意:1,作用域;2,注意将类模板函数的类外实现和普通类的类外实现区分开
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << endl;
}