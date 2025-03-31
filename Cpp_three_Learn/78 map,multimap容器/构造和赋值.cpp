#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
}

//���죺
//map<T1, T2> mp; //mapĬ�Ϲ��캯��:
//map(const map& mp); //�������캯��
//��ֵ��map& operator=(const map& mp); //���صȺŲ�����
void test01()
{
	map<int, int>m;


	m.insert(pair<int, int>(1, 10));//һ�������Ķ���
	m.insert(pair<int, int>(2, 20));//һ�������Ķ���
	m.insert(pair<int, int>(3, 30));//һ�������Ķ���
	m.insert(pair<int, int>(4, 40));//һ�������Ķ���
	printMap(m);

	//��������
	map<int, int>m1(m);
	printMap(m1);

}

//map�Ĳ���
//find(key); //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
//count(key); //ͳ��key��Ԫ�ظ���
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printMap(m);
	map<int,int>::iterator	pos =  m.find(6);//�ҵ���keyֵ,���ص��Ƕ�Ӧ�����ĵ�����ֵ
	if (pos != m.end())
	{
		cout << "�ҵ���,key =  " << pos->first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
	int count = m.count(3);
	cout << count << endl;


}

//map����,����
class MyCompare
{
public:
	bool operator()(int v1,int v2)const//ͨ���º������޸��������,����併��
	{
		return v1 > v2;
	}
};

void test03()
{
	map<int, int, MyCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
