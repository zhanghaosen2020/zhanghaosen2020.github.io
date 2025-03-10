#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person {
public:
	Person(int age)
	{
		cout << "这是Person构造函数的调用" << endl;
		this->m_Age = age;
	}
	void showAge()
	{
		cout << "年龄为: " << m_Age << endl;
	}
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
	int m_Age;
};

//智能指针类
class smartPointer {
public:
	smartPointer(Person*person)
	{
		cout << "智能指针的构造调用" << endl;
		m_Person = person;//相当于用smartPointer类的一个属性m_Person来维护new出的对象
	}

	// -> 的重载
	Person* operator->()
	{
		return m_Person;
	}
	//*
	//Person* operator*()
	//{
	//	return m_Person;
	//}
	Person& operator* ()
	{
		return *this->m_Person;
	}

	~smartPointer()
	{
		cout << "smart的析构函数调用" << endl;
		if (this->m_Person != NULL)
		{
			delete this->m_Person;
			this->m_Person = NULL;
		}
	}

	Person* m_Person;
};

void test01()
{
	//Person* p1 = new Person(18);
	//p1->showAge();
	//(*p1).showAge();
	//delete p1;

	//可以利用(分别体现在)智能(用smart这个类去维护 new出的Person)    指针(-> * 的重载) 托管new出来的对象,不用再写delete
	smartPointer sp(new Person(20));
	sp->showAge();//sp-> ->showPerson();编译器给你优化了;
	(*sp).showAge();//本质上是Person这个类才可用 . 运算符
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
