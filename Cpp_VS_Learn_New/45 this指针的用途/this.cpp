#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1.解决名称冲突
class Person {
public:
	Person(int age)
	{
		//age = age;//这个样子写,会导致成员变量age(因而命名要规范m_Age)不会被赋值,形参age传给形参age了
		this->age = age;//this指针指向 被调用的成员函数所属的对象
		//谁调用了这个有参构造,this就指向谁,这里指向p1
	}

	Person& PersonAddPerson(Person &p)
	{
		this->age += p.age;
		return *this;//若,你要返回本体,你需要用引用的方式返回;如果你用值的方式返回会拷贝构造一个和原对象不同的对象
	}

	int age;
};
void test01()
{
	Person p1(18);
	cout << "age = " << p1.age << endl;
}

//2.返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(10);
	//链式编程思想
	cout << "p1+p2 = " << p1.PersonAddPerson(p2).PersonAddPerson(p1).age;

}
int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
