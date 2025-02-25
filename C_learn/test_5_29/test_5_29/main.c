#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//int test(const char* str)
//{
//	printf("test()\n");
//	return 0;
//}
//int main()
//{
//	//函数指针--也是一种指针，是指向函数的指针
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	//&函数名和函数名都是代表该函数的地址
//
//	//现在尝试把函数地址存放起来，就要用到函数指针
//	int(*pf)(const char*) = test;//pf指向的函数的参数类型是 const char*
//	(*pf)("abc");//此处的*可以不写，但是写了就必须加括号与pf凑一起
//	//本质上pf和test是一回事情
//	pf("abcd");//这样写也是正确的，比上边的更简洁，但是上边的更容易理解(解引用来理解)
//
//	//int len = sizeof(&test);
//	//printf("%d", len);//x86下，len为4
//	return 0;
//}


//函数指针的用途

//写一个计算器
//加法、减法、乘法、除法
//这种实现方式叫做回调函数(机制)
//函数指针非常的牛哦！！！！
//void menu()
//{
//	printf("****************************\n");
//	printf("****	1.add	2.sub	****\n");
//	printf("****	3.mul	4.div	****\n");
//	printf("****	0.exit		****\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// int Div(int x, int y)
//{
//	return x / y;
//}
//
// void calc(int(*pf)(int, int))
// {
//	 int x = 0;
//	 int y = 0;
//	 int ret = 0;
//	 printf("请输入2个操作数:>");
//	 scanf("%d %d", &x, &y);
//	 ret = pf(x, y);
//	 printf("%d\n",ret);
// }
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 0:
//			printf("退出计算器\n");
//			break;
//		case 1:
//			calc(Add);
//			break;
//		case 2:
//			calc(Sub);
//			break;
//		case 3:
//			calc(Mul);
//			break;
//		case 4:
//			calc(Div);
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//
////int main()
////{
////	int input = 0;
////	int x = 0;
////	int y = 0;
////	int ret = 0;
////	do 
////	{
////		menu();
////		printf("请选择:>");
////		scanf("%d", &input);
////
////		switch (input)
////		{
////		case 0:
////			printf("退出计算器\n");
////			break;
////		case 1:
////			printf("请输入2个操作数:");
////			scanf("%d %d", &x, &y);
////			ret = Add(x, y);
////			printf("%d\n", ret);
////			break;
////		case 2:
////			printf("请输入2个操作数:");
////			scanf("%d %d", &x, &y);
////			ret = Sub(x, y);
////			printf("%d\n", ret);
////			break;
////		case 3:
////			printf("请输入2个操作数:");
////			scanf("%d %d", &x, &y);
////			ret = Mul(x, y);
////			printf("%d\n", ret);
////			break;
////		case 4:
////			printf("请输入2个操作数:");
////			scanf("%d %d", &x, &y);//有很多的冗余
////			ret = Div(x, y);
////			printf("%.2f\n", ret);
////			break;
////		default:
////			printf("选择错误\n");
////			break;
////		}
////	} while (input);
////	return 0;
////}




//函数指针数组，其实就是存放函数指针的数组
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// int Div(int x, int y)
//{
//	return x / y;
//}
//
// int main()
// {
//	 int(*pf)(int, int) = Add;//pf是函数指针
//	 //函数指针数组
//	 //定义一个数组arr[4],每个数组元素类型为函数指针类型
//	 int(*arr[4])(int, int) = { Add,Sub,Mul,Div };//arr就是函数指针的数组
//	 int i = 0;
//	 for (i = 0; i < 4; i++)
//	 {
//		int ret = arr[i](8, 4);
//		printf("%d\n", ret);
//	 }
//
//	return 0;
// }

//x&y,x^y,x|y,x||y,x&&y,x>>y,x<<y;

//void menu()
//{
//	printf("****************************\n");
//	printf("****	1.add	2.sub	****\n");
//	printf("****	3.mul	4.div	****\n");
//	printf("****	0.exit		****\n");
//	printf("****************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
// int Div(int x, int y)
//{
//	return x / y;
//}
//
// int main()
// {
// 	int input = 0;
// 	int x = 0;
// 	int y = 0;
// 	int ret = 0;
//
//    //因为此处使用了函数指针的数组，极大的简化了代码，还方便了后续优化
//    //转移表(函数指针的数组)
//    int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
// 	do 
// 	{
// 		menu();
// 		printf("请选择:>");
// 		scanf("%d", &input);
//        if (input == 0)
//        {
//            printf("退出计算器\n");
//        }
//        else if (input >= 1 && input <= 4)
//        {
//            printf("请输入2个操作数:");
//            scanf("%d %d", &x, &y);
//            ret = pfArr[input](x, y);
//            printf("%d\n", ret);
//        }
//        else
//        {
//            printf("选择错误\n");
//        }		
// 	} while (input);
// 	return 0;
// }



//回顾一下冒泡排序
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int flag = 1;//假设数组已经排好序的了，避免再次重复
	//确定趟数(趟数是元素个数-1)
	for (i = 0; i < sz - 1; i++)
	{
		//定义每趟里有多少次两两比较
		int j = 0;
		for(j=0;j<sz-1-i;j++)//(每趟比较次数)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

}

//C语言库里边的快速排序函数(回调函数)
//qsort-可以排任意数据类型的数据
//void qsort(void* base,//你要排序的数据的起始位置，用数组举例就是首元素地址
//		   size_t num,//待排序的数据元素个数
//		   size_t width,//待排序的数据元素的大小(单位是字节)
//		   int(__cdecl* compare)(const void* elem1, const void* elem2)// -是一个比较函数，四个参数，最后一个是函数指针
//		  );
//__cdecl：cdecl调用约定意味着：
//参数从右向左压入堆栈
//调用者负责清理堆栈
//C调用约定允许函数的参数的个数是不固定的，这也是C语言的一大特色。
//仅在函数名前加上一个下划线前缀，格式为_functionname。

//void*类型的指针为泛型，即没有确定的类型，什么类型都可以容纳，所以调用时应当强制类型转换再解引用
int compare_int(void* elme1, void* elme2)
{
	return (*(int*)elme1 - *(int*)elme2);//因为比较的是整形，需要这样做
}
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	//把数组排成升序
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素
	//bubble_sort(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), compare_int);

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
	return strcmp((*(struct Stu*)e1).name , (*(struct Stu*)e2).name);
	//return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//这样也是对的

}
void test2()
{
	//使用qsort来排序结构体数据
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",25} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);

}
int main()
{
	//test1();
	test2();
	return 0;
}