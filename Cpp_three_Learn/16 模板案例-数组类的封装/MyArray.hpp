#pragma once
#include<iostream>
using namespace std;

//ʵ��һ���Լ���������
template<class T>
class MyArray {
public:
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//��������һ�����T����Ԫ�ص�����

		//���Դ���
		//cout << "�����вι���" << endl;
	}

	//��������
	MyArray(const MyArray& arr)//������ֱ���ṩ��ֻ����ǳ����(������ݿ���),��������Լ�ʵ��
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���
		this->pAddress = new T[this->m_Capacity];//????
		//��arr�е����ݶ���������//������Size�Ĵ�С(���ݵĸ���)���������Ĵ�С
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];//arr��һ���Ѿ���������Ķ���ı���
				//�ϱ����Ĺ������ǽ�arr���������һ��(����ķ�ʽ),�������ڶ��������ڴ�
		}

		//���Դ���
		//cout << "���ÿ�������" << endl;
	}

	//����=,��ֹ��ֵʱ��ǳ����,�� p1 = p2 = p3;
	MyArray& operator=(const MyArray& arr)//��������������Ŀ���ǿ���������ֵ
	{
		//���жϱ���ֵ�Ķ����Ƿ�Ϊ��,��Ϊ��,�����
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		//���Դ���
		//cout << "����=�ĵ���" << endl;

		return*this;
	}

	//ʵ��β�巨
	void Push_Back(const T& val)
	{
		//����ǰ��Ҫ�ж������Ƿ��Ѿ����ڴ�С��(������Ҫ����)
		if (this->m_Capacity == this->m_Size)
		{
			cout << "��������,����������µ�������" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;//���������С
	}

	//βɾ��
	void Pop_Back()
	{
		//���û����ʲ������һ��Ԫ��,��Ϊβɾ
		if (this->m_Size == 0)
		{
			cout << "�����ѿ�,����ɾ������" << endl;
			return;
		}
		this->m_Size--;
	}

	//ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//������������
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//���������С
	int getSize()
	{
		return this->m_Size;
	}

	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		//���Դ���
		//cout << "�����ĵ���" << endl;
	}
private:
	T* pAddress;//ָ��������ٵ���ʵ����
	int m_Capacity;//��������
	int m_Size;//����Ĵ�С
};

