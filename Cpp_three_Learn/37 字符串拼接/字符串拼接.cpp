#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//string& operator+=(const char* str); //����+=������
//string& operator+=(const char c); //����+=������
//string& operator+=(const string& str); //����+=������
//string& append(const char* s); //���ַ���s���ӵ���ǰ�ַ�����β
//string& append(const char* s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//string& append(const string& s); //ͬoperator+=(const string& str)
//string& append(const string& s, int pos, int n); //�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β

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
