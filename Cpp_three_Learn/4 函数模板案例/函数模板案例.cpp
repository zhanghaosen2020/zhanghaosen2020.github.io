#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//实现一个通用的,对数组进行排序的函数
//规则从大到小,算法->选择
//测试 char数组,int数组

template<typename T>//声明一个模板,告诉编译器后面代码中紧跟着的T不要报错
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//排序算法
template<class T>
void mySort(T arr[], int len)//len为数组长度
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值的下标
		for (int j = i + 1; j < len; j++)
		{
			//认定出的最大值比遍历出来的最大值下标要小,说明遍历出来的j下标对应的元素才为最大值
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)//交换
		{
			//交换对应下标的元素
			mySwap(arr[max], arr[i]);
		}
	}
}

//提供一个打印数组模板
template<class T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void test01()
{
	//测试char数组
	char charArr[] = "dhifshiefh";
	int len = sizeof(charArr) / sizeof(charArr[1]);
	mySort(charArr, len);
	printArr(charArr, len);
}

void test02()
{
	int arrInt[] = { 1,2,42,4,21,4,234,234,234,2,232,1,2,5,643,3 };
	int len = sizeof(arrInt) / sizeof(arrInt[1]);
	mySort(arrInt, len);
	printArr(arrInt, len);
}

int main() {
	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}
