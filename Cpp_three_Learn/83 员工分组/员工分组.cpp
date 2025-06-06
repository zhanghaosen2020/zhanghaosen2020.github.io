#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>
#include<list>
#include<vector>
#include <ctime>

//公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
//员工信息有 : 姓名 工资组成；部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key(部门编号) value(员工)
//分部门显示员工信息

#define CEHUA	0
#define MEISHU	1
#define YANFA	2
class Worker
{
public:
	string m_Name;
	int m_Salary;
};
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 9; i++)
	{
		//先创建一个员工对象,将其名字和初始化工作做好,再放入到容器当中
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000;//10000-19999

		v.push_back(worker);
	}
}

void serGroup(vector<Worker>& v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;//0,1,2
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部门: " << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);//统计策划的具体人数,方便遍历
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名: " << pos->second.m_Name << " 薪资: " << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "美术部门： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary <<
			endl;
	}
	cout << "----------------------" << endl;
	cout << "研发部门： " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // 统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary <<
			endl;
	}
}

int main() {

	srand((unsigned int)time(NULL));
	//1,创建员工
	vector<Worker>vWorker;
	createWorker(vWorker);
	//测试代码
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "姓名: " << it->m_Name << "  薪资:  " << it->m_Salary << endl;
	}
	cout << endl;
	//2,分组操作
	multimap<int,Worker>mWorker;
	serGroup(vWorker,mWorker);

	//3,显示分组信息
	showWorkerByGroup(mWorker);


	system("pause");
	return EXIT_SUCCESS;
}
