#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//静态成员变量的相关操作
//1,静态成员变量类内声明,类外定义
//2,静态成员变量是被该类的所有对象共享的,不具体属于某一个类
//		2.1,由此可以衍生出两种访问静态成员变量的方式:
//		2.1.1,通过创建一个对象来访问
//		2.1.2,通过该类命来访问
//3,在编译阶段就被分配了内存了
class Person {
public:
	static int m_A; 

private:
	static int m_B;
};
int Person::m_A = 100;//类内声明,类外定义
int Person::m_B = 200;

void test01()
{
	//访问方式1
	Person p1;
	cout << "m_A = " << p1.m_A << endl;
	//访问方式2		(因为静态成员变量是不属于任何一个具体的对象的,因而直接可以用类来访问)
	p1.m_A = 0;
	cout << "m_A = " << Person::m_A << endl;

	//静态成员变量也是有其权限的
	//cout << "m_B = " << Person::m_B << endl;//错误-->不可访问
}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
