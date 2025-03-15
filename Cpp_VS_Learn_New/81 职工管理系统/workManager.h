#pragma once
#include<iostream>
using namespace std;
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"

#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager {
public:
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void exitSystem();


	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;

	//添加职工函数
	void Add_Emp();

	//保存文件
	void Save();

	//判断文件是否为空 标志
	bool m_FileIsempty;

	//统计文件中人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//职工是否存在,后续增删查改都需要用到
	//如果存在返回职工在数组中的位置,如果不存在,则返回-1;
	int IsExist(int id);
	int IsExist(string name);//重载该函数
	
	//按照编号删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找员工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	~WorkerManager();
};