#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//cin.get() //һ��ֻ�ܶ�ȡһ���ַ�,�ӻ������ж�ȡһ���ַ�
//cin.get(һ������) //��һ���ַ�
//cin.get(��������) //���Զ��ַ���
//cin.getline()
//cin.ignore()
//cin.peek()
//cin.putback()

void test01()
{
	//cin.get() //һ��ֻ�ܶ�ȡһ���ַ�,�ӻ������ж�ȡһ���ַ�
	char ch;
	//����as(�س�),��һ�ζ�:a  �ڶ��ζ�:s  �����ζ�:\n  ���Ĵ�:����(�ȴ���һ������)
	ch = cin.get();//�ӻ������ж�ȡһ���ַ�(����������û���ַ�,���������״̬)
	cout << "ch = " << ch << endl;
	ch = cin.get();//�ӻ������ж�ȡһ���ַ�(����������û���ַ�,���������״̬)
	cout << "ch = " << ch << endl;
	ch = cin.get();//�ӻ������ж�ȡһ���ַ�(����������û���ַ�,���������״̬)
	cout << "ch = " << ch << endl;//
	ch = cin.get();//�ӻ������ж�ȡһ���ַ�(����������û���ַ�,���������״̬)
	cout << "ch = " << ch << endl;
	//�ûس�Ҳ�ᱻ���з�ȡ��

	//cin.get(һ������) //��һ���ַ�
	char ch1;
	cin.get(ch);//������ϱߵĲ�ͬ����,ǰ���Ƿ���ֵ,�����Ǵ�����

}

void test02()
{

	//cin.get(��������) //���Զ��ַ���
	char buf[1024] = { 0 };
	//���൱�ڶ�ȡһ��,��Ϊ���������вŽ���
	cin.get(buf, 1024);//��һ�������Ǵӻ������ж��õ����ݴ�ŵĵط�,�ڶ������������ܷŵ��������
	cout << "buf = " << buf <<endl ;//������ȡ,���з��������ڻ�������
	char ch;
	ch = cin.get();//��ȡһ��,���ܽ����������
	if (ch == '\n')
	{
		cout << "���з������ڻ�������" << endl;
	}
	else
	{
		cout << "���з�δ�����ڻ�������" << endl;
	}
}

void test03()
{
	//cin.getline()//ȡһ���ַ�,���ϱߵ�ʹ��һ��
	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << "buf = " << buf << endl;	char ch;
	ch = cin.get();//��ȡһ��,���ܽ����������
	if (ch == '\n')//���з����������ڻ�������
	{
		cout << "���з������ڻ�������" << endl;
	}
	else
	{
		cout << "���з�δ�����ڻ�������" << endl;
	}
}

void test04()
{
	//cin.ignore(n);//Ĭ�ϻ���Ի������е�n���ַ�
	char buf[1024] = { 0 };
	cin.ignore(3); //���Ի�������ǰn���ַ�
	cin.get(buf, 1024);
	cout << buf << endl;
}

void test05()
{
	char ch = cin.peek();
	cout << "͵������������:" << ch << endl;
	char buf[1024] = { 0 };
	cin.get(buf, 1024);
	cout << buf << endl;
}

//�ж��������һ�����ֻ����ַ���
void test06()
{
	cout << "������һ���ַ�����������:" << endl;
	char ch = cin.peek();
	if (ch >= '0' && ch <= '9')
	{
		int num;
		cin >> num;
		cout << "�����������: " <<num<< endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "��������ַ���: " << endl;
	}
}

//����2:��ʾ�û�����1-10֮�������,�����������,����������
void test07()
{
	cout << "������1-10֮�������: " << endl;
	while (true)
	{
		int num;
		cin >> num;
		if (num > 0 && num <= 10)
		{
			cout << "������ȷ,���������Ϊ: " << num << endl;
			break;
		}
		//cout << "������������������" << endl;
		//1.���ñ�־λ(������)
		cin.clear();
		//2.ˢ�»�����
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������1-10֮�������: " << endl;
		//cout << "��־λ: " << cin.fail() << endl;// 0Ϊ���� ,1��ʾ����������
	}
	
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	system("pause");
	return EXIT_SUCCESS;
}
