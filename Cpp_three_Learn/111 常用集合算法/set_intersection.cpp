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

	//����һ��Ŀ�꼯��,������������ϵĽ���
	vector<int>vTarget; //�󽻼����������ϱ������������
	vTarget.resize(min(v1.size(), v2.size()));//ȡС(���ǽ��������ֵ)
	//����Ŀ�����������һ��Ԫ�صĵ�������ַ
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	//for_each(vTarget.begin(), vTarget.end(), Print);//5 6 7 8 9 0 0 0 0 0���
	//ע��۲��ϱ�,�±ߵ�itEnd����Ŀ�����������һ��Ԫ�صĵ�������ַ
	cout << "����Ϊ:" << endl;
	for_each(vTarget.begin(), itEnd, Print);


	cout << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
