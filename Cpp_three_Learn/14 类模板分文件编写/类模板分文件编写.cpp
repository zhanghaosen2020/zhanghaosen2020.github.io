#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//#include"person.h"
#include"person.hpp"

//#include"person.cpp"//��˿��Խ������׶����Ӳ���������,��������ͨ�������ὫԴ��չʾ�����˿�


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
//Person<T1, T2>::Person(T1 name, T2 age)//������ʵ�ֵ�ʱ��ע��:1,������;2,ע�⽫��ģ�庯��������ʵ�ֺ���ͨ�������ʵ�����ֿ�
//{
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() {
//	cout << "����: " << this->m_Name << endl;
//}

void test01()
{
	Person<string, int>p("Tom", 18);
	p.showPerson();//�����ӻᵼ�³����޷��������ⲿ������������ĳ���
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
