#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<iomanip>

void test01()
{
	//cout.put('h').put('e');//每次输出一个字符,提供了链式编程,麻烦不好用
	/*char buf[1024] = "hellow world";
	cout.write(buf, strlen(buf));*///麻烦不好用


	//格式化输出的一些控制符
	int number = 99;
	cout.width(20);//设置宽度
	cout.fill('*');  //设置填充
	cout.setf(ios::left);//左对齐
	cout.unsetf(ios::dec); //卸载十进制
	cout.setf(ios::hex);//安装十六进制
	cout.setf(ios::showbase);//显示进制基数  0x  
	cout.unsetf(ios::hex);//卸载十六进制
	cout.setf(ios::oct);//安装八进制
	cout << number << endl;
}

void test02() {

	int number = 99;
	cout << setw(20)//设置宽度
		<< setfill('~')//设置填充
		<< setiosflags(ios::showbase)
		<< setiosflags(ios::left)//左对齐
		<< hex//安装十六进制
		<< number
		<< endl;

}
int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
