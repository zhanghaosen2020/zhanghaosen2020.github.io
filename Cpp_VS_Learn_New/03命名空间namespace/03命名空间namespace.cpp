#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"game1.h"
#include"game2.h"
using namespace std;

//1,�����ռ�:���Խ�����Ƴ�ͻ����
void test01()
{
	LOL::goAtk();
	KingGlory::goAtk();
}

//2,�����ռ��¿��Դ洢,����\����\�ṹ��\���
namespace A
{
	int m_A = 10;
	void func();
	struct Person {};
	class Animal{};
}

//3,�����ռ����������ȫ����������
void test02()
{
	/*namespace A
	{
	}*///�����������ʽ(���ܶ����ھֲ���)
}

//4,�����ռ����Ƕ�������ռ�
namespace A 
{
	int m_a = 10;
	namespace B
	{
		int m_a = 20;
	}
}
void test03()
{
	cout << A::m_a << endl;
	cout << A::B::m_a << endl;

}
//�����ռ��ǿ��ŵĿ�����ʱ��ռ�������³�Ա
namespace A
{
	int m_b = 30;
}
void test04()
{
	cout << A::m_a << endl;
	cout << A::B::m_a << endl;
	cout << A::m_b << endl;
}

//6,�����ռ������������  (��Ϊ�����ռ������ȫ�ֵ�,���Ե�����ʱ,���Խ����еı������Ϊȫ�ֱ���)
namespace
{
	int m_C = 100;
	int m_D = 200;
}
void test05()
{
	cout << m_C << endl;
	cout << ::m_D << endl;
}

//7,�����ռ����ȡ����
namespace veryLongName
{
	int m_E = 1000;
}
void test06()
{
	namespace veryShrotName = veryLongName;
	cout << veryLongName::m_E << endl;//��������ռ�̫����,Ƕ���˵Ļ��͸��ӳ���
	cout << veryShrotName::m_E << endl;//������̵�����

}

int main() {

	/*test01();
	test03();
	test04();*/
	test05();
	system("pause");
	return EXIT_SUCCESS;
}
                                                                                            