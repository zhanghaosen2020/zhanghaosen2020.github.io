#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
//vector�������캯��
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//vector& operator=(const vector& vec); //���صȺŲ�����
//assign(beg, end); //��[beg, end)�����е����ݿ�����ֵ������
//assign(n, elem); //��n��elem������ֵ������

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//1,�ȺŸ�ֵ����
	vector<int>v2;
	v2 = v1;
	printVector(v1);

	//2,assign(begin ,end);
	vector<int>v3;
	v3.assign(v1.begin(), v1.begin() + 3);
	printVector(v3);

	//3,
	vector<int>v4;
	v4.assign(3, 5);
	printVector(v4);




}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
