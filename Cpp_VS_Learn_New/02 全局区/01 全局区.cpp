#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����������һЩȫ�ֱ���(���ں������ڵı���)
int g_a = 10;
int g_b = 20;

const int c_g_a = 30;//const���ε�ȫ�ֱ���(ȫ�ֳ���)

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
	cout << "�ַ��������ĵ�ַΪ: " << (int)& "hello" << endl;

	//const���α���
	//const���ε�ȫ�ֱ���
	cout << "ȫ�ֳ����ĵ�ַΪ: " << (int)&c_g_a << endl;
	
	//const���εľֲ�����(����ȫ������)
	const int c_l_a = 10;
	cout << "�ֲ������ĵ�ַΪ: " << (int)&c_l_a << endl;

	system("pause");
	return EXIT_SUCCESS;
}
