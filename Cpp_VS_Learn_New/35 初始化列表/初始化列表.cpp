#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//初始化列表
class Person {
public:
	int m_A;
	int m_B;
	int m_C;
	//版本1,初始化列表较为死板的写法
	//Person() :m_A(10), m_B(20), m_C(30)
	//{
	//
	//
	//}
	
	//版本2,初始化列表较为灵活的写法

	//是否脱裤子放屁呢?因为既然有参构造函数能完成下面的操作了,为何还要如此操作呢?
	//非也,这个写法在使用继承派生类调用基类有参构造的时候是必须的
	Person(int a,int b ,int c) :m_A(a), m_B(b), m_C(c)
	{
	
	}
};

void test01()
{
	Person p(10,10,10);
	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}
int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
