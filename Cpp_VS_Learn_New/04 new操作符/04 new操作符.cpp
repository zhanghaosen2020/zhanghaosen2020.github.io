#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1,new�Ļ����﷨
int* func()
{
	int* p = new int(100);
	//char* p = new char('c');
	return p;
}

void test01()
{
	int* p = func();
	cout << *p << endl;

	//������ͷŸ��ڴ�,��������delete�ؼ���
	delete p;
}


//2,������������
void test02()
{
	//����һ��10�����ε�����,�ڶ�������
	int* arr = new int[10];//�������е�10������10��Ԫ��
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i+10;//10~19;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	//�ͷ�����(��Ҫ��������ǿ��,�ͷŵ�������ռ�)
	delete[] arr;
}
int main() {

	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
