#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����,�ɳ���Ա�����ͷ�,�����ͷ�ϵͳ���ڳ�������֮����ո��ڴ�(��Ҫ��new�������ڴ�)
int* func()
{
	int* p = new int(10);
	return p;//�˴����ص���Ȼ�Ǿֲ�����,���Ǹþֲ�������ŵ���new�ڶ������ٳ����Ŀռ�(�����������֮�󲻻����ֵ��Ӱ��)
}

int main() {

	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return EXIT_SUCCESS;
}
