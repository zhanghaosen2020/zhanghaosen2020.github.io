#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class MyString {

	friend ostream& operator<<(ostream& out, MyString& str);
	friend istream& operator>>(istream& cin, MyString& str);
public:
	MyString(const char* str);//ģ�� MyString str = "abcd";
	MyString(const MyString& str); //MyString str1 = str;
	~MyString();

	//���صȺ�( = )��ֵ  
	MyString& operator=(const char* str);

	MyString& operator=(const MyString& str);

	//����[],Ϊ�˷��ʵ���Ԫ��
	char& operator[](int pos);//����Ϊʲô��char&������???

	//���� + ,���ַ�����ƴ�ӹ���
	MyString operator+(const char* str);
	MyString operator+( const MyString& str);

	//���� == ,���ַ����ıȽϹ���
	bool operator==(const MyString& str);
	bool operator==(const char* str);



private:
	char* pString;//ά���ײ�������ٵ��ַ�����
	int m_Size;//�ַ�������  ������ \0
};