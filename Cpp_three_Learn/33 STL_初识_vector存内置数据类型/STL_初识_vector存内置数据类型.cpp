#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
// STL_��ʶ_vector��������������


void MyPrint(int val)
{
	cout << val << endl;
}

void test01()
{
	//����һ�� vector����,����
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//ͨ�����������������е�����
	//vector<int>::iterator itBegin = v.begin();//��ʼ������,ָ�������еĵ�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end();//����������,ָ�����������һ��Ԫ�ص���һ��λ��

	////��һ�ֱ�����ʽ
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//�ڶ��ֱ�����ʽ   �൱�ڰ��ϱߵ�д������дһ��
	/*for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}*/

	//�����ֱ�����ʽ,ʹ��STL���ṩ�ı�׼�����㷨,ע�����ͷ�ļ� algorithm
	for_each(v.begin(), v.end(), MyPrint);//��������ȥ��for_each�ĵײ�
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
