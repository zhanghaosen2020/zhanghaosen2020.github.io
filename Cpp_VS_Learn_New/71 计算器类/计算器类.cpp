#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//普通写法
class Calculator {
public:
	int getResult(string opr)
	{
		if (opr == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (opr == "-")
		{
			return m_Num1 - m_Num2;
		}
		//想要拓展新功能,需要修改源码
		//在开发中,提倡 开闭原则(对拓展进行开放,对修改关闭)
	}

	int m_Num1;//操作数1
	int m_Num2;//操作数2

};

void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
}

//利用多态实现计算器
//实现一个计算器的抽象类(基类)
class AbsentCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//计算器加法类
class AddCalculator :public AbsentCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//计算器减法类
class SubCalculator :public AbsentCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

int doJiSuan(AbsentCalculator& abcalculaotr)
{
	return abcalculaotr.getResult();
}

void test02()
{
	//多态使用条件
	//父类的指针或者引用指向子类对象

	//加法计算
	AbsentCalculator* abc = new AddCalculator;//父类指针指向子类对象
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;

	//用完后释放
	delete abc;

	//减法计算
	abc = new SubCalculator;
	abc->m_Num2 = 10;
	abc->m_Num1 = 100;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;


	AddCalculator add;
	add.m_Num2 = 10;
	add.m_Num1 = 100;
	add.getResult();
	cout << add.m_Num1 << " + " << add.m_Num2 << " = " << doJiSuan(add) << endl;

}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
