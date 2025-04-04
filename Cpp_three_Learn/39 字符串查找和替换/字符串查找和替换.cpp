#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
//int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
//int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
//int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
//int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

//字符串查找
void test01()
{
	string str1 = "abcdefgde";
	int pos = str1.find("def");//会返回首次找到字符串的位置下标,从0开始计算,未找到会返回  -1
	cout << "pos = " << pos << endl;

	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;
	//rfind和find的区别在于前者从左往右查找,后者从右往左查找
}

//字符串替换
void test02()
{
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111");
	cout << "str1 = " << str1 << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
