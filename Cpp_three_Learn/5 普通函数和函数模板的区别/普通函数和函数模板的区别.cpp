#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//普通函数调用时可以发生自动类型转换（隐式类型转换）
//函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//如果利用显示指定类型的方式，可以发生隐式类型转换

//普通函数
int myAdd(int a, int b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "a+b = " << myAdd(a, b) << endl;
	cout << "a+c = " << myAdd(a, c) << endl;//c是一个char类型,编译器将char转化为了int
}

template<class T>
int myAdd02(T a, T b)
{
	return a + b;
}
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//自动类型推导,函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
	//cout << "a+b = " << myAdd02(a, c) << endl;

	//显示指定类型,就相当于告诉编译器请把T给我推导成指定的类型(如int等类型)
	cout << "a+c = " << myAdd02<int>(a, c) << endl;//能(隐式类型转换)转就给我转过去
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
