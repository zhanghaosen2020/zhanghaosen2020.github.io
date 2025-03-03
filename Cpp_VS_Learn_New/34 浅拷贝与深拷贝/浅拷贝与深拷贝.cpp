#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//将浅拷贝会暴露出来的问题表现出来
class Person {
public:
	int m_Age;
	int* m_Height;
	Person()
	{

		cout << "这是一个默认无参构造函数" << endl;
	}

	Person(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);//创建在堆区的数据需要由程序员自己释放
		cout << "这是一个有参构造函数" << endl;
	}

	~Person()
	{
		//析构,将堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "这是一个析构函数函数" << endl;
	}

	//这里需要自己实现一个拷贝构造函数,来解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "这是一个拷贝函数函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//这是编译器默认实现浅拷贝时的操作
		//深拷贝操作
		m_Height = new int(*p.m_Height);//新开辟一个空间来存储,使得之后的析构不再释放同一块空间的内存造成崩盘

	}

};

void test01()
{
	Person p(18,180);//有参构造
	cout << "年龄: " << p.m_Age << "身高: " << *p.m_Height << endl;
	Person p1(p);//编译器所给的拷贝构造
	cout << "年龄: " << p1.m_Age << "身高: " << *p1.m_Height << endl;

}

int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
