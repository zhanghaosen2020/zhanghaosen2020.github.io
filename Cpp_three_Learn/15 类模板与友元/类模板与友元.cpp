#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


template<class T1, class T2>
class Person {
	friend void printPerson(Person<T1,T2>&p)//����ֱ��ʹ��ȫ�ֺ�������ʵ��
	{
		cout << "����: " << p.m_Name << "����: " << p.m_Age << endl;
	}
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "����: " << m_Name << " ����: " << m_Age << endl;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

void test01()
{
	Person<string, int>p("Tom", 20);
	printPerson(p);
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
