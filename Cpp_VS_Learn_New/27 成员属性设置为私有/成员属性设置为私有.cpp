#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//成员属性设置为私有
//1,可以自己控制读写权限

//2,对于写,可检查其数据的有效性


class Person {

public://虽然成员变量是私有的,但是我们可以通过给其提供一些公共的接口来调用
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		//m_Age = 0;
		return m_Age;
	}
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "输出的年龄有误!" << endl;
			return;
		}
		m_Age = age;
	}
	//设置情人
	void setLover(string lover)
	{
		m_Lover = lover;
	}
private:

	string m_Name;//姓名可读可写

	int m_Age;//年龄只读

	string m_Lover;//情人只写
};
int main() {
	Person p1;
	p1.setName("托尔斯泰");
	cout << "姓名: " << p1.getName() << endl;
	p1.setAge(1000);
	cout << "年龄: " << p1.getAge() << endl;
	p1.setLover("ehhe");
	system("pause");
	return EXIT_SUCCESS;
}
