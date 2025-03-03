#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "point.h"
#include "Circle.h"
using namespace std;

//class Point {//点类
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
//	//设置圆心
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//};

void isInCircle(Point& p, Circle& c)
{
	//计算圆心到点之间的距离平方
	int distance =
		(p.getX() - c.getCenter().getX()) * (p.getX() - c.getCenter().getX()) +
		(p.getY() - c.getCenter().getY()) * (p.getY() - c.getCenter().getY());
	//计算半径的平方
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
	//创建圆
	Circle c;
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	p.setX(10);
	p.setY(10);

	//判断关系
	isInCircle(p,c);
	system("pause");
	return EXIT_SUCCESS;
}
