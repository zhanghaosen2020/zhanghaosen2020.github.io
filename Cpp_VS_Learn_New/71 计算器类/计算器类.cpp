#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ͨд��
class Calculator {
public:
	int getResult(string opr)
	{
		if (opr == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (opr == "-")
		{
			return m_Num1 - m_Num2;
		}
		//��Ҫ��չ�¹���,��Ҫ�޸�Դ��
		//�ڿ�����,�ᳫ ����ԭ��(����չ���п���,���޸Ĺر�)
	}

	int m_Num1;//������1
	int m_Num2;//������2

};

void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
}

//���ö�̬ʵ�ּ�����
//ʵ��һ���������ĳ�����(����)
class AbsentCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};
//�������ӷ���
class AddCalculator :public AbsentCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//������������
class SubCalculator :public AbsentCalculator
{
public:
	virtual int getResult()
	{
		return m_Num1 - m_Num2;
	}
};

int doJiSuan(AbsentCalculator& abcalculaotr)
{
	return abcalculaotr.getResult();
}

void test02()
{
	//��̬ʹ������
	//�����ָ���������ָ���������

	//�ӷ�����
	AbsentCalculator* abc = new AddCalculator;//����ָ��ָ���������
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;

	//������ͷ�
	delete abc;

	//��������
	abc = new SubCalculator;
	abc->m_Num2 = 10;
	abc->m_Num1 = 100;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;


	AddCalculator add;
	add.m_Num2 = 10;
	add.m_Num1 = 100;
	add.getResult();
	cout << add.m_Num1 << " + " << add.m_Num2 << " = " << doJiSuan(add) << endl;

}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
