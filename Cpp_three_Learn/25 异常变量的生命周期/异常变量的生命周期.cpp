#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�쳣�������������

class myException {
public:
	myException()
	{
		cout << "�쳣�Ĺ��캯��" << endl;
	}

	myException(const myException& e)
	{
		cout << "�쳣�Ŀ������캯��" << endl;
	}
	~myException()
	{
		cout << "�쳣����������" << endl;
	}
};

void func1()
{
	throw myException();
		 
}

void test01()
{
	try
	{
		func1();
	}
	//�׳�:throw myException();		����:	catch (myException e) �׳��쳣�ĵط�����ÿ������캯��,��Ϊ��������ἰʱ����,�����µĶ���
	catch (myException e)
	{
		cout << "�ҵ��쳣����" << endl;
	}
}


void func2()
{
	throw myException();

}

void test02()
{
	try
	{
		func2();
	}
	//�׳�:throw myException();		����:	catch (myException &e) ��������������������,�൱�ڸ���������ȡ�˱���,(�����ÿ�������),�������������ӳ���
	catch (myException &e)
	{
		cout << "�ҵ��쳣����" << endl;
	}
}


void func3()
{
	throw &myException();//��Ϊ�õ�ָ��ȥ���ն���,������Ҫ�׳���������ĵ�ַ

}

void test03()
{
	try
	{
		func3();
	}
	//�׳�:throw myException();		����:	catch (myException e) �׳��쳣�ĵط�����ÿ������캯��,��Ϊ��������ἰʱ����,�����µĶ���
	catch (myException *e)
	{
		cout << "�ҵ��쳣����" << endl;
	}
}

int main() {

	//test01();
	//test02();//�Ƽ��ķ�ʽ
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
