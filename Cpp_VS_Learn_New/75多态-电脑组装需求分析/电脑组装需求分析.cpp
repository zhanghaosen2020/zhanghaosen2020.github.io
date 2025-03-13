#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//抽象出不同零件类
class CPU {
public:
	//抽象计算函数
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

//电脑类
class Computer
{
	public:
		Computer(CPU* cpu, VideoCard* vc, Memory* mem)
		{
			m_cpu = cpu;
			m_mem = mem;
			m_vc = vc;
		}
		//提供工作函数
		void work()//这里就是多态的应用,不同的硬件对象会调用不同的函数
		{
			m_cpu->calculate();//父类指针指向子类对象
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

//具体厂商
class IntelCPU :public CPU {
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算了!" << endl;
	}
};

class IntelMemory :public Memory {
public:
	virtual void storage()
	{
		cout << "Intel的Memory开始存储了!" << endl;
	}
};

class IntelVideoCard :public VideoCard {
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示了!" << endl;
	}
};

class LenovoCPU :public CPU {
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算了!" << endl;
	}
};

class LenovoMemory :public Memory {
public:
	virtual void storage()
	{
		cout << "Lenovo的Memory开始存储了!" << endl;
	}
};

class LenovoVideoCard :public VideoCard {
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示了!" << endl;
	}
};

void test01()
{
	//第一台电脑的零件
	CPU* intelCPU = new IntelCPU;//父类指针,指向子类对象
	VideoCard* intelVideoCard = new IntelVideoCard;//父类指针,指向子类对象
	Memory* inelMemory = new IntelMemory;

	//创建第一台电脑
	Computer* computer = new Computer(intelCPU, intelVideoCard, inelMemory);
	computer->work();
	delete computer;

	//创建第二台电脑
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
