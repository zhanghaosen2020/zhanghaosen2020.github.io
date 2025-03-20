#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��д�Լ���һ���쳣��,��չһЩ�Լ��Ĺ���
//�ҵ��쳣��-->�Եײ������չ     (��ڿθɻ�̫����)
class MyOutOfRange :public exception
{
public:
	MyOutOfRange(const char* errInfo)
	{
		this->m_errInfo = errInfo;//cpp������const char*��ʽת��Ϊstring����,�����������ֱ�ӽ���
	}
	MyOutOfRange(string& errInfo)
	{

		this->m_errInfo = errInfo;
	}
	virtual char const* what() const //��д�õײ�ĺ���ʱ,ʲô���ǲ��ܸı��(����ֵ,��������־��)
	{
	//����cpp�в�����string������ʿת��Ϊconst char*��ԭʼ���͵�,��Ҫ���ú���
//std::string ������ʽת��Ϊ const char* , std::string ��һ���࣬��const char* ��һ��ԭʼָ�����͡�
//��std::string��const char* ��ת���ǲ���ȫ�ģ���Ϊstd::string�ڲ���ʵ��ϸ�ڣ��綯̬�ڴ���䣩����ֱ�ӱ�¶Ϊһ��
//�򵥵�ָ�롣��ˣ�C++��׼�ⲻ����std::string��ʽת��Ϊconst char* �������Ҫ��std::stringת��Ϊconst char* ��
//������ʽ�ص���std::string��c_str()��data()��Ա������
		return this->m_errInfo.c_str();
	}

	string  m_errInfo;//��¼������Ϣ
};

class Person
{
public:
	Person(int age)
	{
		if (age > 100 || age < 0)
		{
			//throw out_of_range("�������䷶Χ!");
			throw MyOutOfRange("�ҵ��쳣,�������0~150֮��");
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
	catch (exception& e)//����һ��Ҫ��ס,(�ö�̬)����Ҫ�ø��������ȥ���������
	{
		cout << e.what() << endl;//��e.what()ȥ�����Ӧ�Ĵ�����ʾ��Ϣ
	}
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
