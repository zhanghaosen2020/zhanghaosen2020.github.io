#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"game1.h"
#include"game2.h"
using namespace std;

//1,命名空间:可以解决名称冲突问题
void test01()
{
	LOL::goAtk();
	KingGlory::goAtk();
}

//2,命名空间下可以存储,变量\函数\结构体\类等
namespace A
{
	int m_A = 10;
	void func();
	struct Person {};
	class Animal{};
}

//3,命名空间必须声明在全局作用域下
void test02()
{
	/*namespace A
	{
	}*///错误的命名方式(不能定义在局部中)
}

//4,命名空间可以嵌套命名空间
namespace A 
{
	int m_a = 10;
	namespace B
	{
		int m_a = 20;
	}
}
void test03()
{
	cout << A::m_a << endl;
	cout << A::B::m_a << endl;

}
//命名空间是开放的可以随时向空间中添加新成员
namespace A
{
	int m_b = 30;
}
void test04()
{
	cout << A::m_a << endl;
	cout << A::B::m_a << endl;
	cout << A::m_b << endl;
}

//6,命名空间可以是匿名的  (因为命名空间必须是全局的,所以当匿名时,可以将其中的变量理解为全局变量)
namespace
{
	int m_C = 100;
	int m_D = 200;
}
void test05()
{
	cout << m_C << endl;
	cout << ::m_D << endl;
}

//7,命名空间可以取别名
namespace veryLongName
{
	int m_E = 1000;
}
void test06()
{
	namespace veryShrotName = veryLongName;
	cout << veryLongName::m_E << endl;//这个命名空间太长了,嵌套了的话就更加长了
	cout << veryShrotName::m_E << endl;//用这个短的名字

}

int main() {

	/*test01();
	test03();
	test04();*/
	test05();
	system("pause");
	return EXIT_SUCCESS;
}
                                                                                            