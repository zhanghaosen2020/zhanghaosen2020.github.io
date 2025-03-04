#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//类对象作为类成员

class Phone {
public:
	string m_PhoneName;
	Phone(string pName):m_PhoneName(pName)
	{
		cout << "这是Phone的构造函数" << endl;
	}
	~Phone()
	{
		cout << "Phone类的析构" << endl;
	}
};
class Person{
public:
	string m_Name;
	Phone m_pName;
	//这里虽然参数是Phone类型的,你传递的string,这里会发生隐士转换
	//Phone m_pName = pname;	==>		Phone m_pName = Phone(pname);
	Person(string name, string pname) :m_Name(name), m_pName(pname)
	{
		cout << "这是Person的构造函数" << endl;
	}
	~Person()
	{
		cout << "Person类的析构" << endl;
	}
};

void test01()
{
	Person p("王五", "MeiZu");
	cout << p.m_Name << "拿着" << p.m_pName.m_PhoneName << endl;
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
