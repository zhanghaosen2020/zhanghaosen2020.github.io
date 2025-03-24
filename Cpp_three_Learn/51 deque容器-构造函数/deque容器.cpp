#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>
#include<algorithm>
//deque构造函数

//函数试图使用 deque<int>::iterator 来遍历一个 const deque<int>& 类型的参数，这会导致编译错误。
// 原因在于，当你传递一个 const 容器时，你只能使用 const_iterator 来遍历它，而不是普通的 iterator。
void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 100;//容器的状态就不可修改了
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	
	deque<int>d2(d1.begin(),d1.end());//将d1容器里边的begin到end的值传入
	printDeque(d2);

	deque<int>d3(10, 9);
	printDeque(d3);

	deque<int>d4(d2);
	printDeque(d4);

}

//deque& operator=(const deque& deq); //重载等号操作符
//assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem); //将n个elem拷贝赋值给本身。

void test02()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);


	deque<int>d2;
	//d2 = d1;
	//printDeque(d2);

	d2.assign(d1.begin(), d1.end());
	printDeque(d2);

	d2.assign(9, 10);
	printDeque(d2);
}

void test03()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
		cout << "d1的大小为: " << d1.size()<<endl;
		cout << "d1大小重置之后结果为" << endl;
		d1.resize(3, 100);
		printDeque(d1);
		cout << "d1的大小为: " << d1.size() << endl;
	
		//数组变长之后
		d1.resize(15, 100);
		printDeque(d1);
		cout << "d1的大小为: " << d1.size() << endl;
	}

}

void test04()
{
	deque<int >dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(100);
	dq.push_front(200);
	printDeque(dq);
	dq.pop_front();
	dq.pop_back();
	printDeque(dq);

	dq.insert(dq.begin(), 1000);
	printDeque(dq);

	dq.insert(dq.begin()+2, 10,99);
	printDeque(dq);

	dq.clear();
	printDeque(dq);

}

void test05()
{
	deque<int >dq;
	dq.push_back(220);
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(100);
	dq.push_front(200);
	dq.push_front(8);
	printDeque(dq);


	//对于支持随机访问的迭代器容器,就可以直接利用sort算法对其实现排序
	sort(dq.begin(),dq.end());//默认是升序操作
	printDeque(dq);


}


int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}
