#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����������һЩȫ�ֱ���(���ں������ڵı���)
int g_a = 10;
int g_b = 20;

int main() {

	//ȫ�����д��ȫ�ֱ���\��̬����\����(const)����

	//�ȴ���һЩ��ͨ�ľֲ�����(Ҳ�������ں������ڲ�δ�����η��ı���)
	int a = 10;
	int b = 20;
	cout << "�ֲ�����a�ĵ�ַ��: " << (int)&a << endl;
	cout << "�ֲ�����b�ĵ�ַ��: " << (int)&b << endl;

	cout << "ȫ�ֱ���g_a�ĵ�ַ��: " << (int)&g_a << endl;
	cout << "ȫ�ֱ���g_b�ĵ�ַ��: " << (int)&g_b << endl;

	//��̬����
	static int s_a = 10;
	static int s_b = 20;
	cout << "��̬����s_a�ĵ�ַ��: " << (int)&s_a << endl;
	cout << "��̬����s_b�ĵ�ַ��: " << (int)&s_b << endl;

	//����
	//�ַ�������(ֻҪ����˫�����������ľͽ��ַ�������)
	cout << "�ַ��������ĵ�ַΪ: " << (int) & "hello" << endl;

	system("pause");
	return EXIT_SUCCESS;
}
