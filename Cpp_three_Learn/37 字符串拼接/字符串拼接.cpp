#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//string& operator+=(const char* str); //重载+=操作符
//string& operator+=(const char c); //重载+=操作符
//string& operator+=(const string& str); //重载+=操作符
//string& append(const char* s); //把字符串s连接到当前字符串结尾
//string& append(const char* s, int n); //把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string& s); //同operator+=(const string& str)
//string& append(const string& s, int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾

void test01()
{
	string str1("i ");
	str1 += "love you !";
	cout << "str1 = " << str1 << endl;

	str1 += '!';
	cout << "str1 = " << str1 << endl;

	string str2 ;
	str2 += str1;
	cout << "str2 = " << str2 << endl;

	str2.append("me too!");
	cout << "str2 = " << str2 << endl;

	str2.append("zxcvbnmasd", 4);
	cout << "str2 = " << str2 << endl;
	
	str2.append(str1);
	cout << "str2 = " << str2 << endl;




}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
