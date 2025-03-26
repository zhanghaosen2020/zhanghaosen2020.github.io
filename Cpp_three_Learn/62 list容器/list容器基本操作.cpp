#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>




void printList(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}


//list的构造函数
//list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
//list(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
//list(n, elem); //构造函数将n个elem拷贝给本身。
//list(const list& lst); //拷贝构造函数。
void test01()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	printList(l);
	
	list<int>l1(l.begin(), l.end());
	printList(l1);

	list<int>l2(10, 9);
	printList(l2);

	list<int>l3(l2);
	printList(l3);
}

//assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem); //将n个elem拷贝赋值给本身。
//list& operator=(const list& lst); //重载等号操作符
//swap(lst); //将lst与本身的元素互换。

//赋值操作
void test02()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList(l);

	list<int>l1;
	l1.assign(l.begin(), l.end());
	printList(l1);

	l1.assign(10, 2);
	printList(l1);

	l.swap(l1);

	printList(l);
	l1 = l;
	printList(l1);


}

int main() {
	test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
