#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Building {
	//���߱����� goodGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������
	friend class GoodGay;
public:
	Building();//��������,���ⶨ��
	string SettingRoom;
private:
	string BedRoom;
};

class GoodGay {
public:
	GoodGay();
	void visit();//�ιۺ���,���Է���Building�е�����
	Building* building;
};
Building::Building()
{
	SettingRoom = "����";
	BedRoom = "����";
}
GoodGay::GoodGay()
{
	//�������������

	building = new Building;
}
void GoodGay::visit()
{
	cout << "�û�����������ڷ���:" << building->SettingRoom << endl;
	cout << "�û�����������ڷ���:" << building->BedRoom<< endl;

}

void test01()
{
	GoodGay gg;
	gg.visit();
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
