#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//�����﷨:�������� &���� = ԭ��
	int a = 10;
	int& b = a;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	b = 100;
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

//����������ȡ����
void test02()
{
	int arr[5] = { 1,2,3,4,5 };
	//typedef int(ARRAY_TYPE)[5]; �������һ�� �������ͣ���ʾһ����СΪ 5 �����顣
	//typedef int(&ARRAY_TYPE)[5]; �������һ�� �����������ͣ���ʾһ�����ã����õ���һ����СΪ 5 �����顣

	//1,�ȶ������������,��ͨ���������Ͷ�����������
	typedef int(ARRAY_TYPE)[5];
	//��ȡ����
	ARRAY_TYPE& parr = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << parr[i] << endl;
	}

	//2,�ȶ����������õ�����,��ͨ�������������Ͷ�����������
	typedef int(&ARRAY_TYPE1)[5];
	ARRAY_TYPE1 pArr = arr;
	for (int i = 0; i < 5; i++)
	{
		cout << pArr[i] << endl;
	}

	//3,ֱ�Ӷ���
	int(&pArr3)[5] = arr;
}

int main() {

	//test01();
	test02();
	const int& ref = 10;
	system("pause");
	return EXIT_SUCCESS;
}
