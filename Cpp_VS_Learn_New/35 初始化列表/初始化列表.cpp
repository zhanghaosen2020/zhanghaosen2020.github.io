#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ʼ���б�
class Person {
public:
	int m_A;
	int m_B;
	int m_C;
	//�汾1,��ʼ���б��Ϊ�����д��
	//Person() :m_A(10), m_B(20), m_C(30)
	//{
	//
	//
	//}
	
	//�汾2,��ʼ���б��Ϊ����д��

	//�Ƿ��ѿ��ӷ�ƨ��?��Ϊ��Ȼ�вι��캯�����������Ĳ�����,Ϊ�λ�Ҫ��˲�����?
	//��Ҳ,���д����ʹ�ü̳���������û����вι����ʱ���Ǳ����
	Person(int a,int b ,int c) :m_A(a), m_B(b), m_C(c)
	{
	
	}
};

void test01()
{
	Person p(10,10,10);
	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}
int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
