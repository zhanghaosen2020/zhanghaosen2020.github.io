#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������ʹ�������
class Animal {

public:
	Animal()
	{
		cout << "animal�Ĺ��캯��" << endl;
	}
	//virtual ~Animal() //�������������Խ��,����ָ���ͷ��������ʱ���ɾ�������
	//{
	//	cout << "animal������������" << endl;
	//}
	
	//��������
	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal:: ~Animal() {
	cout << "Animal�������������ĵ���" << endl;
}

class Cat :public Animal
{
	public:
		Cat(string name)
		{
			cout << "cat�Ĺ��캯��" << endl;
			m_Name = new string(name);
		}
	virtual void speak()
	{
		cout << *m_Name << "Сè��˵��" << endl;
	}
	~Cat() {
		if (m_Name != NULL)
		{
			cout << "cat����������"<<endl;
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
	//�����ָ����������ʱ��,������������е���������,��������������ж�������,�����ڴ�й©
	delete animal;
}
int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
