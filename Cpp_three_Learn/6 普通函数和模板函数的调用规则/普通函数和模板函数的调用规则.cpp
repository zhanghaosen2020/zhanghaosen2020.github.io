#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ͨ����
void Print(int a, int b)
{
	cout << "������ͨ�����ĵ���" << endl;
}

template<class T>
void Print(T a, T b)
{
	cout << "����ģ�庯���ĵ���" << endl;
}

template<class T>
void Print(T a, T b, T c) 
{
	cout << "����ģ�庯����(����)����" << endl;
}


void test01()
{
	int a = 10;
	int b = 20;
	Print(a, b);//1. �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	// ע�� ������߱����� ��ͨ�������еģ���ֻ������û��ʵ�֣����߲��ڵ�ǰ�ļ���ʵ�֣��ͻᱨ���Ҳ���
	
	Print<int>(a, b); //2. ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��

	int c = 30;
	Print(a, b, c);//3. ����ģ��Ҳ���Է�������

	char c1 = 'a';
	char c2 = 'b';
	Print(c1, c2); //4. �������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��
	//����ͨ������������װ��,��������Ϊ������ֱ�����Ƶ������͸��ӷ���
}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
