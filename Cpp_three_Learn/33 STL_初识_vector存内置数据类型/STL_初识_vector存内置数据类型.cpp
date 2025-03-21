#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
// STL_初识_vector存内置数据类型


void MyPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	//创建一个 vector容器,数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//通过迭代器访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();//起始迭代器,指向容器中的第一个元素
	//vector<int>::iterator itEnd = v.end();//结束迭代器,指向容器中最后一个元素的下一个位置

	////第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//第二种遍历方式   相当于把上边的写法汇总写一下
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}*/

	//第三种遍历方式,使用STL中提供的标准遍历算法,注意包含头文件 algorithm
	for_each(v.begin(), v.end(), MyPrint);//可以试着去读for_each的底层
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
