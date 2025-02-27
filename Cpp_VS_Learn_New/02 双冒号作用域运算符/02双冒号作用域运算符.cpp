#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int atk = 1000;//全局
void test01()
{
	int atk = 2000;//局部
	cout << "局部变量 atk = " << atk << endl;
	//如果	双冒号前没有任何内容,就代表使用的是全局函数(与后边的::前有内容区分开来)
	cout << "全局变量 atk = " << ::atk << endl;

}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
