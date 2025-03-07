#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Building {
	friend void goodGay(Building& building);//友元,让全局函数可以访问该类里边的私有变量(开后门)

public:
	Building()
	{
		m_BedRoom = "卧室";
		m_SittingRoom = "客厅";
	}
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};

//全局函数
void goodGay(Building& building)
{
	cout << "好基友正在访问:" << building.m_SittingRoom << endl;
	cout << "好基友正在访问:" << building.m_BedRoom << endl;

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
