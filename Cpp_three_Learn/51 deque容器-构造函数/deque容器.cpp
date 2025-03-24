#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <deque>
#include<algorithm>
//deque���캯��

//������ͼʹ�� deque<int>::iterator ������һ�� const deque<int>& ���͵Ĳ�������ᵼ�±������
// ԭ�����ڣ����㴫��һ�� const ����ʱ����ֻ��ʹ�� const_iterator ������������������ͨ�� iterator��
void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 100;//������״̬�Ͳ����޸���
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	
	deque<int>d2(d1.begin(),d1.end());//��d1������ߵ�begin��end��ֵ����
	printDeque(d2);

	deque<int>d3(10, 9);
	printDeque(d3);

	deque<int>d4(d2);
	printDeque(d4);

}

//deque& operator=(const deque& deq); //���صȺŲ�����
//assign(beg, end); //��[beg, end)�����е����ݿ�����ֵ������
//assign(n, elem); //��n��elem������ֵ������

void test02()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);


	deque<int>d2;
	//d2 = d1;
	//printDeque(d2);

	d2.assign(d1.begin(), d1.end());
	printDeque(d2);

	d2.assign(9, 10);
	printDeque(d2);
}

void test03()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ��" << endl;
		cout << "d1�Ĵ�СΪ: " << d1.size()<<endl;
		cout << "d1��С����֮����Ϊ" << endl;
		d1.resize(3, 100);
		printDeque(d1);
		cout << "d1�Ĵ�СΪ: " << d1.size() << endl;
	
		//����䳤֮��
		d1.resize(15, 100);
		printDeque(d1);
		cout << "d1�Ĵ�СΪ: " << d1.size() << endl;
	}

}

void test04()
{
	deque<int >dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(100);
	dq.push_front(200);
	printDeque(dq);
	dq.pop_front();
	dq.pop_back();
	printDeque(dq);

	dq.insert(dq.begin(), 1000);
	printDeque(dq);

	dq.insert(dq.begin()+2, 10,99);
	printDeque(dq);

	dq.clear();
	printDeque(dq);

}

void test05()
{
	deque<int >dq;
	dq.push_back(220);
	dq.push_back(10);
	dq.push_back(20);
	dq.push_front(100);
	dq.push_front(200);
	dq.push_front(8);
	printDeque(dq);


	//����֧��������ʵĵ���������,�Ϳ���ֱ������sort�㷨����ʵ������
	sort(dq.begin(),dq.end());//Ĭ�����������
	printDeque(dq);


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
