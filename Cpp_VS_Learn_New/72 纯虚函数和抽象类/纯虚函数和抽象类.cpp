#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base {
public:
	//������������ǿ�Ƶ���������д�ú���,ʵ�ֶ�̬
	virtual void func() = 0;//�麯��=0,���麯��
	//һ������ֻҪ��һ�����麯��,��ô�����,�ͽг�����
	//�������޷�ʵ��������
	//�����������,������д�����еĴ��麯��,����Ҳ���ڳ�����
};

class Son :public Base{
public:
	virtual void func() {};//�ⶼ������д�˹�
};

void test01()
{
	//�������޷�ʵ��������
	//Base b;

	Base* base = new Son;
	base->func();//��̬�����ñ��ʾ�������һ�������ӿڸ���ͨ�û�,ͨ��һ������ָ��,������ָ��Ķ���ͬ,���Ե��ö��ֲ�ͬ(��д��)�ĺ���
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
