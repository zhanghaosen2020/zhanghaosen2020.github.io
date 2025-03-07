#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//空指针访问成员函数
class Person {
public:
	int m_Age;

	void showClassName()
	{
		cout << "这是类的名字" << endl;
	}

	void showPersonAge()
	{
		cout << "年龄为: " << this->m_Age << endl;
	}

};
void test01()
{
	Person* p = NULL;
	p->showClassName();//空类是可以访问成员函数的,前提是该成员函数中没有用到隐含的this指针
	//p->showPersonAge();//该函数中间就调用了this指针导致程序崩溃了
}

int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
