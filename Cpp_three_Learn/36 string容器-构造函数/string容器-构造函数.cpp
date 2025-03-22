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
	string str1;//调用string这个类的默认构造函数,创建一个空字符
	cout << "str1 = " << str1 << endl;

	//const char* str = "hello world";
	//string str2(str);// 注意:此处发生了隐式类型转换
	//cout << "str2 = " << str2 << endl;
	string str2("jjj");

	string str3(str2);
	cout << "str3 = " << str3 << endl;

	string str4(6, 'a');
	cout << "str4 = " << str4 << endl;



}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
