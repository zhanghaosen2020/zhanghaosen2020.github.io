#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

//普通员工类
class Employee :public Worker
{
public:
	//构造函数
	Employee(int id,string name,int did);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};