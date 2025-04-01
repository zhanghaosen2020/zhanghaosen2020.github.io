#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>
#include<ctime>

void Print(int v)
{
	cout << v << " ";
}
void test01()
{

	srand((unsigned int)time(NULL));
	vector<int >v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	cout << "打乱前:" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	cout << "打乱后:" << endl;
	random_shuffle(v.begin(), v.end());//这种涉及随机的,往往都需要种一个随机数种子
	for_each(v.begin(), v.end(), Print);
	cout << endl;


}


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
