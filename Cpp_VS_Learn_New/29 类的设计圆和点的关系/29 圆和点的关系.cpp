#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "point.h"
#include "Circle.h"
using namespace std;

//class Point {//����
//public:
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	int getX()
//	{
//		return  m_X;
//	}
//	int getY()
//	{
//		return  m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};
//
//class Circle {
//private:
//	int m_R;
//	Point m_Center;
//public:
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	int getR()
//	{
//		return m_R;
//	}
//	//����Բ��
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//��ȡԲ��
//	Point getCenter()
//	{
//		return m_Center;
//	}
//};

void isInCircle(Point& p, Circle& c)
{
	//����Բ�ĵ���֮��ľ���ƽ��
	int distance =
		(p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
		(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());
	//����뾶��ƽ��
	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "on" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "out" << endl;
	}
	else
	{
		cout << "in" << endl;
	}
}

int main() {
	//����Բ
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//������
	Point p;
	p.setX(10);
	p.setY(10);

	//�жϹ�ϵ
	isInCircle(p,c);
	system("pause");
	return EXIT_SUCCESS;
}
