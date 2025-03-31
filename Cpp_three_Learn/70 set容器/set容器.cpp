#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<set> 

void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout <<endl;
}

//构造：
//set<T> st; //默认构造函数：
//set(const set& st); //拷贝构造函数
//赋值：set& operator=(const set& st); //重载等号操作符
void test01()
{
	set<int>s1;//默认构造

	//set容器插入数据用insert
	s1.insert(10);
	s1.insert(5);
	s1.insert(1);
	s1.insert(4);
	s1.insert(9);
	//s1.insert(4);//插入重复的数据,不报错,但是会插入失败

	printSet(s1);

	set<int>s2(s1);//拷贝构造函数
	printSet(s2);

	set<int>s3;
	s3 = s2;//重载赋值符
	printSet(s3);
}

//size(); //返回容器中元素的数目
//empty(); //判断容器是否为空
//swap(st); //交换两个集合容器

void test02()
{
	set<int>s1;//默认构造

	//set容器插入数据用insert
	s1.insert(10);
	s1.insert(5);
	s1.insert(1);
	s1.insert(4);
	s1.insert(9);
	if (s1.empty())
	{
		cout << "set容器内为空" << endl;
	}
	else
	{
		cout << "set容器内不为空" << endl;
		cout << "set容器的容量大小为:" << s1.size() << endl;
	}
	printSet(s1);

	set<int>s2;//默认构造

	//set容器插入数据用insert
	s2.insert(77);
	s2.insert(2);
	s2.insert(22);
	s2.insert(10);
	s2.insert(1);
	printSet(s2);
	
	//交换后
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(22);
	printSet(s1);
}

//set 和 multiset的区别,前者无法插入重复数据,后者可以
void test03()
{
	/*set插入数据的同时会返回插入结果，表示插入是否成功,multiset不会检测数据，因此可以插入重复数据*/
	set<int >s;
	s.insert(10);
	pair<set<int>::iterator ,bool> ret  = s.insert(10);//插入时会返回对个队组来说明插入到那个位置(参数一),插入是否成功(参数二)
	if (ret.second)
	{
		cout << "插入成功" << endl;
	}
	else
	{
		cout << "插入失败" << endl;

	}

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(9);
	ms.insert(1);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//pair对组创建,功能描述：成对出现的数据，利用对组可以返回两个数据,c++中如果你想返回两个数据,就可以用对组
//pair<type, type> p(value1, value2);
//pair<type, type> p = make_pair(value1, value2);

void test04()
{
	pair<string, int>p("Jack", 100);//方式一
	cout << "姓名: " << p.first << "  年龄: " << p.second << endl;

	pair<string, int>p1 = make_pair("嘻嘻", 100);//方式二
	cout << "姓名: " << p1.first << "  年龄: " << p1.second << endl;

}


//set存放内置数据类型,排序函数
class MyCompare
{
public:
	bool operator()(int val1, int val2) const//仿函数,这里的const很重要!!
	{
		return val1 > val2;
	}
};
void test05()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(5);
	s1.insert(1);
	s1.insert(4);
	s1.insert(9);
	printSet(s1);//默认升序,我们如何指定排序规则呢
	//要按降序排列
	set<int,MyCompare>s2 ;
	s2.insert(10);
	s2.insert(5);
	s2.insert(1);
	s2.insert(4);
	s2.insert(9);
	//printSet(s2);错误,每个容器都有自己的专属迭代器
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comparePerson {
public:
	//不能修改指定的数据,用const 修饰Person&p1
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Age > p2.m_Age;
	}
};
void test06()
{

	//自定义数据类型,一定要注意指定排序规则
	set<Person, comparePerson> s;
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名: " << it->m_Name << " 年龄: " << it->m_Age<<endl;
	}
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return EXIT_SUCCESS;
}
