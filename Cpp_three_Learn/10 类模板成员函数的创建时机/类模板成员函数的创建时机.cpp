#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1 {
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2 {
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass {
public:
	T obj;
	
	void func1()
	{
		obj.showPerson1();
	}

	void func2()
	{
		obj.showPerson2();
	}
};

void test01()
{
	MyClass<Person1>m;
	m.func1();
	//m.func2();//func2()不是Person1的成员,你上边已经显式指定了参数列表为Person1,即T会被推导为Person1
	//也侧面说明函数调用才会去创建成员函数(对于类模板成员函数的创建来说)
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
