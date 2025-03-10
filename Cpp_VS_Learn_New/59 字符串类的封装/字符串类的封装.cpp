#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myString.h"
void test01()
{
	MyString str1 = "abcd";
	MyString str2 = str1;
	cout << "str1 = " << str1;//需要重载一下 <<,以方便输出自己的类对象
	cout << "str2 = " << str2;

	cout << "请重新给str1赋值" << endl;
	cin >> str1;
	cout << "请重新给str1赋值" << endl;

}
void test02()
{
	MyString str1 = "abcd";
	MyString str2 = "efgh";

	str1 = str2;//自定义的类做不到
	cout << "str1 = " << str1;

	str1 = "3h3h";//自定义的类做不到
	cout << "str1 = " << str1;
}

void test03()
{
	MyString str = "abc";
	cout << "str[0] = " << str[0]<<endl;//访问不到自定义类型的指定位置的字符
	str[0] = 'g';//修改也做不到
	cout << "str[0] = " << str[0]<<endl;
}

void test04()
{
	MyString str1 = "abcd";
	MyString str2 = "efgh";

	MyString str3 = str1 + str2;
	cout << "str3 = " << str3 << endl;

	MyString str4 = str1 + "dek";
	cout << "str4 = " << str4 << endl;

}

void test05()
{
	MyString str1 = "abcd";
	MyString str2 = "acd";
	if (str1 == str2)
	{
		cout << "str1 == str2" << endl;
	}
	else
	{
		cout << "str1 != str2" << endl;
	}

	if (str1 == "abcd")
	{
		cout << "str1 == str2" << endl;
	}
	else
	{
		cout << "str1 != str2" << endl;
	}

}
int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	//char buff[50] = { 0 };
	//cin >> buff;//输入时,遇到空格就会结束
	//cout << buff << endl;
	system("pause");
	return EXIT_SUCCESS;
}
