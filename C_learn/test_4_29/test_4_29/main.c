#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//指针讲解
//X86 - 32位的环境
//X64 - 64位的环境
//int main()
//{
//	int a = 0x11223344;
//	char* pc = NULL;
//	short* ps = NULL;
//	int* pi = NULL;
//	double* pd = NULL;
//
//	//sizeof 的返回值类型是无符号整形  zu来打印
//	printf("%u\n", sizeof(pc));
//	printf("%u\n", sizeof(short*));
//	printf("%u\n", sizeof(ps));
//	printf("%u\n", sizeof(pi));
//	printf("%u\n", sizeof(pd));
//
//	//既然指针类型所占空间均是4\8那么为什么不直接规定一个变量类型来存放地址呢
//	//这里来探讨指针类型的意义
//
//
//	return 0;
//}

//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	//野指针就是，指针指向的位置是不可知的
//	int* p;//此处p没有初始化，就意味着没有明确的指向
//	//一个局部变量不初始化话，放的是随机值
//	*p = 10;//非法访问内存了，这里的p就是野指针
//
//	//内存空间释放导致的野指针
//	int* pa = test();//当调用完函数之后，a这个临时空间就被释放了，就像你还记得
//	//前女友电话，你仍然能联系她，但是她不再属于你受你调用了，这也是野指针的类型
//	return 0;
//}



//指针加减整数
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//通过数组下标的方式赋值
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 1;
//	}
//
//	int* p = arr;//指针变量里边存的是arr数组首元素地址
//	for (i = 0; i < sz; i++)
//	{
//		//*(p+i)=2,实现的效果和后边一样
//		*p = 1;
//		p++;
//	}
//	return 0;
//}


//指针加减指针
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", &arr[9] - &arr[0]);//结果为 9 ，代表九个元素个数
//	//指针减指针的绝对值得到的是指针和指针之间元素的个数
//	//不是所有指针都能相减，指向同一块空间的2个指针才能相减
//	return 0;
//}

//求字符串长度
//1、
//int MyStrlen(char* str)//因此要用char*类型的变量接受
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//2、递归

//3、用地址减去地址的方式
//int MyStrlen(char* str)
//{
//	char* start = str;//首元素地址
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return (str - start);//此处str为 \0 的地址
//}
//int main()
//{
//	int len = MyStrlen("abcdefg");//字符串传参传的是字符串首元素地址
//	printf("%d\n", len);
//
//	return 0;
//}


//#define N_VALUES 5
//float values[N_VALUES];
//float* vp = NULL;
//
//int main()
//{
//	for (vp = &values[0]; vp < &values[N_VALUES];)
//	{
//		*vp++ = 12;
//	}
//	return 0;
//}


//二级指针

//int main()
//{
//	int a = 10;
//	//int * pa的理解 *说明pa是指针变量，int说明pa指向的类型是int类型
//	int* pa = &a;//pa是一个指针变量，一级指针变量
//	*pa = 20;//a变为了20
//	printf("%d\n", a);
//
//	//int* * ppa,第二颗星说明ppa是指针变量，int*说明ppa所指向的对象类型整体为int*
//	int** ppa = &pa;//此时的ppa是一个二级指针，存放了pa的地址
//	
//	**ppa = 30;//*ppa指向了pa这个变量，*ppa才是解引用a
//	
//	printf("%d\n", a);
//
//
//
//	return 0;
//}

//指针数组：存放指针的数组叫做指针数组
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	int arr[10] = { 0 };
//
//	int* pa = &a;
//	int* pb = &b;
//	int* pc = &c;
//
//	int* parr[10] = { &a,&b,&c };
//
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", *(parr[i]));
//	}
//
//	
//	return 0;
//}

//指针数组来模拟二维数组

int main()
{
	int arr[3][4] = { 1,2,3,4,2,3,4,5,3,4,5,6 };
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 2,3,4,5 };
	int arr3[4] = { 3,4,5,6 };
	int* parr[3] = { arr1,arr2,arr3 };//存放的是首元素地址

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", parr[i][j]);
			//printf("%d ", *(parr[i]+j));//效果同上
//parr[i][j]==*(parr[i]+j)==*(*(parr+i)+j)			
//parr是一个指针数组，存放的是arr1数组(首元素地址)，parr[i]读出了地址
//parr[i]则代表元素地址，parr[i][j],则是对数组解引用
//arr[1]=*(arr+1);
		}
		printf("\n");
	}

	return 0;
}