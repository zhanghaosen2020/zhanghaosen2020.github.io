#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��Ա��������Ϊ˽��
//1,�����Լ����ƶ�дȨ��

//2,����д,�ɼ�������ݵ���Ч��


class Person {

public://��Ȼ��Ա������˽�е�,�������ǿ���ͨ�������ṩһЩ�����Ľӿ�������
	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//��ȡ����
	string getName()
	{
		return m_Name;
	}

	//��ȡ����
	int getAge()
	{
		//m_Age = 0;
		return m_Age;
	}
	void setAge(int age)
	{
		if (age < 0 || age>150)
		{
			m_Age = 0;
			cout << "�������������!" << endl;
			return;
		}
		m_Age = age;
	}
	//��������
	void setLover(string lover)
	{
		m_Lover = lover;
	}
private:

	string m_Name;//�����ɶ���д

	int m_Age;//����ֻ��

	string m_Lover;//����ֻд
};
int main() {
	Person p1;
	p1.setName("�ж�˹̩");
	cout << "����: " << p1.getName() << endl;
	p1.setAge(1000);
	cout << "����: " << p1.getAge() << endl;
	p1.setLover("ehhe");
	system("pause");
	return EXIT_SUCCESS;
}
