#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//��������Զ�����������
//�Զ�����������
class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};

void test01()
{
	vector<Person>v;
	
	//��������
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);
	
	//���������������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	//���������е�����
	//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "����: " << (*it).mName << "  ����: " << (*it).mAge << endl;//it����ָ�������֮�����Person��������(�������е�����)
		cout << "����: " << it->mName << "  ����: " << it->mAge << endl;//ֱ����Ҳ�ǿ��Ե�,ͨ��ָ�����
	}
}

//����Զ����������͵�ָ��
void test02()
{
	vector<Person*>v;

	//��������
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);
	Person p5("e", 50);

	//���������������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		//cout << "����: " << (*it)->mName << "  ����: " << (*it)->mAge << endl;
		cout << ":����: " << (**it).mName << "  :����: " << (*it)->mAge << endl;

	}
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
