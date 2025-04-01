#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//查找内置数据类型
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
		cout << "没有找到" << endl;
	}
	else
	{
		cout << "找到了!!" << endl;
	}
}

//查找自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}


	// 重载 operator==，用于比较两个 Person 对象是否相等,find的底层用的 == 号来比较
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
	//创建数据
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
		cout << "没找到!" << endl;
	}
	else
	{
		cout << "找到了: " << "姓名: " << pos->m_Name << " 年龄: " << pos->m_Age << endl;
	}
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
