#pragma once
#include<iostream>
using namespace std;
#include <string.h>

//职工抽象类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	//职工编号
	int m_Id;
	//姓名
	string m_Name;
	//部门编号
	int m_DeptId;
};