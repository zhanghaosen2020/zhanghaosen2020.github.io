#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person {
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯������" << endl;
	}

	Person(int)//ռλ����
	{
		cout << "�������캯������" << endl;
	}
	Person(const Person&)//ռλ����
	{
		cout << "�������캯������" << endl;
	}
	~Person()
	{
		cout << "������������" << endl;
	}
};

//

//malloc��new������?
//1,malloc��free���ڿ⺯��(��Ҫ����ͷ�ļ�)		new��delete���������
//2,malloc���ص���void*							new���ص��Ƕ�Ӧ�������͵�ָ��
//3,malloc��Ӧfree								new��Ӧdelete
//4,ǰ�߲�����ù���ͽ���						���߻����
void test01()
{
	//Person p;//��ջ�ϴ�������

	//�ڶ�����������
	Person* p1 = new Person;

	//�ڶ������ٵ��ڴ����ֶ��ͷ�
	delete p1;

}


//�ڶ����п�������
void test02()
{
	int* pInt = new int[10];
	char* pChar = new char[10];

	Person* persons = new Person[10];//������Զ������͵�����,������ͱ�����Ĭ�Ϲ��캯��(�����������)
	//�ͷŶ�������
	delete []pInt;
	delete[] pChar;
	delete[] persons;//�ͷ������ʱ�����Ҫ����[],�����ͷŵ���һ������,�����������
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
