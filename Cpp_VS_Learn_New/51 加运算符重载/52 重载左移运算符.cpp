#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//重载左移运算符,让cout可以直接输出自定义的数据类型
class Person {
	friend ostream& operator<<(ostream& cout, Person p);//以友元的方式访问类内部的私有变量
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	//利用成员函数重载<<
	//void operator<<( cout )//即使像这个样子写,我们也无法实现 cout << p ;这样的效果
	//{//所以我们一般不在成员函数中重载左移运算符;
	//	
	//}
	int m_A;
	int m_B;
};

//只能用全集函数重载左移运算符
ostream& operator<<(ostream& out, Person p)
{
	out << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return out;	
}

void test01()
{
	Person p(10,20);

	//cout << p.m_A << endl;
	cout << p << " hello world" << endl;//为满足链式输出,我们返回cout,而后cout<<"hello world",就是用的原来的运算符了

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}