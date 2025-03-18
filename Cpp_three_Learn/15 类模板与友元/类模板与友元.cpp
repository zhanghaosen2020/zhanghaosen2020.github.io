#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


template<class T1, class T2>
class Person {
	friend void printPerson(Person<T1,T2>&p)//建议直接使用全局函数类外实现
	{
		cout << "姓名: " << p.m_Name << "年龄: " << p.m_Age << endl;
	}
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "姓名: " << m_Name << " 年龄: " << m_Age << endl;
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
