#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		m_Age = age;
		m_Name = name;
	}
	string m_Name;
	int m_Age;

	//重载关系运算符 == 号
	bool operator==(Person& p) 
	{
		if ((this->m_Name == p.m_Name) && (this->m_Age == p.m_Age))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
void test01()
{
	Person p1("Tom", 18);

	Person p2("Tom", 19);

	if (p1 == p2)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;

	}
	
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
