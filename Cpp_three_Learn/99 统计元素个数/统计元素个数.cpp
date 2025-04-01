#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//内置数据类型
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);

	cout << "元素4重复的次数为:" << num << endl;
}


//自定义数据类型

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person& p)//重载该函数很重要
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//bool operator==(const Person& p)//调用底层代码时,需要加const,以防你小子修改了p的相关值
	//{
	//	if (this->m_Name == p.m_Name)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	string m_Name;
	int m_Age;
};

class Greater
{
public:
	bool operator()(const Person& p)
	{
		if (p.m_Age > 20)
		{
			return true;
		}
	}
};
void test02()
{
	vector<Person> v;
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//统计和诸葛亮年龄相同的人的个数
	Person p("诸葛亮", 35);
	int num = count(v.begin(), v.end(), p);
	cout << "num =  " << num << endl;

	//统计年龄大于20的人数
	int num1 = count_if(v.begin(), v.end(), Greater());
	cout << "num1 =  " << num1 << endl;

}

int main() {
	
	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}
