#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"test.h"

//�����ʽ1:���߱���������C���Եķ�ʽ����show����(����Ҫע�͵�ͷ�ļ�),�÷�����̫��
//#include"test.h"//test.h�Ѿ�����show������,ע�͵�,���û��ظ�
//extern "C" void show();

//extern "C"����Ҫ��;:��C++����C����,(��Ϊcpp�еĺ�����������,�ᵼ�º���������,�Ӷ��Ҳ���c�еĺ���ʵ��,�������Ӵ���)

//�����ʽ2:��.h�ļ�����Ӵ���


void test01()
{
	show();//�޷��������ⲿ����,���ڱ������ӽ׶γ��ֵĴ���
	//���show()��������.c��������,�ᵼ��cpp��c��ͬһ���������β�ͬ,�Ҳ�����Ӧ�ĺ���ʵ��
}

int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
