#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�������ͬ�����
class CPU {
public:
	//������㺯��
	virtual void calculate() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

//������
class Computer
{
	public:
		Computer(CPU* cpu, VideoCard* vc, Memory* mem)
		{
			m_cpu = cpu;
			m_mem = mem;
			m_vc = vc;
		}
		//�ṩ��������
		void work()//������Ƕ�̬��Ӧ��,��ͬ��Ӳ���������ò�ͬ�ĺ���
		{
			m_cpu->calculate();//����ָ��ָ���������
			m_vc->display();
			m_mem->storage();
		}

		~Computer()
		{
			if (m_cpu != NULL)
			{
				delete m_cpu;
				m_cpu = NULL;
			}
			if (m_mem != NULL)
			{
				delete m_mem;
				m_mem = NULL;
			}
			if (m_vc != NULL)
			{
				delete m_vc;
				m_vc = NULL;
			}
		}

	private:
		CPU* m_cpu;
		VideoCard* m_vc;
		Memory* m_mem;
};

//���峧��
class IntelCPU :public CPU {
public:
	virtual void calculate()
	{
		cout << "Intel��CPU��ʼ������!" << endl;
	}
};

class IntelMemory :public Memory {
public:
	virtual void storage()
	{
		cout << "Intel��Memory��ʼ�洢��!" << endl;
	}
};

class IntelVideoCard :public VideoCard {
public:
	virtual void display()
	{
		cout << "Intel���Կ���ʼ��ʾ��!" << endl;
	}
};

class LenovoCPU :public CPU {
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU��ʼ������!" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	virtual void storage()
	{
		cout << "Lenovo��Memory��ʼ�洢��!" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void display()
	{
		cout << "Lenovo���Կ���ʼ��ʾ��!" << endl;
	}
};

void test01()
{
	//��һ̨���Ե����
	CPU* intelCPU = new IntelCPU;//����ָ��,ָ���������
	VideoCard* intelVideoCard = new IntelVideoCard;//����ָ��,ָ���������
	Memory* inelMemory = new IntelMemory;

	//������һ̨����
	Computer* computer = new Computer(intelCPU, intelVideoCard, inelMemory);
	computer->work();
	delete computer;

	//�����ڶ�̨����
	cout << "-----------------------------------------" << endl;
	Computer* computer1 = new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
	computer1->work();
	delete computer1;
}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
