#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

//�������ļ� д�ļ�
class Person {
public:
	char m_Name[64];//����
	int m_Age;//����
};

void test01()
{
	ofstream ofs("Person.txt", ios::out | ios::binary);
	//ofs.open("Person.txt", ios::out | ios::binary);

	Person p = { "����",18 };//public���޻�����麯��,��˿���{}��ʼ��,�����ڽṹ��ĳ�ʼ��
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
