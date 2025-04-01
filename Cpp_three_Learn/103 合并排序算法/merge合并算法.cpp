#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>


void Print(int v)
{
	cout << v << " ";
}

void test01()
{
	vector<int>v1;
	vector<int>v2;
	//先往两个容器中有序地插入数据
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 9);
	}

	vector<int>vTarget;//你会不会想,这样的函数需要先给一个空间,而插入时不需要呢,或许插入之前,库函数会做内存检查,以便随时扩容,而merge这样的函数不会
	vTarget.resize(v1.size() + v2.size());//目标容器需要提前开辟空间
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), Print);
	cout << endl;

}

class Greater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前: " << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
	cout << "替换后: " << endl;
	//大于等于30的都替换为3000
	replace_if(v.begin(), v.end(), Greater30(), 3000);
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
