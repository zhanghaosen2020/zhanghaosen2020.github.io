#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class GetFive
{
public:
	bool operator()(int val)const//����ֻ��һ��,���ǳ�֮ΪһԪν��
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
	//�ҵ������д���6������
	vector<int>::iterator it = find_if(v.begin(), v.end(), GetFive());
	if (it != v.end())
	{
		cout << "�ҵ���" << ",����Ϊ:" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
 