#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int atk = 1000;//ȫ��
void test01()
{
	int atk = 2000;//�ֲ�
	cout << "�ֲ����� atk = " << atk << endl;
	//���	˫ð��ǰû���κ�����,�ʹ���ʹ�õ���ȫ�ֺ���(���ߵ�::ǰ���������ֿ���)
	cout << "ȫ�ֱ��� atk = " << ::atk << endl;

}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
