#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


//内置数据类型按照条件查找
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
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了:" << *pos << endl;
	}
}



//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}


	//// 重载 operator==，用于比较两个 Person 对象是否相等,find的底层用的 == 号来比较
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

	//寻找年龄大约20的数据
	vector<Person>::iterator pos = find_if(v.begin(), v.end(), Greater20());
	if(pos == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了:" << "年龄: " << pos->m_Age << endl;
	}
}



//查找相邻重复元素
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
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了,重复元素为:" << *pos << endl;
	}
}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
