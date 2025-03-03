#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//基本语法:数据类型 &别名 = 原名
	int a = 10;
	int& b = a;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	b = 100;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

//建立对数组取别名
void test02()
{
	int arr[5] = { 1,2,3,4,5 };
	//typedef int(ARRAY_TYPE)[5]; 定义的是一个 数组类型，表示一个大小为 5 的数组。
	//typedef int(&ARRAY_TYPE)[5]; 定义的是一个 数组引用类型，表示一个引用，引用的是一个大小为 5 的数组。

	//1,先定义数组的类型,再通过数组类型定义数组引用
	typedef int(ARRAY_TYPE)[5];
	//再取别名
	ARRAY_TYPE& parr = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << parr[i] << endl;
	}

	//2,先定义数组引用的类型,再通过数组引用类型定义数组引用
	typedef int(&ARRAY_TYPE1)[5];
	ARRAY_TYPE1 pArr = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << pArr[i] << endl;
	}

	//3,直接定义
	int(&pArr3)[5] = arr;
}

int main() {

	//test01();
	test02();
	const int& ref = 10;
	system("pause");
	return EXIT_SUCCESS;
}
