#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//binary_search//二分查找,必须是有序数列
void test01()
{
	vector<int>v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(i);
	}
	//查找是否有9元素
	bool ret = binary_search(v.begin(), v.end(),90);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
