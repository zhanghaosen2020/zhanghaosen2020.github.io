#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�ַ����Ƚ�
void test01()
{
	string str1 = "ello";
	string str2 = "hello";

	if (str1.compare(str2) == 0)//�����ַ��Ƚϴ�С��û�������,���ֻ�бȽ���ȵ����
	{
		cout << "�ַ������" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1>str2" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
