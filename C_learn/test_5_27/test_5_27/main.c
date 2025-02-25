#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//指针进阶

//int main()
//{
//	//通过地址修改单个字符值
//	//char ch = 'W';
//	//char* pc = &ch;
//	//*pc = 'B';
//	//printf("%c\n", ch);
//	//printf("%d\n", ch);
//
//	char* p = "abcdef";//把字符串首字母a的值，赋值给了p
//	//上边的赋值方式是不安全的，因为右边为常量字符串，如此赋值权限放大了。
//	const char* pc = "abcdef";//这合理些
//	char arr[] = "abcdef";//这样是把字符串存入数组里边去了
//	
//	printf("%s", p);//%s 是把地址p的值往后打印，直到 \0 为止
//	return 0;
//}

//模拟实现二维数组
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };//此处指针数组存放了三个地址
//	//打印模拟的二位数组(内存中不一定是连续存放的)
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			//printf("%d ", *(parr[i] + j));
//			//因为*(p+i)-->*p[i]
//			printf("%d ", parr[i][j]);
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}


//int main()
//{
//	char* arr[5] = { 0 };//指针数组，五个元素，每个元素的内容都是char*的
//	char*(*pc)[5] = &arr;//
//
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr1;
//	//打印(数组指针的用法)
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		//printf("%d ", *p);//p是指向数组的，*p其实就相当于数组名，数组名又是数组首元素地址
//			//所以*p本质上是数组首元素的地址
//		printf("%d ", *(*p + i));//很别扭
//	}
//
//	return 0;
//}



//数组指针的用法
//void print1(int arr[3][5],int c,int r)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		int j = 0;
//		for (j = 0; j < r; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void print2(int(*p)[5], int c, int r)
//{
//	int i = 0;
//	for (i = 0; i < c; i++)
//	{
//		int j = 0;
//		for (j = 0; j < r; j++)
//		{
//			//printf("%d ", *(*(p + i) + j));
//			//p的类型是int*[5],p是指向一个整形数组的，数组个元素int[5]
//			//p+1跳过5个int元素的数组。
//			printf("%d ", p[i][j]);
//
//		}
//		printf("\n");
//
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//	print1(arr, 3, 5);
//	printf("\n");
//	print2(arr, 3, 5);
//
//	return 0;
//}


//函数指针
int Add(int x, int y)
{
	return x + y;
}

//传递的实参是Add函数名，也即函数地址，因该用函数指针来接收
void calc(int(*pf)(int, int))
{
	int a = 3;
	int b = 5;
	int ret = pf(a, b);
	printf("%d ", ret);
}
int main()
{
	int(*p)(int, int) = Add;//如此就将Add函数的地址传递给了p
	//int(*p)(int, int) = &Add;//这句代码和上边的是一个意思
	//&函数名和函数名都代表函数的地址

	int ret = (*p)(3, 6);
	//*是一个摆设，p中存放了函数的地址，对p解引用，就是函数Add,再传入参数就可以当作函数使用了

	printf("%d\n", ret);
	
	calc(Add);
	return 0;
}