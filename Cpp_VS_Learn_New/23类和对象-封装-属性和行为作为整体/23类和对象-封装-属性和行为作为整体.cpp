#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//Բ����
const double PI = 3.14;

//���һ��Բ��,�����ܳ�
class Circle
{
	//����Ȩ��
public:
	//����
	//�뾶
	int m_r;

	//��Ϊ
	//��ȡԲ�ܳ�
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
};

class Students {
public:
	//����--ѧ�ź�����
	int Id;
	string name;

	//��Ϊ--���ѧ�����ֺ�ѧ��
	void PrintIdName()
	{
		cout << "����: " << name <<"  "<< "ѧ��: " << Id << endl;
	}

};
int main() {
	//ͨ��Բ��,���������Բ(����)�Ĺ��̽�ʵ����
	Circle c1;//�����һ��Բc1
	c1.m_r = 10;//����һ���뾶Ϊ10 ��Բ
	cout << "Բ���ܳ�Ϊ: " << c1.calculateZC() << endl;

	Students student;
	student.name = "����";
	student.Id = 3123104;
	student.PrintIdName();

	system("pause");
	return EXIT_SUCCESS;
}
