#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��������(�º���)

//1,����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class MyAdd {
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test01()
{
	MyAdd myAdd;
	cout << myAdd(10, 20) << endl;//����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
}


//2,�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator()(string str)
	{
		cout << str << endl;
		count++;//����ͳ�Ʒº����ĵ��ô���
	}
	int count;
};
void test02()
{
	MyPrint myPrint;
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	myPrint("hi,Tim");
	cout << "myPrint�ĵ��ô���Ϊ:" << myPrint.count << endl;
}

//3,�������������Ϊ��������
void print(MyPrint& mp, string str)
{
	mp(str);
}
void test03()
{
	MyPrint myPrint;
	print(myPrint, "�ǺǺ�!!!");
}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
