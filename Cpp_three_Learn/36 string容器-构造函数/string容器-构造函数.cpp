#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//string(); //����һ���յ��ַ��� ����: string str;
//string(const char* s); //ʹ���ַ���s��ʼ��
//string(const string& str); //ʹ��һ��string�����ʼ����һ��string����
//string(int n, char c); //ʹ��n���ַ�c��ʼ��
void test01()
{
	string str1;//����string������Ĭ�Ϲ��캯��,����һ�����ַ�
	cout << "str1 = " << str1 << endl;

	//const char* str = "hello world";
	//string str2(str);// ע��:�˴���������ʽ����ת��
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
