#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;

	}
	int m_Age;
	string m_Name;
};

template<class T>
bool myCompare(T& p1, T& p2)
{
	if (p1 == p2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//具体化定义来解决自定义类型的通用化问题
template<>bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test01()
{
	int a = 10;
	int b = 11;
	cout << myCompare(a,b) << endl;//内置类型可以(使用通用的函数模板)比较

	Person p1("tom", 18);
	Person p2("tom", 18);
	//cout << myCompare(p1, p2) << endl;//自定义类型则不能

}

void test02()
{
	Person p1("tolm", 18);
	Person p2("tom", 18);
	cout << myCompare(p1, p2) << endl;//自定义类型则不能
}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
