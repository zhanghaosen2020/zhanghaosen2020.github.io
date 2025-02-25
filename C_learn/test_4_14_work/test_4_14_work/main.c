#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//写一个函数判断一年是不是润年
//能被4整除，但不能被100整除
//或者能被400整除
//int Is_LeapYear(int x)
//{
//	if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400) == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	printf("请输入要判断的年份:>");
//	scanf("%d", &year);
//
//	if (Is_LeapYear(year))
//	{
//		printf("year = %d 是闰年", year);
//	}
//	else
//	{
//		printf("year = %d 不是闰年", year);
//	}
//	return 0;
//}

//打印1000-2000之间的闰年
//为什么不同时打印呢？ 这样函数会不够单一，模块化程度不够（减少耦合性）
//int Is_LeapYear(int x)
//{
//	if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400) == 0)//这样简化了代码
//	{
//		return 1;//闰年返回1，否则返回0；
//	}
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	printf("1000-2000年之间的闰年有:>\n");
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (Is_LeapYear(year))
//		{
//			printf("%d\t ", year);//\t是制表符
//		}
//	}
//	return 0;
//}

//3. 写一个函数，实现一个整形有序数组的二分查找。

//第一个参数 int arr[],实际上，主函数传递给它的是数组首元素地址，后边的调用都是在
//调用主函数中的arr[],数组传参，不是一份临时拷贝，是指针变量在调用原数组
//所以在函数内部计算一个函数参数部分的数组元素个数孰不靠谱的
//形参 arr 看上去是数组，本质上是一个指针变量
//int BinarySearch(int arr[],int num,int sz)//怎么将数组整个丢给函数？
//{
//	//定义变量
//	int left = 0;//左下标
//	int right = sz - 1;//右下标
//
//	//折半查找实现
//	while (left <= right)
//	{
//		//int mid = (right + left) / 2;//折半
//		int mid = left + (right - left) / 2;//这样设置mid不会溢出
//
//		if (arr[mid] < num)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > num)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;//找到之后返回下标
//			break;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//int main()
//{
//	int arr[] = { 1,3,5,7,9,10,12,13,15,19 };//先定义一个有序整形数组
//	int num = 0;//要查找的数字
//	int sz = sizeof(arr) / sizeof(arr[0]);//元素个数
//	//输入
//	printf("请输入要查找的数字:>");
//	scanf("%d", &num);
//
//	//查找
//	//找到返回下标，未找到返回 -1；
//	int ret = BinarySearch(arr, num, sz);
//	if (ret == -1)
//	{
//		printf("未找到!");
//	}
//	else
//	{
//		printf("找到了,下标为:%d",ret);
//	}
//
//	return 0;
//}
//复习一下二分法   BinarySearch 
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,11 };//定义一个有序整形数组
//	int left = 0;//数组左下标
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;//元素个数-1，右下标
//	int num = 0;
//	
//	printf("请输入要查找的数字:>");
//	scanf("%d", &num);
//
//		while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < num)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > num )
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标为：%d\n", mid);
//			break;
//		}
//	}		
//	if (left > right)
//	{
//		printf("找不到该数!\n");
//	}
//	return 0;
//}

//4. 写一个函数，每调用一次这个函数，就会将 num 的值增加1。
void Add(int* p)//无返回值用void
{
	*p += 1;
}

int main()
{
	int num = 0;
	Add(&num);//Add()调用一次num会加1，用传址调用比较符合
	printf("num = %d\n", num);
	Add(&num);
	printf("num = %d\n", num);
	return 0;
}