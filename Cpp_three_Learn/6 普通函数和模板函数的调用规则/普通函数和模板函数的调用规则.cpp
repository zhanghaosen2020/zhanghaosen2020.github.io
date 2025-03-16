#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//普通函数
void Print(int a, int b)
{
	cout << "这是普通函数的调用" << endl;
}

template<class T>
void Print(T a, T b)
{
	cout << "这是模板函数的调用" << endl;
}

template<class T>
void Print(T a, T b, T c) 
{
	cout << "这是模板函数的(重载)调用" << endl;
}


void test01()
{
	int a = 10;
	int b = 20;
	Print(a, b);//1. 如果函数模板和普通函数都可以实现，优先调用普通函数
	// 注意 如果告诉编译器 普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
	
	Print<int>(a, b); //2. 可以通过空模板参数列表来强制调用函数模板

	int c = 30;
	Print(a, b, c);//3. 函数模板也可以发生重载

	char c1 = 'a';
	char c2 = 'b';
	Print(c1, c2); //4. 如果函数模板可以产生更好的匹配, 优先调用函数模板
	//用普通函数会有类型装换,编译器认为还不如直接用推导的类型更加方便
}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
