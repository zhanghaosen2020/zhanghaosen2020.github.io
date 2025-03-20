#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//cin.get() //一次只能读取一个字符,从缓冲区中读取一个字符
//cin.get(一个参数) //读一个字符
//cin.get(两个参数) //可以读字符串
//cin.getline()
//cin.ignore()
//cin.peek()
//cin.putback()

void test01()
{
	//cin.get() //一次只能读取一个字符,从缓冲区中读取一个字符
	char ch;
	//输入as(回车),第一次读:a  第二次读:s  第三次读:\n  第四次:阻塞(等待下一次输入)
	ch = cin.get();//从缓冲区中读取一个字符(若缓冲区中没有字符,则进入阻塞状态)
	cout << "ch = " << ch << endl;
	ch = cin.get();//从缓冲区中读取一个字符(若缓冲区中没有字符,则进入阻塞状态)
	cout << "ch = " << ch << endl;
	ch = cin.get();//从缓冲区中读取一个字符(若缓冲区中没有字符,则进入阻塞状态)
	cout << "ch = " << ch << endl;//
	ch = cin.get();//从缓冲区中读取一个字符(若缓冲区中没有字符,则进入阻塞状态)
	cout << "ch = " << ch << endl;
	//敲回车也会被换行符取走

	//cin.get(一个参数) //读一个字符
	char ch1;
	cin.get(ch);//这里和上边的不同在于,前者是返回值,后者是传参数

}

void test02()
{

	//cin.get(两个参数) //可以读字符串
	char buf[1024] = { 0 };
	//就相当于读取一行,因为他遇到换行才结束
	cin.get(buf, 1024);//第一个参数是从缓冲区中读得滴数据存放的地方,第二个参数传你能放的最大容量
	cout << "buf = " << buf <<endl ;//这样子取,换行符会遗留在缓冲区中
	char ch;
	ch = cin.get();//再取一次,才能将缓冲区清空
	if (ch == '\n')
	{
		cout << "换行符遗留在缓冲区中" << endl;
	}
	else
	{
		cout << "换行符未遗留在缓冲区中" << endl;
	}
}

void test03()
{
	//cin.getline()//取一行字符,和上边的使用一样
	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << "buf = " << buf << endl;	char ch;
	ch = cin.get();//再取一次,才能将缓冲区清空
	if (ch == '\n')//换行符不会遗留在缓冲区中
	{
		cout << "换行符遗留在缓冲区中" << endl;
	}
	else
	{
		cout << "换行符未遗留在缓冲区中" << endl;
	}
}

void test04()
{
	//cin.ignore(n);//默认会忽略缓冲区中的n个字符
	char buf[1024] = { 0 };
	cin.ignore(3); //忽略缓冲区当前n个字符
	cin.get(buf, 1024);
	cout << buf << endl;
}

void test05()
{
	char ch = cin.peek();
	cout << "偷窥缓冲区数据:" << ch << endl;
	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << buf << endl;
}

//判断输入的是一个数字还是字符串
void test06()
{
	cout << "请输入一个字符串或者数字:" << endl;
	char ch = cin.peek();
	if (ch >= '0' && ch <= '9')
	{
		int num;
		cin >> num;
		cout << "输入的是数字: " <<num<< endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "输入的是字符串: " << endl;
	}
}

//案例2:提示用户输入1-10之间的数字,如果输入有误,则重新输入
void test07()
{
	cout << "请输入1-10之间的数字: " << endl;
	while (true)
	{
		int num;
		cin >> num;
		if (num > 0 && num <= 10)
		{
			cout << "输入正确,输入的数字为: " << num << endl;
			break;
		}
		//cout << "输入有误，请重新输入" << endl;
		//1.重置标志位(缓冲区)
		cin.clear();
		//2.刷新缓冲区
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入1-10之间的数字: " << endl;
		//cout << "标志位: " << cin.fail() << endl;// 0为正常 ,1表示缓冲区有误
	}
	
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	system("pause");
	return EXIT_SUCCESS;
}
