#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
public:
	int* m_Age;
	Person(int age)
	{
		m_Age = new int(age);
	}

	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
		cout << "��������" << endl;
	}
	Person& operator=(Person& p)
	{
		//if (m_Age != NULL)
		//{
		//	delete m_Age;
		//	m_Age = NULL;
		//}//�������Ķ�����Ҳ�ڶ����������ڴ�������ֵ,���ǲ�����Ĭ�ϵĺ��������򵥵Ľ���ֵ����

		//m_Age = new int(*p.m_Age);
		*(this->m_Age) = *(p.m_Age);

		return *this;
	}
};
void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	cout << &p1.m_Age << endl;
	cout << &p2.m_Age << endl;
	cout << *p1.m_Age << endl;
	cout << *p2.m_Age << endl;




	p1 = p2 ;
	cout << *p1.m_Age << endl;
	cout << *p2.m_Age << endl;
	cout << *p1.m_Age << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
