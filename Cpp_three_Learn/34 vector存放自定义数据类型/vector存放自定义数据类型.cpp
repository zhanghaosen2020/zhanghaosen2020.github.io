#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//容器存放自定义数据类型
//自定义数据类型
class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};

void test01()
{
	vector<Person>v;
	
	//创建对象
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);
	
	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	//遍历容器中的数组
	//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "姓名: " << (*it).mName << "  年龄: " << (*it).mAge << endl;//it当做指针解引用之后就是Person数据类型(尖括号中的类型)
		cout << "姓名: " << it->mName << "  年龄: " << it->mAge << endl;//直接用也是可以的,通过指针访问
	}
}

//存放自定义数据类型的指针
void test02()
{
	vector<Person*>v;

	//创建对象
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "姓名: " << (*it)->mName << "  年龄: " << (*it)->mAge << endl;
		cout << ":姓名: " << (**it).mName << "  :年龄: " << (*it)->mAge << endl;

	}
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
