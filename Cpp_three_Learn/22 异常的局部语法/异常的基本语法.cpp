#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class myException
{
public:
	void printError()
	{
		cout << "���Լ����쳣" << endl;
	}
};
//�쳣�Ļ����﷨
int myDivision(int a, int b)
{
	if (b == 0)
	{
	//	return -1;//C���Է���ֵֻ��һ��,�޷�����(�ǳ���Ϊ0,���ǽ��Ϊ-1),���ܻ���ֶ�����,���û��һ��ͳһ�ı�־(���˷���0��ʾ�쳣,ÿ���˶���ͬ)
		//throw - 1;//һ�㶼�ǵײ��׳�
		//throw 3.14;
		//throw 'a';
		throw myException();//�׳�һ��myException��  �����쳣����
	}
	return a / b;
}
void test01()
{
	int a = 10;
	int b = 0;

	//if (ret == -1)
	//{
	//	cout << "��������쳣" << endl;
	//}
	
	//�ڿ��ܳ����쳣�ĵط�,д�뵽try�������
	try
	{
		int ret = myDivision(a, b);
	}
	catch (int)
	{
		cout << "int�����쳣����" << endl;
	}
	catch (double)
	{
		throw;//cpp�еĳ����쳣������������,�չ�Ҫ����,����������ͻᵼ�³������
		cout << "double�����쳣����" << endl;
	}
	catch (myException e)
	{
		e.printError();
	}
	catch (...)// ...�����ȥint,double֮����������͵��쳣����
	{
		cout << "���������쳣����" << endl;
	}
}


int main() {

	try {
		test01();
	}
	catch (double)
	{
		cout << "main�����е�double�쳣����" << endl;
	}
	//������û���κεط������쳣,ϵͳ���Զ�����terminate����,ʹ������ֹ
	system("pause");
	return EXIT_SUCCESS;
}
