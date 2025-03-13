#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base {
public:
	//这样子做可以强制的让子类重写该函数,实现多态
	virtual void func() = 0;//虚函数=0,纯虚函数
	//一个类中只要有一个纯虚函数,那么这个类,就叫抽象类
	//抽象类无法实例化对象
	//抽象类的子类,必须重写父类中的纯虚函数,否则也属于抽象类
};

class Son :public Base{
public:
	virtual void func() {};//这都算是重写了哈
};

void test01()
{
	//抽象类无法实例化对象
	//Base b;

	Base* base = new Son;
	base->func();//多态服复用本质就是想让一个函数接口更加通用化,通过一个父类指针,由于你指向的对象不同,可以调用多种不同(重写的)的函数
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
