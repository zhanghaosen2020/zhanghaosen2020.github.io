#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
//vector容器构造函数
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//empty(); //判断容器是否为空
//capacity(); //容器的容量
//size(); //返回容器中元素的个数
//resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
////如果容器变短，则末尾超出容器长度的元素被删除。
//resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
////如果容器变短，则末尾超出容器长度的元素被删除

void test01()
{
	vector<int>v1;
	for (int i = 0; i < 11; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
		cout << "容器的容量为: " << v1.capacity() << endl;
		cout << "容器的大小为: " << v1.size() << endl;
	}

	v1.resize(15, 10);
	printVector(v1);
	cout << "容器的容量为: " << v1.capacity() << endl;
	cout << "容器的大小为: " << v1.size() << endl;

}

//push_back(ele); //尾部插入元素ele
//pop_back(); //删除最后一个元素
//insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
//insert(const_iterator pos, int count, ele); //迭代器指向位置pos插入count个元素ele
//erase(const_iterator pos); //删除迭代器指向的元素
//erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
//clear(); //删除容器中所有元素
void test02()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	printVector(v1);

	v1.insert(v1.begin()+1, 9);
	printVector(v1);
	
	//v1.insert(v1.begin(), 9,0);
	v1.erase(v1.begin());
	v1.erase(v1.begin(), v1.end());
	printVector(v1);
	cout << "容量为: " << v1.capacity() << endl;
}

//at(int idx); //返回索引idx所指的数据
//operator[]; //返回索引idx所指的数据
//front(); //返回容器中第一个数据元素
//back(); //返回容器中最后一个数据元素

void test03()
{
	vector<int>v1;//默认构造,无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " " ;
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << v1.front() << endl;
}

void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	cout << "容器互换前: " << endl;
	printVector(v1);
	printVector(v2);

	v1.swap(v2);
	cout << "容器互换后: " << endl;
	printVector(v1);
	printVector(v2);

	//实际的用途  -->  收缩内存空间
}


void test05()
{
	vector<int>v;
	v.reserve(5000);
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "容器的容量为: " << v.capacity() << endl;
	cout << "容器的大小为: " << v.size() << endl;
	cout << num << endl;

}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();

	test05();


	system("pause");
	return EXIT_SUCCESS;
}
