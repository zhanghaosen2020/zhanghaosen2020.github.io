#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�̳���ͬ����Ա����
class Base
{
public:
	Base()
	{
		m_A = 100;
	}
	int m_A;

	void func()
	{
		cout << "Base of func����" << endl;
	}

	void func(int a)
	{
		cout << "Base - func(int a)����" << endl;
	}
};

class Son :public Base
{
public:
	Son()
	{
		m_A = 200;
	}
	int m_A;

	void func()
	{
		cout << "Son - func()����" << endl;
	}
};

//ͬ����Ա����
void test01()
{
	Son s;
	cout << "Son  of m_A = " << s.m_A << endl;
	//���ͨ�����������ʵ������е�ͬ����Ա,��Ҫ��������
	cout << "Base of m_A = " << s.Base::m_A << endl;
}

void test02()
{
	Son s;
	s.func();
	//���ϱ�һ��,���������Ҫ���ʸ����е�ͬ����Ա,��Ҫ��������
	s.Base::func();


	//��������г��ֺ͸���ͬ���ĳ�Ա����,�����ͬ�����������ص�����������ͬ����Ա����
	//s.func(100);//����
	//�������ʵ������б����صĳ�Ա����,��Ҫ��������
	s.Base::func(100);

}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
