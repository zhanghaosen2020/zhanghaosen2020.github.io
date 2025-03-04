#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
public:
	Person()
	{
		cout << "默认构造函数调用" << endl;
	}

	Person(int)//占位参数
	{
		cout << "参数构造函数调用" << endl;
	}
	Person(const Person&)//占位参数
	{
		cout << "拷贝构造函数调用" << endl;
	}
	~Person()
	{
		cout << "析构函数调用" << endl;
	}
};

//

//malloc和new的区别?
//1,malloc和free属于库函数(需要包含头文件)		new和delete属于运算符
//2,malloc返回的是void*							new返回的是对应数据类型的指针
//3,malloc对应free								new对应delete
//4,前者不会调用构造和解析						后者会调用
void test01()
{
	//Person p;//在栈上创建对象

	//在堆区创建对象
	Person* p1 = new Person;

	//在堆区开辟的内存需手动释放
	delete p1;

}


//在堆区中开辟数组
void test02()
{
	int* pInt = new int[10];
	char* pChar = new char[10];

	Person* persons = new Person[10];//如果是自定义类型的数组,这个类型必须有默认构造函数(编译器会调用)
	//释放堆区数组
	delete []pInt;
	delete[] pChar;
	delete[] persons;//释放数组的时候必须要加上[],声明释放的是一个数组,否则程序会崩溃
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
