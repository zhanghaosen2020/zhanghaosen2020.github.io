#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ָ����ʳ�Ա����
class Person {
public:
	int m_Age;

	void showClassName()
	{
		cout << "�����������" << endl;
	}

	void showPersonAge()
	{
		cout << "����Ϊ: " << this->m_Age << endl;
	}

};
void test01()
{
	Person* p = NULL;
	p->showClassName();//�����ǿ��Է��ʳ�Ա������,ǰ���Ǹó�Ա������û���õ�������thisָ��
	//p->showPersonAge();//�ú����м�͵�����thisָ�뵼�³��������
}

int main() {

	test01();
	system("pause");
	return EXIT_SUCCESS;
}
