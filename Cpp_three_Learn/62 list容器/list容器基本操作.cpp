#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>




void printList(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}


//list�Ĺ��캯��
//list<T> lst; //list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
//list(beg, end); //���캯����[beg, end)�����е�Ԫ�ؿ���������
//list(n, elem); //���캯����n��elem����������
//list(const list& lst); //�������캯����
void test01()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	printList(l);
	
	list<int>l1(l.begin(), l.end());
	printList(l1);

	list<int>l2(10, 9);
	printList(l2);

	list<int>l3(l2);
	printList(l3);
}

//assign(beg, end); //��[beg, end)�����е����ݿ�����ֵ������
//assign(n, elem); //��n��elem������ֵ������
//list& operator=(const list& lst); //���صȺŲ�����
//swap(lst); //��lst�뱾���Ԫ�ػ�����

//��ֵ����
void test02()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList(l);

	list<int>l1;
	l1.assign(l.begin(), l.end());
	printList(l1);

	l1.assign(10, 2);
	printList(l1);

	l.swap(l1);

	printList(l);
	l1 = l;
	printList(l1);


}

int main() {
	test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
