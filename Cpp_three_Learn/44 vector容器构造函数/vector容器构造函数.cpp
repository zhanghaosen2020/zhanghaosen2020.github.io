#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
//vector容器构造函数
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int>v1;//默认构造,无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//利用区间的方式给新的容器对象赋值
	vector<int>v2(v1.begin(), v1.end());//把v1从开头到结尾的数据传入v2中;
	//vector<int>v2(v1.begin(), v1.begin()+4);//可指定传多少个
	printVector(v2);

	//n个elem方式构造
	vector<int>v3(10, 100);//向容器中传入10个100
	printVector(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector(v4);
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
