#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>

//ϵͳ��׼�쳣��ʹ��(��out_of_rangeΪ����)
class Person
{
public:
	Person(int age)
	{
		if (age > 100 || age < 0)
		{
			throw out_of_range("�������䷶Χ!");
		}
		else
		{
			this->m_Age = age;
		}
	}

	int m_Age;
};

void test01()
{
	try {
		Person(1000);
	}
	//���б�׼�쳣�ĸ��������exception
	catch(exception& e)//����һ��Ҫ��ס,(�ö�̬)����Ҫ�ø��������ȥ���������
	{
		cout << e.what() << endl;//��e.what()ȥ�����Ӧ�Ĵ�����ʾ��Ϣ
	}
}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
