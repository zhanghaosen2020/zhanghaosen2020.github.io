#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//字符串比较
void test01()
{
	string str1 = "ello";
	string str2 = "hello";

	if (str1.compare(str2) == 0)//中文字符比较大小是没有意义的,因而只有比较相等的情况
	{
		cout << "字符串相等" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
