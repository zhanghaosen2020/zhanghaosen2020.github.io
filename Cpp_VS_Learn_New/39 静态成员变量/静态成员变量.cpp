#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��̬��Ա��������ز���
//1,��̬��Ա������������,���ⶨ��
//2,��̬��Ա�����Ǳ���������ж������,����������ĳһ����
//		2.1,�ɴ˿������������ַ��ʾ�̬��Ա�����ķ�ʽ:
//		2.1.1,ͨ������һ������������
//		2.1.2,ͨ��������������
//3,�ڱ���׶ξͱ��������ڴ���
class Person {
public:
	static int m_A; 

private:
	static int m_B;
};
int Person::m_A = 100;//��������,���ⶨ��
int Person::m_B = 200;

void test01()
{
	//���ʷ�ʽ1
	Person p1;
	cout << "m_A = " << p1.m_A << endl;
	//���ʷ�ʽ2		(��Ϊ��̬��Ա�����ǲ������κ�һ������Ķ����,���ֱ�ӿ�������������)
	p1.m_A = 0;
	cout << "m_A = " << Person::m_A << endl;

	//��̬��Ա����Ҳ������Ȩ�޵�
	//cout << "m_B = " << Person::m_B << endl;//����-->���ɷ���
}
int main() {
	test01();

	system("pause");
	return EXIT_SUCCESS;
}
