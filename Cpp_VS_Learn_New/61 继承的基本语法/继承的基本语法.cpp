#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//Javaҳ��
//class Java
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...(���������б�)" << endl;
//	}
//	void content()
//	{
//		cout << "JAVAѧ����Ƶ" << endl;
//	}
//};
//
//class Python
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
//	}
//	void footer()
//	{
//		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...(���������б�)" << endl;
//	}
//	void content()
//	{
//		cout << "Pythonѧ����Ƶ" << endl;
//	}
//};

//void test01()
//{
//	//Javaҳ��
//	cout << "Java������Ƶҳ�����£� " << endl;
//	Java ja;
//	ja.header();
//	ja.footer();
//	ja.left();
//	ja.content();
//	cout << "--------------------" << endl;
//	//Pythonҳ��
//	cout << "Python������Ƶҳ�����£� " << endl;
//	Python py;
//	py.header();
//	py.footer();
//	py.left();
//	py.content();
//	cout << "--------------------" << endl;
//}

//�ü̳���ʵ��ҳ��

//����ҳ����
class BasePage {
public:
	void header()
		{
			cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
		}
		void footer()
		{
			cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
		}
		void left()
		{
			cout << "Java,Python,C++...(���������б�)" << endl;
		}
};
//Javaҳ��
class Java :public BasePage {
public:
	void content()
	{
		cout << "Javaѧ������" << endl;
	}
};

//�̳еĺô�����:�����ظ��Ĵ���
//�﷨:class ���� :�̳з�ʽ  ����
//����Ҳ��Ϊ������,����Ҳ��Ϊ����

class CPP :public BasePage {
public:
	void content()
	{
		cout << "CPPѧ������" << endl;
	}
};


void test01()
{
	//Javaҳ��
	cout << "Java������Ƶҳ�����£� " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;
	//Pythonҳ��
	cout << "CPP������Ƶҳ�����£� " << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();
	cout << "--------------------" << endl;
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
