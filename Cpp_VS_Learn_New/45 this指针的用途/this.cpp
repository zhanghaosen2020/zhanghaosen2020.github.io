#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1.������Ƴ�ͻ
class Person {
public:
	Person(int age)
	{
		//age = age;//�������д,�ᵼ�³�Ա����age(�������Ҫ�淶m_Age)���ᱻ��ֵ,�β�age�����β�age��
		this->age = age;//thisָ��ָ�� �����õĳ�Ա���������Ķ���
		//˭����������вι���,this��ָ��˭,����ָ��p1
	}

	Person& PersonAddPerson(Person &p)
	{
		this->age += p.age;
		return *this;//��,��Ҫ���ر���,����Ҫ�����õķ�ʽ����;�������ֵ�ķ�ʽ���ػ´������һ����ԭ����ͬ�Ķ���
	}

	int age;
};
void test01()
{
	Person p1(18);
	cout << "age = " << p1.age << endl;
}

//2.���ض�������*this
void test02()
{
	Person p1(10);
	Person p2(10);
	//��ʽ���˼��
	cout << "p1+p2 = " << p1.PersonAddPerson(p2).PersonAddPerson(p1).age;

}
int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
