#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>

class Person
{
public:
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

void printList(list<Person>&l)
{
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名: " << it->m_Name << "  年龄: " << it->m_Age << "  身高: " << it->m_Height << endl;
	}
}
bool compare(Person&p1,Person&p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;//年龄相同,按照身高做降序排列
	}
	else
	{
		return p1.m_Age<p2.m_Age;

	}
}

void test01()
{
	list<Person>L;
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	cout << "排序前:" << endl;
	printList(L);
	cout << "排序后:" << endl;


	L.sort(compare);
	printList(L);

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
