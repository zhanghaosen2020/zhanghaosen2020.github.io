#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

////ջ������Ҫ���� --- ��Ҫ���ؾֲ������ĵ�ַ(��Ϊ�ֲ������ĵ�ַ���ں�����������֮���Զ��ͷ�)
////ջ�������ɱ����������ٺ��ͷ�
//int* func()
//{
//	int a = 100;
//	return &a;
//}
//
//int main() {
//
//	int* p = func();//����func�����ķ���ֵ
//
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;
//	cout << *p << endl;	
//	cout << *p << endl;
//	cout << *p << endl;
//
//	system("pause");
//	return EXIT_SUCCESS;
//}

//ջ������Ҫ���� --- ��Ҫ���ؾֲ������ĵ�ַ(��Ϊ�ֲ������ĵ�ַ���ں�����������֮���Զ��ͷ�)
//ջ�������ɱ����������ٺ��ͷ�

int* display(int b)//�β�����Ҳ�Ǵ����ջ����
{
	b = 100;
	int num[3] = { 8,6,5 };
	return num;
}

int main() {
	int* p = display(1);
	for (int i = 0; i < 3; i++) {
		std::cout << *(p + i) << std::endl;
	}
	//��õ�����Ľ��
	return 0;
}