#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��ǳ�����ᱩ¶������������ֳ���
class Person {
public:
	int m_Age;
	int* m_Height;
	Person()
	{

		cout << "����һ��Ĭ���޲ι��캯��" << endl;
	}

	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);//�����ڶ�����������Ҫ�ɳ���Ա�Լ��ͷ�
		cout << "����һ���вι��캯��" << endl;
	}

	~Person()
	{
		//����,���������ٵ��������ͷŲ���
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "����һ��������������" << endl;
	}

	//������Ҫ�Լ�ʵ��һ���������캯��,�����ǳ��������������
	Person(const Person& p)
	{
		cout << "����һ������������������" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//���Ǳ�����Ĭ��ʵ��ǳ����ʱ�Ĳ���
		//�������
		m_Height = new int(*p.m_Height);//�¿���һ���ռ����洢,ʹ��֮������������ͷ�ͬһ��ռ���ڴ���ɱ���

	}

};

void test01()
{
	Person p(18,180);//�вι���
	cout << "����: " << p.m_Age << "���: " << *p.m_Height << endl;
	Person p1(p);//�����������Ŀ�������
	cout << "����: " << p1.m_Age << "���: " << *p1.m_Height << endl;

}

int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
