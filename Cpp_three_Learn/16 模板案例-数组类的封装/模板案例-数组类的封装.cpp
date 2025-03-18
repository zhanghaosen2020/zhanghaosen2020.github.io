#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.hpp"

void printArr(MyArray<int>& arr)
{
	for (int j = 0; j < arr.getSize(); j++)
	{
		cout << " " << arr[j];
	}
	cout << endl;
}


void test01()
{
	//测试有参\拷贝\析构等函数
	//MyArray<int> arr1(5);
	//MyArray<int>arr2(arr1);

	//MyArray<int>arr3(100);//这里我们有参构造一个arr3,内存大小为100,通过下面的运算符重载,内部清空()就可以节省空间了
	//arr3 = arr1;

	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "打印arr1的输出: " ;
	printArr(arr1);

	cout << "arr1的容量为: " << arr1.getCapacity() << endl;
	cout << "arr1的大小为: " << arr1.getSize() << endl;

	MyArray<int>arr2(arr1);
	cout << "打印arr2的输出: ";
	printArr(arr2);

	arr2.Pop_Back();
	arr2.Pop_Back();
	arr2.Pop_Back();
	arr2.Pop_Back();
	cout << "打印arr2的输出: ";
	printArr(arr2);
	cout << "arr2的容量为: " << arr2.getCapacity() << endl;
	cout << "arr2的大小为: " << arr2.getSize() << endl;
}

//测试自定义数据类型
class Person {
public:
	Person() {};//这里提供默认构造的原因是,下面提供了有参构造,而后续代码中需要空实现的对象,因而需要主动提供默认构造函数
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArr(MyArray<Person>arr)
{
	for (int j = 0; j < arr.getSize(); j++)
	{
		cout << "姓名: " << arr[j].m_Name << " 年龄: " << arr[j].m_Age << endl;
	}
	cout << endl;
}
void test02()
{
	MyArray<Person>arr(10);

	Person p1("孙悟空", 999);
	Person p2("猪八戒", 888);
	Person p3("沙悟净", 777);
	Person p4("悟空", 99);
	Person p5("八戒", 88);
	Person p6("悟净", 77);
	
	//将数据都插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);

	printPersonArr(arr);
	cout << "arr的容量为: " << arr.getCapacity() << endl;
	cout << "arr的大小为: " << arr.getSize() << endl;



}

int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
