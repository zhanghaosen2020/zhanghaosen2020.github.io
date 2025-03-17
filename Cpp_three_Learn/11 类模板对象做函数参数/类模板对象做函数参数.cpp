#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ģ����������������Ĵ��ݷ�ʽ
//1. ָ�����������-- - ֱ����ʾ�������������
//2. ����ģ�廯-- - �������еĲ�����Ϊģ����д���
//3. ������ģ�廯-- - ������������� ģ�廯���д���

template<class T1,class T2>
class Person {
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{	
		cout << "����: " << m_Name << " ����: " << m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

//1,ֱ�Ӵ���ָ��������(��ʾָ��),���ַ����õ���Ϊ�㷺
void printPerson1(Person<string ,int>&p)
{
	p.showPerson();
}
void test01()
{
	Person<string, int>p("���", 18);
	printPerson1(p);
}

//2,����ģ�廯
template<class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1������Ϊ: " << typeid(T1).name()<<endl ;
	cout << "T2������Ϊ: " << typeid(T2).name()<<endl ;

}
void test02()
{
	Person<string,int>p("�˽�", 17);
	printPerson2(p);
}

//3,ֱ�ӽ�������ģ�廯
template<class T>
void printPerson3(T&p)
{
	p.showPerson();
	cout << "T������Ϊ: " << typeid(T).name() << endl;
}
void test03()
{
	Person<string, int>p("��", 16);
	printPerson3(p);
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
