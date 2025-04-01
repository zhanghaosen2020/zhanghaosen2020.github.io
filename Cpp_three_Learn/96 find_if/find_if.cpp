#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


//�����������Ͱ�����������
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());

	if (pos == v.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���:" << *pos << endl;
	}
}



//�Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}


	//// ���� operator==�����ڱȽ����� Person �����Ƿ����,find�ĵײ��õ� == �����Ƚ�
	//bool operator==(const Person& p) const
	//{
	//	return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	//}

	string m_Name;
	int m_Age;
};

class Greater20
{
public:
	bool operator()(Person&p)
	{
		return p.m_Age > 20;
	}
};
void test02()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//Ѱ�������Լ20������
	vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
	if(pos == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���:" << "����: " << pos->m_Age << endl;
	}
}



//���������ظ�Ԫ��
void test03()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end())
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���,�ظ�Ԫ��Ϊ:" << *pos << endl;
	}
}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
