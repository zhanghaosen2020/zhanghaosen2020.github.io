#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>
//算数运算符

//其中negate是一元运算，其他都是二元运算
//仿函数原型：
//template<class T> T plus<T> //加法仿函数
//template<class T> T minus<T> //减法仿函数
//template<class T> T multiplies<T> //乘法仿函数
//template<class T> T divides<T> //除法仿函数
//template<class T> T modulus<T> //取模仿函数
//template<class T> T negate<T> //取反仿函数
void test01()
{
	//一元运算
	negate<int>n;//去反函数
	cout << n(10) << endl;

	//二元运算
	plus<int>p;//这里<>内只需要写一个int,因为二元运算时只允许同种类型的数据加减,也饿可以从仿函数的函数原型看出来
	cout << p(10, 40) << endl;

}


//实现关系对比
//仿函数原型：
//template<class T> bool equal_to<T> //等于
//template<class T> bool not_equal_to<T> //不等于
//template<class T> bool greater<T> //大于
//template<class T> bool greater_equal<T> //大于等于
//template<class T> bool less<T> //小于
//template<class T> bool less_equal<T> //小于等于
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(8);
	v.push_back(12);
	v.push_back(5);
	v.push_back(1);
	cout << "排序前:" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	sort(v.begin(), v.end());

	cout << "排序之后" << endl;
	sort(v.begin(), v.end(), greater<int>());//通过内建函数关系运算符,快速实现排序

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
