#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>

//��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

//ѡ����
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;

};

void createPerson(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		string nameSeed = "ABCDE";
		name += nameSeed[i];
		int score = 0;
		
		Person p(name, score);
		v.push_back(p);

	}
}

//���÷����ĺ���
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//���������뵽deque��������
		deque<int>dq;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//������Χ����Ϊ60-100
			dq.push_back(score);
		}

		//���Դ���
		//cout << "ѡ��: " << (*it).m_Name << "  ����: " << endl;
		//for (deque<int>::iterator dit = dq.begin(); dit != dq.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
			
		//�������������
		sort(dq.begin(), dq.end());


		//ȥ�������ͷ�
		dq.pop_back();
		dq.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator dit = dq.begin(); dit != dq.end(); dit++)
		{
			sum += (*dit);//�ۼӷ���
		}

		int avg = sum / dq.size();

		//ƽ���ָ�ֵ��ѡ������
		(*it).m_Score = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
{
	cout << "����: " << (*it).m_Name << "  ����: " << (*it).m_Score << endl;
}
}

int main() {
	//���������
	srand((unsigned int)time(NULL));

	//1,��������ѡ��
	vector<Person>v;//���ѡ�ֵ�����
	createPerson(v);
	//���Դ��ȥû��
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "����: " << (*it).m_Name << "  ����: " << (*it).m_Score << endl;
	//}
	// �ϱ��ǵ������Ĳ�����ʽ,�±�����������صķ�ʽ
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "����: " << v[i].m_Name << "  ����: " << v[i].m_Score << endl;
	//}

	//2,�����˴��
	setScore(v);

	//3,��ʾ���÷�
	showScore(v);

	system("pause");
	return EXIT_SUCCESS;
}
