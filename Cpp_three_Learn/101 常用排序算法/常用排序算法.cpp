#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>


//for_each的第三个参数
void myPrint(int v)
{
	cout << v << " " ;
}

void test01()
{
	vector<int>v;
	v.push_back(9);
	v.push_back(6);
	v.push_back(80);
	v.push_back(12);
	v.push_back(2);
	v.push_back(40);
	v.push_back(23);
	v.push_back(22);
	v.push_back(25);
	
	//升序遍历一遍
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(),myPrint);
	cout << endl;

	//降序排列一遍
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

}

int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
