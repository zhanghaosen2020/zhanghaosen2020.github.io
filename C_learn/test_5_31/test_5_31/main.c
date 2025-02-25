#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	int flag = 1;//假设数组已经排好序的了，避免再次重复
//	//确定趟数(趟数是元素个数-1)
//	for (i = 0; i < sz - 1; i++)
//	{
//		//定义每趟里有多少次两两比较
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)//(每趟比较次数)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	//按照bit位交换值
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int flag = 1;//假设数组已经排好序的了，避免再次重复
	//确定趟数(趟数是元素个数-1)
	for (i = 0; i < sz - 1; i++)
	{
		//定义每趟里有多少次两两比较
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)//(每趟比较次数)
		{
			if ((cmp((char*)base + j * width, (char*)base + (j + 1) * width))>0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}				
		}
		if (flag == 1)
		{
			break;
		}
	}
}
int cmp(void* elme1, void* elme2)
{
	return (*(int*)elme1 - *(int*)elme2);//因为比较的是整形，需要这样做
}
void test1()
{
	int arr[] = { 99,8,7,6,5,4,3,2,10,0 };
	//把数组排成升序
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素
	bubble_sort(arr, sz,sizeof(arr[0]),cmp);
	//qsort(arr, sz, sizeof(arr[0]), compare_int);

	//打印排序后的数组元素
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
struct Stu
{
	char name[20];
	int age;
};
int cmp_stu_by_name(const* e1, const* e2)
{
	//return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
	//两字符串比较需要用到strcmp()函数
	return strcmp((*(struct Stu*)e1).name, (*(struct Stu*)e2).name);
	//return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//这样也是对的

}
void test2()
{
	//使用qsort来排序结构体数据
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);

}

int main()
{
	test1();
	test2();

	return 0;
}