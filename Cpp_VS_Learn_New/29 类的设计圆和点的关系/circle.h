#pragma once
#include <iostream>
#include "point.h"
using namespace std;
class Circle {
private:
	int m_R;
	Point m_Center;
public:
	void setR(int r);
	int getR();
	//设置圆心
	void setCenter(Point center);
	//获取圆心
	Point getCenter();
};