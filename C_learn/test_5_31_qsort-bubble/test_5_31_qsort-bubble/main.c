#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//先写一个简单的冒泡排序
void qbubble_sort(int arr[], int sz)
{
	//冒泡的趟数
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;//每一趟需要compare多少次
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//交换
				int tmp = 0;
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = tmp;
			}
		}
	}
}


//来引用一个qsort函数试试吧
int compare(const void* elem1, const void* elem2)
{
	return (*(int*)elem1) - (*(int*)elem2);
}

//来搞一个用刚写的冒泡排序，模拟实现qsort排序(优点是可以实现不同类型数据的排序)
void Swap(char* buf1, char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width;i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void*base,int sz,int width,int compare(const void*elem1,const void*elem2))
{
	//冒泡的趟数
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;//每一趟需要compare多少次
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (compare(((char*)base) + j * width, ((char*)base) + (j + 1) * width) > 0)
			{
				//交换
				Swap(((char*)base) + j * width, ((char*)base) + (j + 1) * width,width);
			}
			//if (arr[j] > arr[j + 1])
			//{
			//	//交换
			//	int tmp = 0;
			//	tmp = arr[j];
			//	arr[j] = arr[j + 1];
			//	arr[j + 1] = tmp;
			//}
		}
	}
}

int main()
{
	//定义数组、数组长度
	int arr[10] = { 9,100,7,6,5,4,3,2,1,0 };
	int sz = 0;
	sz = sizeof(arr) / sizeof(arr[0]);
	
	//冒泡排序
	//bubble_sort(arr, sz);
	
	//qsort快速排序
	//qsort(arr,sz,sizeof(arr[0]),compare);
	
	//改造的冒泡排序
	qbubble_sort(arr, sz, sizeof(arr[0]), compare);
	//打印出排序的数组
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}