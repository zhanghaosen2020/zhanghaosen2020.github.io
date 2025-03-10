#define _CRT_SECURE_NO_WARNINGS
#include "myString.h"

//���������������
ostream& operator<<(ostream& out, MyString& str)
{
	out << str.pString << endl;
	return out;
}

istream& operator>>(istream& cin, MyString& str)
{
	//���ж�ԭ�������Ƿ�������,����������
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}
	//�ٿ���һ��������
	char buff[1024] = { 0 };
	cin >> buff;

	//�������ֵд��
	str.pString = new char[strlen(buff) + 1];
	strcpy(str.pString, buff);
	str.m_Size = strlen(str.pString);
	return cin;
}

MyString::MyString(const char* str)
{
	//cout << "�вι������" << endl;
	this->pString = new char[strlen(str) + 1];//���㴫�ݹ�����str����(����\0),+1Ԥ��\0.
	strcpy(pString, str);//��ԭ�������ݿ�������
	this->m_Size = strlen(str);//ά���Լ����ַ����ĳ���
}

MyString::MyString(const MyString& str)
{
	//cout << "�����������" << endl;

	this->pString = new char[strlen(str.pString) + 1];//���㴫�ݹ�����str����(����\0),+1Ԥ��\0.
	strcpy(pString, str.pString);//��ԭ�ַ����������ݿ�������
	this->m_Size = strlen(str.pString);//ά���Լ����ַ����ĳ���
}

MyString::~MyString()
{
	//cout << "������������" << endl;

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
	//������abc,������def,
	//�ȸ�һ�����ȹ��õ�����
	int newSize = this->m_Size + strlen(str) + 1;
	char* temp  = new char[newSize];
	memset(temp, 0,newSize);//�����������ַ����������ֵ0;
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
	memset(temp, 0, newSize);//�����������ַ����������ֵ0;
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

