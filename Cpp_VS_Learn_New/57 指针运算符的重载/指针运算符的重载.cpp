#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Person {
public:
	Person(int age)
	{
		cout << "����Person���캯���ĵ���" << endl;
		this->m_Age = age;
	}
	void showAge()
	{
		cout << "����Ϊ: " << m_Age << endl;
	}
	~Person()
	{
		cout << "Person���������ĵ���" << endl;
	}
	int m_Age;
};

//����ָ����
class smartPointer {
public:
	smartPointer(Person*person)
	{
		cout << "����ָ��Ĺ������" << endl;
		m_Person = person;//�൱����smartPointer���һ������m_Person��ά��new���Ķ���
	}

	// -> ������
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
		cout << "smart��������������" << endl;
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

	//��������(�ֱ�������)����(��smart�����ȥά�� new����Person)    ָ��(-> * ������) �й�new�����Ķ���,������дdelete
	smartPointer sp(new Person(20));
	sp->showAge();//sp-> ->showPerson();�����������Ż���;
	(*sp).showAge();//��������Person�����ſ��� . �����
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
