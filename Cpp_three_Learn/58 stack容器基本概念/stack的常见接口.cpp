#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stack>
//栈的常见接口

void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "栈的元素个数为: " << s.size() << endl;

	while (!s.empty())//该栈不为空的情况
	{
		cout << "栈顶的元素为: " << s.top() << endl;
		s.pop();
	}
	cout << "栈的元素个数为: " << s.size()<<endl;
}

int main() {
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
