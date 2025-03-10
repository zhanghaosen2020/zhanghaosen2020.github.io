#define _CRT_SECURE_NO_WARNINGS
#include "myString.h"

//左移运算符的重载
ostream& operator<<(ostream& out, MyString& str)
{
	out << str.pString << endl;
	return out;
}

istream& operator>>(istream& cin, MyString& str)
{
	//先判断原来堆区是否有数据,如果有先清空
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}
	//再开辟一个缓冲区
	char buff[1024] = { 0 };
	cin >> buff;

	//将输入的值写入
	str.pString = new char[strlen(buff) + 1];
	strcpy(str.pString, buff);
	str.m_Size = strlen(str.pString);
	return cin;
}

MyString::MyString(const char* str)
{
	//cout << "有参构造调用" << endl;
	this->pString = new char[strlen(str) + 1];//计算传递过来的str长度(不算\0),+1预留\0.
	strcpy(pString, str);//将原数组内容拷贝过来
	this->m_Size = strlen(str);//维护自己类字符串的长度
}

MyString::MyString(const MyString& str)
{
	//cout << "拷贝构造调用" << endl;

	this->pString = new char[strlen(str.pString) + 1];//计算传递过来的str长度(不算\0),+1预留\0.
	strcpy(pString, str.pString);//将原字符串数组内容拷贝过来
	this->m_Size = strlen(str.pString);//维护自己类字符串的长度
}

MyString::~MyString()
{
	//cout << "析构函数调用" << endl;

	if (this->pString != NULL)
	{
		delete[] pString;
		pString = NULL;
	}

}
MyString& MyString::operator=(const char* str)
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(pString);

	return *this;
}

MyString& MyString::operator=(const MyString& str)
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->m_Size = strlen(str.pString);

	return *this;
}

char& MyString::operator[](int pos)
{
	return this->pString[pos];
}

MyString MyString::operator+(const char* str)
{
	//自身是abc,传入是def,
	//先搞一个长度够用的容器
	int newSize = this->m_Size + strlen(str) + 1;
	char* temp  = new char[newSize];
	memset(temp, 0,newSize);//将创建的新字符串数组符初值0;
	strcat(temp, this->pString);
	strcat(temp, str);

	MyString newString(temp);
	delete[] temp;
	return newString;

}

MyString MyString::operator+(const MyString& str)
{
	int newSize = this->m_Size + strlen(str.pString ) + 1;
	char* temp = new char[newSize];
	memset(temp, 0, newSize);//将创建的新字符串数组符初值0;
	strcat(temp, this->pString);
	strcat(temp, str.pString );

	MyString newString(temp);
	delete[] temp;
	return newString;

}

bool MyString::operator==(const MyString& str)
{
	if (strcmp(this->pString, str.pString) == 0)
	{
		return true;
	}
	return false;
}

bool MyString::operator==(const char* str)
{
	if (strcmp(this->pString, str) == 0)
	{
		return true;
	}
	return false;
}

