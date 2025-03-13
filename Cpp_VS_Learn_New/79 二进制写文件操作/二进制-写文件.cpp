#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

//二进制文件 写文件
class Person {
public:
	char m_Name[64];//姓名
	int m_Age;//年龄
};

void test01()
{
	ofstream ofs("Person.txt", ios::out | ios::binary);
	//ofs.open("Person.txt", ios::out | ios::binary);

	Person p = { "张三",18 };//public且无基类和虚函数,因此可以{}初始化,类似于结构体的初始化
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
