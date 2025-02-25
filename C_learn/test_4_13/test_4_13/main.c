#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//goto语句
//int main()
//{
//	//这里完成的功能相当于一个死循环了，建议少使用
//again:
//	printf("haha\n");
//	printf("hehe\n");
//	goto again;
//	return 0;
//}

//关机程序
//1、电脑运行起来，1min内关机
//2、如果输入：我是猪   便取消关机
//int main()
//{
//	char input[20] = {0};
//	system("shutdown -a -t 60");
//again:
//	printf("请注意，你的电脑将在60秒内关机，如果输入：我是猪，就取消关机！\n");
//	scanf("%s", input);
//	
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//		printf("关机取消!");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}


//写的是求两个数的最大值
//返回类型和返回的值是一致的，int char ...
//int get_max(int x,int y)
//{
//	return(x > y ? x : y);
//}
//void test()//无返回值
//{
//	printf("hehe\n");
//}
////自定义函数
//int main()
//{
//	int a = 0, b = 0;
//	int max = 0;
//	scanf("%d %d", &a, &b);
//	//调用函数
//	max = get_max(a, b);
//
//	printf("%d\n", max);
//	return 0;
//}

//写一个函数可以交换两个整形变量的值

//void Swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}

int Swap(int* px, int* py)
{
	int z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前:a = %d b = %d\n", a, b);
	//a b是实参数，而调用函数后的x y是形参，形参是实参的临时拷贝，改变形参的值不会改变实参的值
	//对形参的修改不会影响实参
	//Swap(a, b);//交换a和b
	Swap(&a, &b);//把a，b的地址传递给指针变量px，py，再用*px =a *py=b间接交换两者的值
	printf("交换后:a = %d b = %d\n", a, b);
	return 0;
}