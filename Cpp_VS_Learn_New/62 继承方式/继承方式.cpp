#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//����
class Base1 {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:
	void func()
	{
		m_A = 10;//�����й���Ȩ�޳�Ա,����������ȻΪ����Ȩ��
		m_B = 10;//�����б���Ȩ�޳�Ա,����������ȻΪ����Ȩ��
		//m_C = 10;//�����е�˽��Ȩ�޳�Ա,������ʲ���
	}
};

class Son2 :protected Base1 {

};


int main() {

	system("pause");
	return EXIT_SUCCESS;
}
