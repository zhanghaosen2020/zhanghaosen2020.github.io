#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//������������
void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);

	cout << "Ԫ��4�ظ��Ĵ���Ϊ:" << num << endl;
}


//�Զ�����������

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person& p)//���ظú�������Ҫ
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//bool operator==(const Person& p)//���õײ����ʱ,��Ҫ��const,�Է���С���޸���p�����ֵ
	//{
	//	if (this->m_Name == p.m_Name)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	string m_Name;
	int m_Age;
};

class Greater
{
public:
	bool operator()(const Person& p)
	{
		if (p.m_Age > 20)
		{
			return true;
		}
	}
};
void test02()
{
	vector<Person> v;
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//ͳ�ƺ������������ͬ���˵ĸ���
	Person p("�����", 35);
	int num = count(v.begin(), v.end(), p);
	cout << "num =  " << num << endl;

	//ͳ���������20������
	int num1 = count_if(v.begin(), v.end(), Greater());
	cout << "num1 =  " << num1 << endl;

}

int main() {
	
	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}
