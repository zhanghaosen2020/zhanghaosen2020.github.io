#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��̬

//������
class Animal {
public:
	virtual void speak() {
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak() {
		cout << "Сè��˵��" << endl;
	}
};

//˵������
//��̬��̬��ʹ��,����ָ�������  ָ���������
void doSpeak(Animal& animal)// Animal &animal = cat;��������ָ���������
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
