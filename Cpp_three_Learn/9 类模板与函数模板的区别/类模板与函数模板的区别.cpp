#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����
//1. ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//2. ��ģ����ģ������б��п�����Ĭ�ϲ���
template<class NameType , class AgeType=int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showInfo()
	{
		cout << "name = " << this->m_Name << " age = " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test01()
{
	//Person p1("���", 999);//����,��ģ��û���Զ������Ƶ�

	Person<string, int>p2("���", 999);//��ģ��ֻ����ʾָ������
	p2.showInfo();
}

//2. ��ģ����ģ������б��п�����Ĭ�ϲ���
void test02()
{
	//����ʱ�Ĳ����б��Ѿ�ָ����һ����������,�����û�д���,����Ĭ�ϵ�,�����˾����㴫�ݵ�
	Person<string>p1("wuneng", 999);
	p1.showInfo();
}

int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
