#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void test01()
{
	//1,包含头文件

	//2,创建对象
	ifstream ifs;
	//3,打开文件,并且判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//4.读数据
	//第一种
	//char buf[1024] = { 0 };
	//while (ifs >> buf)//数据读完之后会返回一个0
	//{
	//	cout << buf << endl;
	//}
	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}

	//第三种
	//string buf;
	//while (string::getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}
	// 第四种
	char c;//一个字符一个字符读(慢),推荐第二种
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	//5,关闭文件
	ifs.close();
}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
