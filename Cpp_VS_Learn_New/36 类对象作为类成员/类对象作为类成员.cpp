#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�������Ϊ���Ա

class Phone {
public:
	string m_PhoneName;
	Phone(string pName):m_PhoneName(pName)
	{
		cout << "����Phone�Ĺ��캯��" << endl;
	}
	~Phone()
	{
		cout << "Phone�������" << endl;
	}
};
class Person{
public:
	string m_Name;
	Phone m_pName;
	//������Ȼ������Phone���͵�,�㴫�ݵ�string,����ᷢ����ʿת��
	//Phone m_pName = pname;	==>		Phone m_pName = Phone(pname);
	Person(string name, string pname) :m_Name(name), m_pName(pname)
	{
		cout << "����Person�Ĺ��캯��" << endl;
	}
	~Person()
	{
		cout << "Person�������" << endl;
	}
};

void test01()
{
	Person p("����", "MeiZu");
	cout << p.m_Name << "����" << p.m_pName.m_PhoneName << endl;
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
