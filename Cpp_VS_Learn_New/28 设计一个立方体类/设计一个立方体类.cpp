#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
��ϰ����1�������������
�����������(Cube)
������������������
�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����(�˴�����ѧ���жϴ�������ĸ���,�Լ���ʶ�����õĺô�)
*/
class Cube {
private:
	int m_L;
	int m_W;
	int m_H;
public:
	void setLength(int l,int w, int h)
	{
		m_L = l;
		m_W = w;
		m_H = h;
	}
	int getL()
	{
		return m_L;
	}
	int getW()
	{
		return m_W;
	}
	int getH()
	{
		return m_H;
	}

	int calculateVolume()
	{
		return m_L * m_H* m_W;
	}

	int calculateArea()
	{
		return 2*m_L*m_W+2*m_L*m_H+2*m_W*m_H;
	}

	bool isSameByClass(Cube& c)
	{
		if (m_H == c.getH() && m_L== c.getL() && m_W== c.getW())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool isSame(Cube &c1,Cube &c2)
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main() {
	Cube c1;
	c1.setLength(10, 12, 10);
	cout << "���Ϊ: " << c1.calculateArea() << endl;
	cout << "���Ϊ: " << c1.calculateVolume() << endl;

	Cube c2;
	c2.setLength(10, 12, 10);
	bool ret = isSame(c1, c2);
	cout << "�������Ƿ����?: " << ret << endl;
	
	bool ret1 = c1.isSameByClass(c2);
	cout << "�������Ƿ����?: " << ret1 << endl;
	system("pause");
	return EXIT_SUCCESS;
}
