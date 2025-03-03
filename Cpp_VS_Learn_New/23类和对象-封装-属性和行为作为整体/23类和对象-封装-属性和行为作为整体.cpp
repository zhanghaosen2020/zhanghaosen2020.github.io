#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//圆周率
const double PI = 3.14;

//设计一个圆类,求其周长
class Circle
{
	//访问权限
public:
	//属性
	//半径
	int m_r;

	//行为
	//获取圆周长
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
};

class Students {
public:
	//属性--学号和姓名
	int Id;
	string name;

	//行为--输出学生名字和学号
	void PrintIdName()
	{
		cout << "姓名: " << name <<"  "<< "学号: " << Id << endl;
	}

};
int main() {
	//通过圆类,创建具体的圆(对象)的过程叫实例化
	Circle c1;//具体出一个圆c1
	c1.m_r = 10;//画了一个半径为10 的圆
	cout << "圆的周长为: " << c1.calculateZC() << endl;

	Students student;
	student.name = "张三";
	student.Id = 3123104;
	student.PrintIdName();

	system("pause");
	return EXIT_SUCCESS;
}
