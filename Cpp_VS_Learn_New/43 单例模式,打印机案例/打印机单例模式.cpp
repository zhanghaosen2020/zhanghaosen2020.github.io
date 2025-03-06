#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Printer
{
public:
	static Printer* getInstance()
	{
		return singlePrinter;
	}
	void printText(string text)
	{
		cout << text << endl;
		m_Count++;
	}
	int m_Count=0;
private:
	Printer() {};
	Printer(const Printer&) {};

	static Printer* singlePrinter;

};
Printer* Printer::singlePrinter = new(Printer);
void test01()
{
	Printer* p1 = Printer::getInstance();//�õ�Ψһ��ָ��
	p1->printText("��ְ֤��");
	p1->printText("��ְ֤��");
	p1->printText("��ְ֤��");
	p1->printText("��ְ֤��");
	Printer* p2 = Printer::getInstance();
	//.����������������ڷ��ʽṹ��������ĳ�Ա��
	//->����ͷ�������������ڷ���ָ��ָ��Ľṹ��������ĳ�Ա
	cout << "��ӡ��ʹ�õĴ���Ϊ:" << p2->m_Count << endl;
	p2->printText("��ְ֤��");
	cout << "��ӡ��ʹ�õĴ���Ϊ:" << p2->m_Count << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
