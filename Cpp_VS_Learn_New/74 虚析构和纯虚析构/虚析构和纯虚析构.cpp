#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//虚析构和纯虚析构
class Animal {

public:
	Animal()
	{
		cout << "animal的构造函数" << endl;
	}
	//virtual ~Animal() //利用虚析构可以解决,父类指针释放子类对象时不干净的问题
	//{
	//	cout << "animal的虚析构函数" << endl;
	//}
	
	//纯虚析构
	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal:: ~Animal() {
	cout << "Animal纯虚析构函数的调用" << endl;
}

class Cat :public Animal
{
	public:
		Cat(string name)
		{
			cout << "cat的构造函数" << endl;
			m_Name = new string(name);
		}
	virtual void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}
	~Cat() {
		if (m_Name != NULL)
		{
			cout << "cat的析构函数"<<endl;
			delete m_Name;
			m_Name = NULL;
		}
	}
		
	string* m_Name;
};
void test01()
{
	Animal* animal = new Cat("Tom");
	animal->speak();
	//父类的指针在析构的时候,不会调用子类中的析构函数,导致子类中如果有堆区属性,出现内存泄漏
	delete animal;
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
