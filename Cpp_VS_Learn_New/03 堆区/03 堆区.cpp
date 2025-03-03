#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//堆区,由程序员开辟释放,若不释放系统将在程序运行之后回收该内存(主要用new来开辟内存)
int* func()
{
	int* p = new int(10);
	return p;//此处返回的虽然是局部变量,但是该局部变量存放的是new在堆区开辟出来的空间(程序结束运行之后不会对其值有影响)
}

int main() {

	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;

	system("pause");
	return EXIT_SUCCESS;
}
