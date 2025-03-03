#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//接下来创建一些全局变量(不在函数体内的变量)
int g_a = 10;
int g_b = 20;

const int c_g_a = 30;//const修饰的全局变量(全局常量)

int main() {

	//全局区中存放全局变量\静态变量\常量(const)修饰

	//先创建一些普通的局部变量(也即创建在函数体内部未加修饰符的变量)
	int a = 10;
	int b = 20;
	cout << "局部变量a的地址是: " << (int)&a << endl;
	cout << "局部变量b的地址是: " << (int)&b << endl;

	cout << "全局变量g_a的地址是: " << (int)&g_a << endl;
	cout << "全局变量g_b的地址是: " << (int)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 20;
	cout << "静态变量s_a的地址是: " << (int)&s_a << endl;
	cout << "静态变量s_b的地址是: " << (int)&s_b << endl;

	//常量
	//字符串常量(只要是用双引号括起来的就叫字符串常量)
	cout << "字符串常量的地址为: " << (int)& "hello" << endl;

	//const修饰变量
	//const修饰的全局变量
	cout << "全局常量的地址为: " << (int)&c_g_a << endl;
	
	//const修饰的局部变量(不在全局区中)
	const int c_l_a = 10;
	cout << "局部常量的地址为: " << (int)&c_l_a << endl;

	system("pause");
	return EXIT_SUCCESS;
}
