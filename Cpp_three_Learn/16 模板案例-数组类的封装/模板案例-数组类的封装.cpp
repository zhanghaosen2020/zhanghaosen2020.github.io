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
	//�����в�\����\�����Ⱥ���
	//MyArray<int> arr1(5);
	//MyArray<int>arr2(arr1);

	//MyArray<int>arr3(100);//���������вι���һ��arr3,�ڴ��СΪ100,ͨ����������������,�ڲ����()�Ϳ��Խ�ʡ�ռ���
	//arr3 = arr1;

	MyArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "��ӡarr1�����: " ;
	printArr(arr1);

	cout << "arr1������Ϊ: " << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ: " << arr1.getSize() << endl;

	MyArray<int>arr2(arr1);
	cout << "��ӡarr2�����: ";
	printArr(arr2);

	arr2.Pop_Back();
	arr2.Pop_Back();
	arr2.Pop_Back();
	arr2.Pop_Back();
	cout << "��ӡarr2�����: ";
	printArr(arr2);
	cout << "arr2������Ϊ: " << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ: " << arr2.getSize() << endl;
}

//�����Զ�����������
class Person {
public:
	Person() {};//�����ṩĬ�Ϲ����ԭ����,�����ṩ���вι���,��������������Ҫ��ʵ�ֵĶ���,�����Ҫ�����ṩĬ�Ϲ��캯��
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
		cout << "����: " << arr[j].m_Name << " ����: " << arr[j].m_Age << endl;
	}
	cout << endl;
}
void test02()
{
	MyArray<Person>arr(10);

	Person p1("�����", 999);
	Person p2("��˽�", 888);
	Person p3("ɳ��", 777);
	Person p4("���", 99);
	Person p5("�˽�", 88);
	Person p6("��", 77);
	
	//�����ݶ����뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);

	printPersonArr(arr);
	cout << "arr������Ϊ: " << arr.getCapacity() << endl;
	cout << "arr�Ĵ�СΪ: " << arr.getSize() << endl;



}

int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
