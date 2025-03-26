#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

class Person {
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01()
{
	//��������
	queue<Person>q;

	//׼������
	Person p1("��ɮ0", 99);
	Person p2("��ɮ1", 993);
	Person p3("��ɮ2", 994);
	Person p4("��ɮ3", 995);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "���д�СΪ��" << q.size() << endl;

	//�ж϶��в�Ϊ��,�鿴��ͷ��β,����
	while (!q.empty())
	{
		//�����ͷԪ��
		cout << "��ͷԪ��-- ������ " << q.front().m_Name
			<< " ���䣺 " << q.front().m_Age << endl;
		cout << "��βԪ��-- ������ " << q.back().m_Name
			<< " ���䣺 " << q.back().m_Age << endl;
		cout << endl;
		//������ͷԪ��
		q.pop();
	}
	cout << "���д�СΪ��" << q.size() << endl;
	
}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
