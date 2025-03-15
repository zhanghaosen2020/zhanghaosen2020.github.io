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

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void exitSystem();


	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//���ְ������
	void Add_Emp();

	//�����ļ�
	void Save();

	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsempty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ְ���Ƿ����,������ɾ��Ķ���Ҫ�õ�
	//������ڷ���ְ���������е�λ��,���������,�򷵻�-1;
	int IsExist(int id);
	int IsExist(string name);//���ظú���
	
	//���ձ��ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����Ա��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	~WorkerManager();
};