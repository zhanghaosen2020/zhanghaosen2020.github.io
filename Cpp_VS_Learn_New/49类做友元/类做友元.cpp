#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Building {
	//告诉编译器 goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend class GoodGay;
public:
	Building();//类内声明,类外定义
	string SettingRoom;
private:
	string BedRoom;
};

class GoodGay {
public:
	GoodGay();
	void visit();//参观函数,可以访问Building中的属性
	Building* building;
};
Building::Building()
{
	SettingRoom = "客厅";
	BedRoom = "卧室";
}
GoodGay::GoodGay()
{
	//创建建筑物对象

	building = new Building;
}
void GoodGay::visit()
{
	cout << "好基友这个类正在访问:" << building->SettingRoom << endl;
	cout << "好基友这个类正在访问:" << building->BedRoom<< endl;

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
