#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1,new的基本语法
int* func()
{
	int* p = new int(100);
	//char* p = new char('c');
	return p;
}

void test01()
{
	int* p = func();
	cout << *p << endl;

	//如果想释放该内存,可以利用delete关键字
	delete p;
}


//2,堆区开辟数组
void test02()
{
	//创建一个10个整形的数组,在堆区创建
	int* arr = new int[10];//中括号中的10代表有10个元素
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i+10;//10~19;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//释放数组(需要加中括号强调,释放的是数组空间)
	delete[] arr;
}
int main() {

	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
