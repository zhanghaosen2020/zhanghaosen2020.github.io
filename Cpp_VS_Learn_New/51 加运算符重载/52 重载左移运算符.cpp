#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������������,��cout����ֱ������Զ������������
class Person {
	friend ostream& operator<<(ostream& cout, Person p);//����Ԫ�ķ�ʽ�������ڲ���˽�б���
public:
	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	//���ó�Ա��������<<
	//void operator<<( cout )//��ʹ���������д,����Ҳ�޷�ʵ�� cout << p ;������Ч��
	//{//��������һ�㲻�ڳ�Ա�������������������;
	//	
	//}
	int m_A;
	int m_B;
};

//ֻ����ȫ�������������������
ostream& operator<<(ostream& out, Person p)
{
	out << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return out;	
}

void test01()
{
	Person p(10,20);

	//cout << p.m_A << endl;
	cout << p << " hello world" << endl;//Ϊ������ʽ���,���Ƿ���cout,����cout<<"hello world",�����õ�ԭ�����������

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}