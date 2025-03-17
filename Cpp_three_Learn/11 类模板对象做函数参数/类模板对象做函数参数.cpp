#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//类模板对象做函数参数的传递方式
//1. 指定传入的类型-- - 直接显示对象的数据类型
//2. 参数模板化-- - 将对象中的参数变为模板进行传递
//3. 整个类模板化-- - 将这个对象类型 模板化进行传递

template<class T1,class T2>
class Person {
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

	T1 m_Name;
	T2 m_Age;
};

//1,直接传入指定的类型(显示指定),这种方法用的最为广泛
void printPerson1(Person<string ,int>&p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int>p("悟空", 18);
	printPerson1(p);
}

//2,参数模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为: " << typeid(T1).name()<<endl ;
	cout << "T2的类型为: " << typeid(T2).name()<<endl ;

}
void test02()
{
	Person<string,int>p("八戒", 17);
	printPerson2(p);
}

//3,直接将整个类模板化
template<class T>
void printPerson3(T&p)
{
	p.showPerson();
	cout << "T的类型为: " << typeid(T).name() << endl;
}
void test03()
{
	Person<string, int>p("悟净", 16);
	printPerson3(p);
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
