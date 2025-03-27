#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>




void printList(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << (*it) << " ";
	}
	cout << endl;
}


//list的构造函数
//list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
//list(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
//list(n, elem); //构造函数将n个elem拷贝给本身。
//list(const list& lst); //拷贝构造函数。
void test01()
{
	list<int>l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	printList(l);
	
	list<int>l1(l.begin(), l.end());
	printList(l1);

	list<int>l2(10, 9);
	printList(l2);

	list<int>l3(l2);
	printList(l3);
}

//assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem); //将n个elem拷贝赋值给本身。
//list& operator=(const list& lst); //重载等号操作符
//swap(lst); //将lst与本身的元素互换。

//赋值操作
void test02()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	printList(l);

	list<int>l1;
	l1.assign(l.begin(), l.end());
	printList(l1);

	l1.assign(10, 2);
	printList(l1);

	l.swap(l1);

	printList(l);
	l1 = l;
	printList(l1);


}

//size(); //返回容器中元素的个数
//empty(); //判断容器是否为空
//resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
////如果容器变短，则末尾超出容器长度的元素被删除。
//resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
////如果容器变短，则末尾超出容器长度的元素被删除。

void test03()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1为不为空" << endl;
		cout << "L1的大小(元素个数)为："<<L1.size() << endl;

	}

	L1.resize(9,0);
	cout << "L1.resize(9)之后的大小为：" << L1.size() << endl;
	printList(L1);

	L1.resize(2);
	cout << "L1.resize(9)之后的大小为：" << L1.size() << endl;
	printList(L1);
}

//push_back(elem);//在容器尾部加入一个元素
//pop_back();//删除容器中最后一个元素
//push_front(elem);//在容器开头插入一个元素
//pop_front();//从容器开头移除第一个元素
//insert(pos, elem);//在pos位置插elem元素的拷贝，返回新数据的位置。//pos的位置,都是迭代器
//insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
//insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值。
//clear();//移除容器的所有数据
//erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置。
//erase(pos);//删除pos位置的数据，返回下一个数据的位置。
//remove(elem);//删除容器中所有与elem值匹配的元素

void test04()
{
	list<int>L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);

	//尾删
	L.pop_back();

	//头删
	L.pop_front();

	//insert方式插入
	//L.insert(L.begin(),1000);
	list<int>::iterator it = L.begin();//先创建一个迭代器
	L.insert(++it, 1000);

	//删除
	it = L.begin();
	L.erase(++it);

	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);
	L.push_back(10000);

	printList(L);


	//移除指定数据
	L.remove(10000);


	printList(L);

}


//front(); //返回第一个元素。
//back(); //返回最后一个元素。
void test05()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);


	//头尾接口
	cout << "L1的第一个元素为:" << L1.front()<<endl;
	cout << "L1的末尾的元素为:" << L1.back()<<endl;
	/*这是和list的底层实现相关的(存储不是在连续的空间上), 迭代器只支持前后移动一位;*/

	//验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();
	it++;
	//it += 5;列表迭代器是不能跳跃访问的,可以像上边那样
}

//list容器的翻转和排序

bool myCompare(int v1,int v2)
{
	//降序,就让第一个数大于第二个数
	return v1 > v2;
}

void test06()
{
	list<int>l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(4);
	l.push_back(1);

	l.push_back(30);
	l.push_back(40);
	cout << "容器反转前: " << endl;
	printList(l);
	l.reverse();
	cout << "容器反转后: " << endl;
	printList(l);

	cout << "容器排序前: " << endl;
	printList(l);
	cout << "容器排序后: " << endl;
	//所有不支持随机访问迭代器的容器,不可以用标准的算法
	//不支持随机访问迭代器的容器,内部会提供一些成员函数(一些算法)
	l.sort();//升序
	printList(l);

	l.sort(myCompare);//降序


	printList(l);


}

int main() {
	//test01();
	//test02();

	//test03();

	//test04();
	//test05();

	test06();
	system("pause");
	return EXIT_SUCCESS;
}
