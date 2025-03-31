#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>
#include<list>
#include<vector>
#include <ctime>

//��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//Ա����Ϣ�� : ���� ������ɣ����ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
//�ֲ�����ʾԱ����Ϣ

#define CEHUA	0
#define MEISHU	1
#define YANFA	2
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 9; i++)
	{
		//�ȴ���һ��Ա������,�������ֺͳ�ʼ����������,�ٷ��뵽��������
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000-19999

		v.push_back(worker);
	}
}

void serGroup(vector<Worker>& v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;//0,1,2
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻�����: " << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);//ͳ�Ʋ߻��ľ�������,�������
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����: " << pos->second.m_Name << " н��: " << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ� " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary <<
			endl;
	}
	cout << "----------------------" << endl;
	cout << "�з����ţ� " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������ " << pos->second.m_Name << " ���ʣ� " << pos->second.m_Salary <<
			endl;
	}
}

int main() {

	srand((unsigned int)time(NULL));
	//1,����Ա��
	vector<Worker>vWorker;
	createWorker(vWorker);
	//���Դ���
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "����: " << it->m_Name << "  н��:  " << it->m_Salary << endl;
	}
	cout << endl;
	//2,�������
	multimap<int,Worker>mWorker;
	serGroup(vWorker,mWorker);

	//3,��ʾ������Ϣ
	showWorkerByGroup(mWorker);


	system("pause");
	return EXIT_SUCCESS;
}
