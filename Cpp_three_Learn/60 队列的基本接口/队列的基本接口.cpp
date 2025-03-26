#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

class Person {
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test01()
{
	//创建队列
	queue<Person>q;

	//准备数据
	Person p1("唐僧0", 99);
	Person p2("唐僧1", 993);
	Person p3("唐僧2", 994);
	Person p4("唐僧3", 995);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列大小为：" << q.size() << endl;

	//判断队列不为空,查看队头队尾,出队
	while (!q.empty())
	{
		//输出队头元素
		cout << "队头元素-- 姓名： " << q.front().m_Name
			<< " 年龄： " << q.front().m_Age << endl;
		cout << "队尾元素-- 姓名： " << q.back().m_Name
			<< " 年龄： " << q.back().m_Age << endl;
		cout << endl;
		//弹出队头元素
		q.pop();
	}
	cout << "队列大小为：" << q.size() << endl;
	
}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
