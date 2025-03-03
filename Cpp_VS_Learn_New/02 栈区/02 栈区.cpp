#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////栈区的主要事项 --- 不要返回局部变量的地址(因为局部变量的地址会在函数结束运行之后自动释放)
////栈区数据由编译器管理开辟和释放
//int* func()
//{
//	int a = 100;
//	return &a;
//}
//
//int main() {
//
//	int* p = func();//接受func函数的返回值
//
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;	
//	cout << *p << endl;
//	cout << *p << endl;
//
//	system("pause");
//	return EXIT_SUCCESS;
//}

//栈区的主要事项 --- 不要返回局部变量的地址(因为局部变量的地址会在函数结束运行之后自动释放)
//栈区数据由编译器管理开辟和释放

int* display(int b)//形参数据也是存放在栈区的
{
	b = 100;
	int num[3] = { 8,6,5 };
	return num;
}

int main() {
	int* p = display(1);
	for (int i = 0; i < 3; i++) {
		std::cout << *(p + i) << std::endl;
	}
	//会得到错误的结果
	return 0;
}