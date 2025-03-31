#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class GetFive
{
public:
	bool operator()(int val)const//参数只有一个,我们称之为一元谓词
	{
		return val > 5;
	}
};
void test01()
{
	vector<int >v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//找到容器中大于6的数据
	vector<int>::iterator it = find_if(v.begin(), v.end(), GetFive());
	if (it != v.end())
	{
		cout << "找到了" << ",数字为:" << *it << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
 