#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
public:
	int m_A;
	int m_B;

	Person()
	{
		m_A = 0;
		m_B = 0;
	}
	Person(int x,int y):m_A(x),m_B(y)
	{
	}

	//Person operator-(Person& p)
	//{	
	//	//这样子写会改变原先参数的值
	//	//this->m_A -= p.m_A;
	//	//this->m_B -= p.m_B;
	//	//return *this;

	//	Person temp;
	//	temp.m_A = this->m_A - p.m_A;
	//	temp.m_B = this->m_B - p.m_B;
	//	return temp;//临时变量不要引用返回
	//}
};
Person  operator-(Person  p1, Person  p2)
{
	Person temp;
	temp.m_A = p1.m_A - p2.m_A;
	temp.m_B = p1.m_B - p2.m_B;
	return temp;
}


void test01()
{
	Person p1(30, 20);
	Person p2(10, 10);
	Person p4(10, 10);
	Person p3 = p1 - p2 -p4 ;//连续的-,调用了默认构造函数
	cout << "p1.m_A = " << p1.m_A<<endl;
	cout << "m_A = " << p3.m_A << " m_B = " << p3.m_B<<endl;
}
//void test02()
//{
//	Person p1(30, 20);
//	Person p2(10, 10);
//	Person p4(10, 10);
//	Person p3 = p1 - p2;
//
//	cout << "m_A = " << p3.m_A << " m_B = " << p3.m_B;
//}

int main() {
	test01();
	//test02();

	system("pause");
	return EXIT_SUCCESS;
}
