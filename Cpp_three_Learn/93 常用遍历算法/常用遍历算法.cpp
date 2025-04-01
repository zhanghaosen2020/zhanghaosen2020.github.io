#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>


//for_each�����㷨
//����ͨ����
void Print01(int val)
{
	cout << val << " ";
}
//�º���ʵ��
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

	for_each(v.begin(), v.end(), Print02());//ע���±��÷º�����ʵ��(�۲����µĲ�ͬ)
	cout << endl;
}


//transform�����㷨

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
	
	vector<int>vTarget;//ע�����ʱ,һ��Ҫ��Ŀ���������ٿռ�
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), Transform);
	////transform(v.begin(), v.end(), vTarget.begin(), Transform());

	//ĩβ��Transform�Ǹ�Ϊ�˷�������˵�����������(����ʹ�õ�),�����Ƕ�����ߺ���
	for_each(vTarget.begin(), vTarget.end(), Print02());
}

int main() {
//	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
