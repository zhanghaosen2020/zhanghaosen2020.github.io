#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//成员变量和成员函数分开存储
class Person {

};

class Person1 {

	int m_A;//非静态成员变量		属于类的对象上
	static int m_B;//静态成员变量	不属于类的对象上边
	void func() {}//非静态成员函数	不属于类的对象上边
	static void func1() {}//不属于类的对象上边
	//归根结底就是,非静态成员变量属于类的对象,其他的都不属于
};
int Person1::m_B = 0;

void test01()
{
	Person p;
	//空对象(类里边什么也不写)占有的内存空间:1个字节
	//c++编译器会给每个空对象也分配一个字节空间,是为了区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "sizeof p = " << sizeof(p) << endl;
}

void test02()
{
	Person1 p1;
	cout << "sizeof p1 = " << sizeof(p1) << endl;
}
int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
