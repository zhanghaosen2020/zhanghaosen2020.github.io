#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//����������������
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos == v.end())
	{
		cout << "û���ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���!!" << endl;
	}
}

//�����Զ�����������
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}


	// ���� operator==�����ڱȽ����� Person �����Ƿ����,find�ĵײ��õ� == �����Ƚ�
	bool operator==(const Person& p) const
	{
		return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person> v;
	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person pp("aaa", 10);
	vector<Person>::iterator pos = find(v.begin(), v.end(), pp);
	if (pos == v.end())
	{
		cout << "û�ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ���: " << "����: " << pos->m_Name << " ����: " << pos->m_Age << endl;
	}
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
