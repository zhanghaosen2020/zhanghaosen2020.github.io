#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//函数对象(仿函数)

//1,函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd {
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 20) << endl;//函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
}


//2,函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string str)
	{
		cout << str << endl;
		count++;//可以统计仿函数的调用次数
	}
	int count;
};
void test02()
{
	MyPrint myPrint;
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	cout << "myPrint的调用次数为:" << myPrint.count << endl;
}

//3,函数对象可以作为参数传递
void print(MyPrint& mp, string str)
{
	mp(str);
}
void test03()
{
	MyPrint myPrint;
	print(myPrint, "呵呵呵!!!");
}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
