#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
//����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
//���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��

//��ͨ����
int myAdd(int a, int b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << "a+b = " << myAdd(a, b) << endl;
	cout << "a+c = " << myAdd(a, c) << endl;//c��һ��char����,��������charת��Ϊ��int
}

template<class T>
int myAdd02(T a, T b)
{
	return a + b;
}
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//�Զ������Ƶ�,����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
	//cout << "a+b = " << myAdd02(a, c) << endl;

	//��ʾָ������,���൱�ڸ��߱��������T�����Ƶ���ָ��������(��int������)
	cout << "a+c = " << myAdd02<int>(a, c) << endl;//��(��ʽ����ת��)ת�͸���ת��ȥ
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
