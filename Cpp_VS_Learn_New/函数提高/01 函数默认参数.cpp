#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����Ĭ�ϲ���
//�������������ô��ݵĲ���,�������Ĭ��ֵ
int func(int a, int b = 20, int c = 30) 
{
	return a + b + c;
}


//ע������
//1,���ĳ��λ���Ѿ�����Ĭ�ϲ���,��ô�����λ�������������,��������Ĭ�ϲ���func1
//int func1(int a, int b = 1, int c)//����,Ĭ��ʵ�β����β��б�Ľ�β
//{
//	return a + b + c;
//}

//2,���������������Ĭ�ϲ���,����ʵ�־Ͳ�����Ĭ�ϲ���
int func2(int a = 10, int b = 30);
int func2(int a, int b)
{
	return a + b;
}




int main() {

	cout << func(10, 40) << endl;
	//func1(1,2,3);
	system("pause");
	return EXIT_SUCCESS;
}
