#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//binary_search//���ֲ���,��������������
void test01()
{
	vector<int>v;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(i);
	}
	//�����Ƿ���9Ԫ��
	bool ret = binary_search(v.begin(), v.end(),90);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
