#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��Ա�����ͳ�Ա�����ֿ��洢
class Person {

};

class Person1 {

	int m_A;//�Ǿ�̬��Ա����		������Ķ�����
	static int m_B;//��̬��Ա����	��������Ķ����ϱ�
	void func() {}//�Ǿ�̬��Ա����	��������Ķ����ϱ�
	static void func1() {}//��������Ķ����ϱ�
	//�����׾���,�Ǿ�̬��Ա����������Ķ���,�����Ķ�������
};
int Person1::m_B = 0;

void test01()
{
	Person p;
	//�ն���(�����ʲôҲ��д)ռ�е��ڴ�ռ�:1���ֽ�
	//c++���������ÿ���ն���Ҳ����һ���ֽڿռ�,��Ϊ�����ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "sizeof p = " << sizeof(p) << endl;
}

void test02()
{
	Person1 p1;
	cout << "sizeof p1 = " << sizeof(p1) << endl;
}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
