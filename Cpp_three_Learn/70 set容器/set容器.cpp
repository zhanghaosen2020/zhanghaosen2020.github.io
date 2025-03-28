#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<set> 

void printSet(set<int>&s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout <<endl;
}

//���죺
//set<T> st; //Ĭ�Ϲ��캯����
//set(const set& st); //�������캯��
//��ֵ��set& operator=(const set& st); //���صȺŲ�����
void test01()
{
	set<int>s1;//Ĭ�Ϲ���

	//set��������������insert
	s1.insert(10);
	s1.insert(5);
	s1.insert(1);
	s1.insert(4);
	s1.insert(9);
	//s1.insert(4);//�����ظ�������,������,���ǻ����ʧ��

	printSet(s1);

	set<int>s2(s1);//�������캯��
	printSet(s2);

	set<int>s3;
	s3 = s2;//���ظ�ֵ��
	printSet(s3);
}

//size(); //����������Ԫ�ص���Ŀ
//empty(); //�ж������Ƿ�Ϊ��
//swap(st); //����������������

void test02()
{
	set<int>s1;//Ĭ�Ϲ���

	//set��������������insert
	s1.insert(10);
	s1.insert(5);
	s1.insert(1);
	s1.insert(4);
	s1.insert(9);
	if (s1.empty())
	{
		cout << "set������Ϊ��" << endl;
	}
	else
	{
		cout << "set�����ڲ�Ϊ��" << endl;
		cout << "set������������СΪ:" << s1.size() << endl;
	}
	printSet(s1);

	set<int>s2;//Ĭ�Ϲ���

	//set��������������insert
	s2.insert(77);
	s2.insert(2);
	s2.insert(22);
	s2.insert(10);
	s2.insert(1);
	printSet(s2);
	
	//������
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(22);
	printSet(s1);
}

//set �� multiset������,ǰ���޷������ظ�����,���߿���
void test03()
{
	/*set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�,multiset���������ݣ���˿��Բ����ظ�����*/
	set<int >s;
	s.insert(10);
	pair<set<int>::iterator ,bool> ret  = s.insert(10);//����ʱ�᷵�ضԸ�������˵�����뵽�Ǹ�λ��(����һ),�����Ƿ�ɹ�(������)
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;

	}

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(9);
	ms.insert(1);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//pair���鴴��,�����������ɶԳ��ֵ����ݣ����ö�����Է�����������,c++��������뷵����������,�Ϳ����ö���
//pair<type, type> p(value1, value2);
//pair<type, type> p = make_pair(value1, value2);

void test04()
{
	pair<string, int>p("Jack", 100);
	cout << "����: " << p.first << "  ����: " << p.second << endl;
}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
