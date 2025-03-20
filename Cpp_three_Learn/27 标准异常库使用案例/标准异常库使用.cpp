#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>

//系统标准异常的使用(以out_of_range为例子)
class Person
{
public:
	Person(int age)
	{
		if (age > 100 || age < 0)
		{
			throw out_of_range("超出年龄范围!");
		}
		else
		{
			this->m_Age = age;
		}
	}

	int m_Age;
};

void test01()
{
	try {
		Person(1000);
	}
	//所有标准异常的父类对象都是exception
	catch(exception& e)//这里一定要记住,(用多态)就需要用父类的引用去接子类对象
	{
		cout << e.what() << endl;//用e.what()去输出对应的错误提示信息
	}
}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
