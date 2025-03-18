#pragma once
#include<iostream>
using namespace std;

//实现一个自己的数组类
template<class T>
class MyArray {
public:
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];//堆区开辟一个存放T类型元素的数组

		//测试代码
		//cout << "调用有参构造" << endl;
	}

	//拷贝构造
	MyArray(const MyArray& arr)//编译器直接提供的只会是浅拷贝(表层数据拷贝),因此我们自己实现
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[this->m_Capacity];//????
		//将arr中的数据都拷贝过来//这里是Size的大小(数据的个数)而非容量的大小
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];//arr是一个已经构造出来的对象的别名
				//上边做的工作就是将arr这个对象复制一份(深拷贝的方式),即重新在堆区开辟内存
		}

		//测试代码
		//cout << "调用拷贝构造" << endl;
	}

	//重载=,防止赋值时的浅拷贝,如 p1 = p2 = p3;
	MyArray& operator=(const MyArray& arr)//传参这样子做的目的是可以连续赋值
	{
		//先判断被赋值的对象是否为空,不为空,先清空
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		//测试代码
		//cout << "重载=的调用" << endl;

		return*this;
	}

	//实现尾插法
	void Push_Back(const T& val)
	{
		//插入前需要判断容量是否已经等于大小了(否则需要扩容)
		if (this->m_Capacity == this->m_Size)
		{
			cout << "内容已满,不能再添加新的数组了" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;//更新数组大小
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素,即为尾删
		if (this->m_Size == 0)
		{
			cout << "内容已空,不能删除数据" << endl;
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中的元素
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
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
		//测试代码
		//cout << "析构的调用" << endl;
	}
private:
	T* pAddress;//指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;//数组的大小
};

