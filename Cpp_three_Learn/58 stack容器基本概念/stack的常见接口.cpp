#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stack>
//ջ�ĳ����ӿ�

void test01()
{
	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << "ջ��Ԫ�ظ���Ϊ: " << s.size() << endl;

	while (!s.empty())//��ջ��Ϊ�յ����
	{
		cout << "ջ����Ԫ��Ϊ: " << s.top() << endl;
		s.pop();
	}
	cout << "ջ��Ԫ�ظ���Ϊ: " << s.size()<<endl;
}

int main() {
	test01();


	system("pause");
	return EXIT_SUCCESS;
}
