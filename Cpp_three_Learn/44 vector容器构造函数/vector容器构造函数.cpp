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

void test01()
{
	vector<int>v1;//Ĭ�Ϲ���,�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	//��������ķ�ʽ���µ���������ֵ
	vector<int>v2(v1.begin(), v1.end());//��v1�ӿ�ͷ����β�����ݴ���v2��;
	//vector<int>v2(v1.begin(), v1.begin()+4);//��ָ�������ٸ�
	printVector(v2);

	//n��elem��ʽ����
	vector<int>v3(10, 100);//�������д���10��100
	printVector(v3);

	//��������
	vector<int>v4(v3);
	printVector(v4);
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
