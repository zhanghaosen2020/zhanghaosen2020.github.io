#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
}

//构造：
//map<T1, T2> mp; //map默认构造函数:
//map(const map& mp); //拷贝构造函数
//赋值：map& operator=(const map& mp); //重载等号操作符
void test01()
{
	map<int, int>m;


	m.insert(pair<int, int>(1, 10));//一个匿名的对组
	m.insert(pair<int, int>(2, 20));//一个匿名的对组
	m.insert(pair<int, int>(3, 30));//一个匿名的对组
	m.insert(pair<int, int>(4, 40));//一个匿名的对组
	printMap(m);

	//拷贝构造
	map<int, int>m1(m);
	printMap(m1);

}

//map的查找
//find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key); //统计key的元素个数
void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printMap(m);
	map<int,int>::iterator	pos =  m.find(6);//找的是key值,返回的是对应索引的迭代器值
	if (pos != m.end())
	{
		cout << "找到了,key =  " << pos->first << " value = " << pos->second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	int count = m.count(3);
	cout << count << endl;


}

//map容器,排序
class MyCompare
{
public:
	bool operator()(int v1,int v2)const//通过仿函数来修改排序规则,升序变降序
	{
		return v1 > v2;
	}
};

void test03()
{
	map<int, int, MyCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

int main() {
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}
