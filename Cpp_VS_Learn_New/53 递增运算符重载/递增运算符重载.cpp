#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//自定义整形
class MyInteger{

	friend ostream& operator<<(ostream& out, MyInteger& myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载++运算符号(前置)
	MyInteger& operator++()//返回引用是为了一直对一个数据递增,传值返回的话,会调用拷贝构造,产生新的对象
	{
		m_Num++;
		return *this;
	}

	//重载++运算符(后置)
	MyInteger operator++(int)//这里的int是一个占位参数,加了int之后,编译器就能区分前后置递增
	{//后置递增一定要返回其值而不是其引用,因为返回的temp是一个临时变量(会被释放),返回其引用就会导致非法操作
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		m_Num++;
		//再 将记录的结果返回
		return temp;
	}//注意区分前后置递增的区别

private:
	int m_Num;
};

void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
}

void test02()
{
	MyInteger myint;
	cout << (myint++)++ << endl;
}

ostream& operator<<(ostream& out,  MyInteger&  myint)
{
	out << myint.m_Num;
	return out;
}
int main() {
	test01();

	test02();
	system("pause");
	return EXIT_SUCCESS;
}
