#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class NameType,class AgeType>
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
	Person<string, int>p1("Tom", 18);
	p1.showInfo();
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
