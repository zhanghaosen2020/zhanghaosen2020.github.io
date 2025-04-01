#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

//Print类继承自std::binary_function<int, int, void>，这是一个函数适配器的基类，用于表示一个接受两个参数并返回void的二元函数。
//operator()重载了函数调用运算符，接受两个参数val和start，并将它们相加后打印出来。
//const修饰符表示该函数不会修改对象的任何成员变量，这使得该函数可以被const对象调用。
class Print:public binary_function<int,int,void >
{
public:
	void operator()(int val,int start)const
	{
		cout << val+start<< endl;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	cout << "请输入起始累加值: " << endl;
	int start = 0;
	cin >> start;
	
	for_each(v.begin(), v.end(), bind2nd(Print(),start));
}

//1,绑定bind2nd
//2,继承public_functin<int,int,void>
//3,加const


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
