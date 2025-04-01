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
	//������������������ز�������
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 9);
	}

	vector<int>vTarget;//��᲻����,�����ĺ�����Ҫ�ȸ�һ���ռ�,������ʱ����Ҫ��,�������֮ǰ,�⺯�������ڴ���,�Ա���ʱ����,��merge�����ĺ�������
	vTarget.resize(v1.size() + v2.size());//Ŀ��������Ҫ��ǰ���ٿռ�
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
	cout << "�滻ǰ: " << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
	cout << "�滻��: " << endl;
	//���ڵ���30�Ķ��滻Ϊ3000
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
