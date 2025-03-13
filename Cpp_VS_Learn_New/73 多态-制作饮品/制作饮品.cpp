#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class AbstractDrinking
{
public:
	//��ˮ
	virtual void Boil() = 0;
	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSomething() = 0;

	//������Ʒ
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class Coffee : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "�����ɽ��Ȫˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}

	virtual void PutSomething()
	{
		cout << "���Ǻ�ţ��" << endl;
	}
};

//��������
class Tea : public AbstractDrinking {
public:
	//��ˮ
	virtual void Boil()
	{
		cout << "�����ɽ��Ȫˮ" << endl;
	}
	//����
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	//���뱭��
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}

	virtual void PutSomething()
	{
		cout << "���" << endl;
	}
};

//��������
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
	//��������
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
