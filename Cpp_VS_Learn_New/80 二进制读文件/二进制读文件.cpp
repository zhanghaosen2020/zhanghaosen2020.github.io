#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

//文件输入流对象 可以通过read函数，以二进制方式读数据
#include <string>
class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test01()
{
	ifstream ifs("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}
int main() {
	test01();
	system("pause");
	return 0;
}