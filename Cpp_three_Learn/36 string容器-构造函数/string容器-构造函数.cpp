#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//string(); //创建一个空的字符串 例如: string str;
//string(const char* s); //使用字符串s初始化
//string(const string& str); //使用一个string对象初始化另一个string对象
//string(int n, char c); //使用n个字符c初始化
void test01()
{
	string str;//调用string这个类的默认构造函数,创建一个空字符
	cout << "str = " << str << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
