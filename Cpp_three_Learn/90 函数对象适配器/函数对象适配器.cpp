#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

//Print��̳���std::binary_function<int, int, void>������һ�������������Ļ��࣬���ڱ�ʾһ��������������������void�Ķ�Ԫ������
//operator()�����˺��������������������������val��start������������Ӻ��ӡ������
//const���η���ʾ�ú��������޸Ķ�����κγ�Ա��������ʹ�øú������Ա�const������á�
class Print:public binary_function<int,int,void >
{
public:
	void operator()(int val,int start)const
	{
		cout << val+start<< endl;
	}
};
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	cout << "��������ʼ�ۼ�ֵ: " << endl;
	int start = 0;
	cin >> start;
	
	for_each(v.begin(), v.end(), bind2nd(Print(),start));
}

//1,��bind2nd
//2,�̳�public_functin<int,int,void>
//3,��const


int main() {
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
