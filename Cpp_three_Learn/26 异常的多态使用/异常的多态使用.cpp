#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣�Ļ���
class BaseException
{
public:
	virtual void printError() = 0;
};

//��ָ���쳣
class NULLPointer :public BaseException
{
public:
	virtual void printError()
	{
		cout << "��ָ���쳣" << endl;
	}
};

//Խ���쳣
class OUTOfRange :public BaseException
{
public:
	virtual void printError()
	{
		cout << "����Խ���쳣" << endl;
	}
};

void func1()
{
	throw NULLPointer();
}

void  test01()
{
	try
	{
		func1();
	}
	/*catch (NULLPointer& e)*/
	catch(BaseException &e)//�����û�������ȥ�����������,���ɶ�̬
	{
		e.printError();
	}
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
