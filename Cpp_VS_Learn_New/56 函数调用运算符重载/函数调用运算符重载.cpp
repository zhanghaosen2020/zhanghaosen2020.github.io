#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyPrint {
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};
//�º����ǳ����,û�й̶���д��
//�ӷ���
class MyAdd {
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test01()
{
	MyPrint myPrint;
	myPrint("hahahha");//ͨ��()ֱ�ӵ���,�൱��
	myPrint.operator()("hahahah"); 
}

void test02()
{
	MyAdd myAdd;
	cout << myAdd(2, 3) << endl;
	//������������
	cout << MyAdd()(100, 100) << endl;//MyAdd()Ϊ��������,�ص��ǵ�ǰ��ִ����֮�������ͷ�

}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
