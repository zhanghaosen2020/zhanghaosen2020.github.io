#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//多态

//动物类
class Animal {
public:
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal
{
public:
	virtual void speak() {
		cout << "小猫在说话" << endl;
	}
};

//说话函数
//动态多态的使用,父类指针或引用  指向子类对象
void doSpeak(Animal& animal)// Animal &animal = cat;父类引用指向子类对象
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
