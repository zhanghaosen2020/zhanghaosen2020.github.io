#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣�Ľӿ�����//��С������û��д�κ����͵�ʱ��,�ʹ��������׳��κ��쳣	
void func()throw(int,double)//����ֻ�����׳�int���͵��쳣,�ڸ߰汾��VS֮��,������ָ���׳��쳣�����͵�,����������������������,�ͻ���ɳ����ж�
{
	throw 3.14;
}

int main() {

	try
	{
		func();
	}
	catch (int)
	{
		cout << "int�����쳣����" << endl;
	}
	catch (double)
	{
		cout << "double���͵��쳣����" << endl;
	}
	catch (...)
	{
		cout << "�������͵��쳣����" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}
