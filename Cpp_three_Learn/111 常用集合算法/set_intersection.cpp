#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>
#include<algorithm>

void Print(int v)
{
	cout << v << " ";
}

void test01()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	
	for_each(v1.begin(), v1.end(), Print);
	cout << endl;
	for_each(v2.begin(), v2.end(), Print);
	cout << endl;

	//先来一个目标集合,来存放两个集合的交集
	vector<int>vTarget; //求交集的两个集合必须的有序序列
	vTarget.resize(min(v1.size(), v2.size()));//取小(就是交集的最大值)
	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	//for_each(vTarget.begin(), vTarget.end(), Print);//5 6 7 8 9 0 0 0 0 0输出
	//注意观察上边,下边的itEnd返回目标容器的最后一个元素的迭代器地址
	cout << "交集为:" << endl;
	for_each(vTarget.begin(), itEnd, Print);


	cout << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
