#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�Զ�������
class MyInteger{

	friend ostream& operator<<(ostream& out, MyInteger& myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����++�������(ǰ��)
	MyInteger& operator++()//����������Ϊ��һֱ��һ�����ݵ���,��ֵ���صĻ�,����ÿ�������,�����µĶ���
	{
		m_Num++;
		return *this;
	}

	//����++�����(����)
	MyInteger operator++(int)//�����int��һ��ռλ����,����int֮��,��������������ǰ���õ���
	{//���õ���һ��Ҫ������ֵ������������,��Ϊ���ص�temp��һ����ʱ����(�ᱻ�ͷ�),���������þͻᵼ�·Ƿ�����
		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		m_Num++;
		//�� ����¼�Ľ������
		return temp;
	}//ע������ǰ���õ���������

private:
	int m_Num;
};

void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
}

void test02()
{
	MyInteger myint;
	cout << (myint++)++ << endl;
}

ostream& operator<<(ostream& out,  MyInteger&  myint)
{
	out << myint.m_Num;
	return out;
}
int main() {
	test01();

	test02();
	system("pause");
	return EXIT_SUCCESS;
}
