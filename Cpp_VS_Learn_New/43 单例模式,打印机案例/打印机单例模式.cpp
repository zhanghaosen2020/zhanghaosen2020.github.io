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
	Printer* p1 = Printer::getInstance();//拿到唯一的指针
	p1->printText("入职证明");
	p1->printText("入职证明");
	p1->printText("入职证明");
	p1->printText("入职证明");
	Printer* p2 = Printer::getInstance();
	//.（点操作符）：用于访问结构体或类对象的成员。
	//->（箭头操作符）：用于访问指针指向的结构体或类对象的成员
	cout << "打印机使用的次数为:" << p2->m_Count << endl;
	p2->printText("入职证明");
	cout << "打印机使用的次数为:" << p2->m_Count << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
