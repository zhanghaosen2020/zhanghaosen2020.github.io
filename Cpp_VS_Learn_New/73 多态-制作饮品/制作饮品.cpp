#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee : public AbstractDrinking {
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮百岁山矿泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	virtual void PutSomething()
	{
		cout << "加糖和牛奶" << endl;
	}
};

//制作咖啡
class Tea : public AbstractDrinking {
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮百岁山矿泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	//倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	virtual void PutSomething()
	{
		cout << "枸杞" << endl;
	}
};

//制作函数
void doWork(AbstractDrinking* abs)
{
	abs->makeDrink();
	delete abs;
}
void doWork1(AbstractDrinking& abs)
{
	abs.makeDrink();
}

void test01()
{
	//制作咖啡
	doWork(new Coffee);//AbstractDrinking* abs = new Coffee;
	cout << "------------------------" << endl;
	doWork(new Tea);//AbstractDrinking* abs = new Coffee;
	cout << "------------------------" << endl;
	Coffee coffee;
	doWork1(coffee);
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
