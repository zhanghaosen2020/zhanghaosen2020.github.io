#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<numeric>

void test01()
{
	vector<int>v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	//����3��һ��	--->	��ʼ���ۼ�ֵ
	int total = accumulate(v.begin(), v.end(), 0);
	cout << "total = " << total << endl;
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
