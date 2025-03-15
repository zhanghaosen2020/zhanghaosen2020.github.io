#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//函数模板

//两个整形交换函数
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型函数
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T>//声明一个模板,告诉编译器后面代码中紧跟着的T不要报错
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//2,模板必须要确定出T的数据类型,才可以使用
template<class T>
void func()
{
	cout << "func函数的调用" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//1,自动类型推导,必须推导出一致的数据类型T,才可使用
	//mySwap(a, b);
	//mySwap(a, c);//错误,类型不一致

	//2,显示指定类型
	mySwap<int>(a, b);
	cout << "a = " << a << " b = " << b << endl;
}

void test02()
{
	//func();//错误，模板不能独立使用，必须确定出T的类型
	func<int>();//利用显示指定类型的方式，给T一个类型，才可以使用该模板
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
