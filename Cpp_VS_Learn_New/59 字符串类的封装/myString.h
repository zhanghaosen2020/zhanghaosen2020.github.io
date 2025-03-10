#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class MyString {

	friend ostream& operator<<(ostream& out, MyString& str);
	friend istream& operator>>(istream& cin, MyString& str);
public:
	MyString(const char* str);//模拟 MyString str = "abcd";
	MyString(const MyString& str); //MyString str1 = str;
	~MyString();

	//重载等号( = )赋值  
	MyString& operator=(const char* str);

	MyString& operator=(const MyString& str);

	//重载[],为了访问单个元素
	char& operator[](int pos);//想想为什么是char&来接收???

	//重载 + ,做字符串的拼接功能
	MyString operator+(const char* str);
	MyString operator+( const MyString& str);

	//重载 == ,做字符串的比较功能
	bool operator==(const MyString& str);
	bool operator==(const char* str);



private:
	char* pString;//维护底层堆区开辟的字符数组
	int m_Size;//字符串长度  不计算 \0
};