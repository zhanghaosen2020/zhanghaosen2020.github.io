#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//类模板与继承的关系
//当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中T的类型，子类也需变为类模板

template<class T>
class Base {//父类
public:
	T m;
};

//class Son1 :public Base//此处会报错,缺少类模板的参数列表,并且编译器无法知道该给这个子类分配多大内存
//{
//
//};

class Son2 :public Base<int>//这样子指定参数列表之后,编译器就能知道,究竟究竟创建多大的空间了
{

};

//向上边那样指定具体的参数类型之后,难免会使后来的继承变得局促,因而我们可以继续使用模板
template<class T1,class T2>
class Son3 :public Base<T2> {
public:
	Son3()
	{
		cout << "T1的类型为: " << typeid(T1).name() << endl;
		cout << "T2的类型为: " << typeid(T2).name() << endl;
	}
	T1 m;
};

void test01()
{
	Son3<int,char> s;//char-->T2(Son3中的)-->T(Base中的)
}

int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
