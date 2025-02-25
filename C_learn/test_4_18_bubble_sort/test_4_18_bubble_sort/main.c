#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//数组传参的时候有两种写法
//1.数组形式
//2.指针形式



//void bubble_sort(int* arr,int sz)//形参是指针形式
//形参是数组形式
//void bubble_sort(int arr[],int sz)//数组传过来，数组接收
//{
//	//先确定趟数
//	int i = 0;
//	//数组传过来的本质是数组首元素的地址，因此本质上是一个指针变量
////	int sz = sizeof(arr) / sizeof(arr[0]);//在函数中计算数组的长度是不正确的
//	for (i = 0; i < sz - 1; i++)
//	{
//		//确定每一趟比较多少次
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			//相邻数据左作比较
//			if (arr[j] > arr[j + 1])
//			{
//				//交换
//				int tmp = 0;//交换的中间变量
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	//数组
//	//把该数组的数据排成升序
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//冒泡排序算法，对数组进行排序
//	bubble_sort(arr,sz);
//	//打印排完序的数组
//	int i = 0;	
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//二维数组数组名的理解
int main()
{
	int arr[3][4] = {0};
	int sz = sizeof(arr);//12个元素，1个整形元素4个字节，共48个字节
	printf("%d\n", sz);

	//如何计算二维数组的行和列数呢？
	//计算行 表示总的数组大小  arr[0]表示第一行的数组名，计算的是第一行的大小
	printf("%zu\n",sizeof(arr)/sizeof(arr[0]));

	//计算列   第一行的大小 除以  第一个元素的大小
	printf("%zu\n",sizeof(arr[0])/sizeof(arr[0][0]));

	//arr;//二维数组的数组名也表示数组首元素的地址//表示的行向量的首行地址，这个虽然和arr[0][0]值一样，
	//	//但是效果却很不一样，如arr+1跳过的是一行。
	return 0;
}