#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<iomanip>

void test01()
{
	//cout.put('h').put('e');//ÿ�����һ���ַ�,�ṩ����ʽ���,�鷳������
	/*char buf[1024] = "hellow world";
	cout.write(buf, strlen(buf));*///�鷳������


	//��ʽ�������һЩ���Ʒ�
	int number = 99;
	cout.width(20);//���ÿ��
	cout.fill('*');  //�������
	cout.setf(ios::left);//�����
	cout.unsetf(ios::dec); //ж��ʮ����
	cout.setf(ios::hex);//��װʮ������
	cout.setf(ios::showbase);//��ʾ���ƻ���  0x  
	cout.unsetf(ios::hex);//ж��ʮ������
	cout.setf(ios::oct);//��װ�˽���
	cout << number << endl;
}

void test02() {

	int number = 99;
	cout << setw(20)//���ÿ��
		<< setfill('~')//�������
		<< setiosflags(ios::showbase)
		<< setiosflags(ios::left)//�����
		<< hex//��װʮ������
		<< number
		<< endl;

}
int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
