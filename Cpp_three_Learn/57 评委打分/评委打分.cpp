#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>

//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

//选手类
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;

};

void createPerson(vector<Person>& v)
{
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		string nameSeed = "ABCDE";
		name += nameSeed[i];
		int score = 0;
		
		Person p(name, score);
		v.push_back(p);

	}
}

//设置分数的函数
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将分数放入到deque容器当中
		deque<int>dq;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//分数范围设置为60-100
			dq.push_back(score);
		}

		//测试代码
		//cout << "选手: " << (*it).m_Name << "  分数: " << endl;
		//for (deque<int>::iterator dit = dq.begin(); dit != dq.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;
			
		//对所存分数排序
		sort(dq.begin(), dq.end());


		//去除最高最低分
		dq.pop_back();
		dq.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = dq.begin(); dit != dq.end(); dit++)
		{
			sum += (*dit);//累加分数
		}

		int avg = sum / dq.size();

		//平均分赋值到选手身上
		(*it).m_Score = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
{
	cout << "姓名: " << (*it).m_Name << "  分数: " << (*it).m_Score << endl;
}
}

int main() {
	//随机数种子
	srand((unsigned int)time(NULL));

	//1,创建五名选手
	vector<Person>v;//存放选手的容器
	createPerson(v);
	//测试存进去没有
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名: " << (*it).m_Name << "  分数: " << (*it).m_Score << endl;
	//}
	// 上边是迭代器的操作方式,下边是运算符重载的方式
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << "姓名: " << v[i].m_Name << "  分数: " << v[i].m_Score << endl;
	//}

	//2,给五人打分
	setScore(v);

	//3,显示最后得分
	showScore(v);

	system("pause");
	return EXIT_SUCCESS;
}
