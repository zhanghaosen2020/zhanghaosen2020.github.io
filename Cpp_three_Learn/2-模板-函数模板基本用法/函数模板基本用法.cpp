#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����ģ��

//�������ν�������
void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//�������������ͺ���
void swapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T>//����һ��ģ��,���߱�������������н����ŵ�T��Ҫ����
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//2,ģ�����Ҫȷ����T����������,�ſ���ʹ��
template<class T>
void func()
{
	cout << "func�����ĵ���" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//1,�Զ������Ƶ�,�����Ƶ���һ�µ���������T,�ſ�ʹ��
	//mySwap(a, b);
	//mySwap(a, c);//����,���Ͳ�һ��

	//2,��ʾָ������
	mySwap<int>(a, b);
	cout << "a = " << a << " b = " << b << endl;
}

void test02()
{
	//func();//����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
	func<int>();//������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
