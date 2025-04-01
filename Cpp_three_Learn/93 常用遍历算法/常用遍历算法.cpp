#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


//for_each遍历算法
//用普通函数
void Print01(int val)
{
	cout << val << " ";
}
//仿函数实现
class Print02
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), Print01);
	cout << endl;

	for_each(v.begin(), v.end(), Print02());//注意下边用仿函数来实现(观察上下的不同)
	cout << endl;
}


//transform搬运算法

class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}
};
int Transform(int val)
{
	return val;
}

void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), Print01);
	cout << endl;
	
	vector<int>vTarget;//注意搬运时,一定要给目标容器开辟空间
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), Transform);
	////transform(v.begin(), v.end(), vTarget.begin(), Transform());

	//末尾的Transform是给为了方便给搬运的数据做运算(操作使用的),可以是对象或者函数
	for_each(vTarget.begin(), vTarget.end(), Print02());
}

int main() {
//	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
