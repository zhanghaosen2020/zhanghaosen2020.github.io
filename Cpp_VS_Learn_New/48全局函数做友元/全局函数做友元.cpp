#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Building {
	friend void goodGay(Building& building);//��Ԫ,��ȫ�ֺ������Է��ʸ�����ߵ�˽�б���(������)

public:
	Building()
	{
		m_BedRoom = "����";
		m_SittingRoom = "����";
	}
public:
	string m_SittingRoom;//����
private:
	string m_BedRoom;//����
};

//ȫ�ֺ���
void goodGay(Building& building)
{
	cout << "�û������ڷ���:" << building.m_SittingRoom << endl;
	cout << "�û������ڷ���:" << building.m_BedRoom << endl;

}

void test01()
{
	Building building;
	goodGay(building);
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
