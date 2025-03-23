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

//empty(); //�ж������Ƿ�Ϊ��
//capacity(); //����������
//size(); //����������Ԫ�صĸ���
//resize(int num); //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
////���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
//resize(int num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
////���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 11; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ��" << endl;
		cout << "����������Ϊ: " << v1.capacity() << endl;
		cout << "�����Ĵ�СΪ: " << v1.size() << endl;
	}

	v1.resize(15, 10);
	printVector(v1);
	cout << "����������Ϊ: " << v1.capacity() << endl;
	cout << "�����Ĵ�СΪ: " << v1.size() << endl;

}

//push_back(ele); //β������Ԫ��ele
//pop_back(); //ɾ�����һ��Ԫ��
//insert(const_iterator pos, ele); //������ָ��λ��pos����Ԫ��ele
//insert(const_iterator pos, int count, ele); //������ָ��λ��pos����count��Ԫ��ele
//erase(const_iterator pos); //ɾ��������ָ���Ԫ��
//erase(const_iterator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
//clear(); //ɾ������������Ԫ��
void test02()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	printVector(v1);

	v1.insert(v1.begin()+1, 9);
	printVector(v1);
	
	//v1.insert(v1.begin(), 9,0);
	v1.erase(v1.begin());
	v1.erase(v1.begin(), v1.end());
	printVector(v1);
	cout << "����Ϊ: " << v1.capacity() << endl;
}

//at(int idx); //��������idx��ָ������
//operator[]; //��������idx��ָ������
//front(); //���������е�һ������Ԫ��
//back(); //�������������һ������Ԫ��

void test03()
{
	vector<int>v1;//Ĭ�Ϲ���,�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " " ;
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << v1.front() << endl;
}

void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	cout << "��������ǰ: " << endl;
	printVector(v1);
	printVector(v2);

	v1.swap(v2);
	cout << "����������: " << endl;
	printVector(v1);
	printVector(v2);

	//ʵ�ʵ���;  -->  �����ڴ�ռ�
}


void test05()
{
	vector<int>v;
	v.reserve(5000);
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "����������Ϊ: " << v.capacity() << endl;
	cout << "�����Ĵ�СΪ: " << v.size() << endl;
	cout << num << endl;

}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();

	test05();


	system("pause");
	return EXIT_SUCCESS;
}
