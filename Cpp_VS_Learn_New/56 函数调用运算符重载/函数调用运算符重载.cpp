#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyPrint {
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};
//仿函数非常灵活,没有固定的写法
//加法类
class MyAdd {
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test01()
{
	MyPrint myPrint;
	myPrint("hahahha");//通过()直接调用,相当于
	myPrint.operator()("hahahah"); 
}

void test02()
{
	MyAdd myAdd;
	cout << myAdd(2, 3) << endl;
	//匿名函数对象
	cout << MyAdd()(100, 100) << endl;//MyAdd()为匿名对象,特点是当前行执行完之后立马释放

}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
