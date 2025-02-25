#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//算数操作符
//int main()
//{
//	int a = 3;
//	int b = a << 1;
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//	//简单练习一下
//	int num1 = 1;//001
//	int num2 = 2;//010
//	printf("%d\n", num1 & num2);//000 --> 0 
//	printf("%d\n", num1 | num2);//011 --> 3
//	printf("%d\n", num1 ^ num2);//011 --> 3
//	return 0;
//}

//编写代码实现：求一个整数存储在内存中的二进制中1的个数
//int main()
//{
//	int a = 0;
//	printf("请输入一个整数:>");
//	scanf("%d", &a);
//	int count = 0;
//	int i = 0;
//	for (i = 0; i <= 32; i++)
//	{
//		a = a >> i;
//		if (a & 1 == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

//int main()
//{
//	int a = -10;
//	int* p = NULL;//令指针为空
//	printf("%d\n", !2);//0  逻辑取反，非0为真(一般为1)，0为假
//	printf("%d\n", !0);//1  
//	a = -a;
//	p = &a;
//	printf("%zu\n", sizeof(a));
//	printf("%zu\n", sizeof(int));
//	printf("%zu\n", sizeof a);//这样写行不行？
//	//printf("%d\n", sizeof int);//这样写行不行？
//	return 0;
//}


//int main()
//{
//	int a = 0;
//	//～的作用是按二进制位取反
//	//00000000000000000000000000000000 - 0的补码(0按照正数理解)
//	//11111111111111111111111111111111 - ~a(补码的形式)
//	//11111111111111111111111111111110 - ~a 减 1
//	//10000000000000000000000000000001 -  值为 -1
//	printf("%d\n", ~a);// -1
//
//	int b = 3;
//	//00000000000000000000000000000011 - 3的补码
//	//11111111111111111111111111111100 - ~3
//	//11111111111111111111111111111011 - ~3 - 1
//	//10000000000000000000000000000100 -  -4(上一条反码，符号位不变，其余位取反)
//	printf("%d\n", ~b);// -4
//	
//	int c = 13;
//	c |= (1 << 1);//(此步达到的效果是让a或上1左1移位的值，置位指定位置0为1)
//	printf("%d\n", c);
//	//
//	//00000000000000000000000000001101 -> 13的补码
//	//00000000000000000000000000000010 -> 1<<1
//	//00000000000000000000000000001111 -> 前两者 或 一下的到该值，也就达到了置位1的作用  
//	
//
//	
//	int d = 13;
//	//00000000000000000000000000001101 -> 13的补码
//	//00000000000000000000000000010000 -> 1<<4
//	//00000000000000000000000000011101 -> 前两者 或 一下的到该值，也就达到了置位1的作用 //结果为29
//	d |= (1 << 4);//(此步达到的效果是让a或上1左1移位的值，置位指定位置0为1)
//	printf("%d\n", d);//29
//	d &= ~(1 << 4);//这一步太过于精妙
//	printf("%d\n", d);
//	//
//
//	return 0;
//}
//void test(int n)
//{
//
//}
//int main()
//{
//	int a = 3;
//	//int b = ++a;//前置++，先++，后使用，先a = a+1，再赋值给b，a会在原来的基础上＋1再被使用
//	int c = a++;//后置++，先使用，后++，a = 3先赋值给c，然后 a变为 a+1
//	printf("%d\n", a); // 4
//	//printf("%d\n", b); // 4
//	printf("%d\n", c); // 4
//
//	int e = 10;
//	printf("%d\n", e--);//先使用，打印10，然后e会减1变为9
//	printf("%d\n", e);
//
//
//	int f = 10;
//	test(f--);//传递给函数的任然是10，而后f会减1变为9
//	return 0;
//}

// 解引用操作符 *
//int main()
//{
//	int a = 10;
//	int* p = &a;//int*,代表p的类型，整形的指针类型，p，里边存放的是地址
//	*p = 20;//其本质意思是通过p找到p中地址所指向的a变量，*p等价于a
//	return 0;
//}


//强制类型转换
//int main()
//{	//3.14这类小数会被编译器默认为double类型，3.14f才会被认为是float类型
//	int a = (int)3.14;//将double类型的3.14强制转化为整形，去掉小数部分
//	printf("%d\n",a);
//	return 0;
//}

// []操作符
//int main()
//{
//	int arr[10] = { 0 };
//	arr[7] = 8;
//	7[arr] = 9;//都是更改数组第七个元素的值，[]是一个操作符
//
//	//arr[7]	可以写作    *(arr+7)加法交换律*(7+arr)
//	// arr是首元素地址，arr+7就是跳过7个元素指向了第八个元素
//	// *(arr+7)就是第8个元素 
//	return 0;
//}

//结构成员访问操作符
#include<string.h>
//创建一个学生结构体
//struct Stu
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//void SetStu(struct Stu* ps)//这里为了直接改变s的参数，需要用传址调用的方式，用结构体指针ps来接收s的首地址
//{
//	//  结构体指针 -> 成员
//	strcpy(ps->name, "zhanghaosen");//意为将ps指针所指向对象s中的name赋值字符串
//	ps->age = 20;
//	ps->score = 100.0;
//}
////void PrintStu(struct Stu ss)
////{
////	//  结构体对象 -> 成员
////	printf("%s %d %lf", ss.name, ss.age, ss.score);
////}//存在极大的空间浪费
//void PrintStu(struct Stu* ps)
//{
//	printf("%s  %d  %.2lf", ps->name, ps->age, ps->score);
//}
//int main()
//{
//	struct Stu s = { 0 };//初始化结构体变量s
//	SetStu(&s);
//	//PrintStu(s);
//	PrintStu(&s);
//
//	return 0;
//}



struct Stu
{
	char name[10];
	int age;
	char sex[5];
	double score;
};
void set_age1(struct Stu stu)//该段函数采用的传值调用，是零时拷贝，这里赋值不会改变主函数中stu的age值
	{
		stu.age = 18;
	}
	void set_age2(struct Stu* pStu)
	{
		pStu->age = 18;//结构成员访问
	}
	int main()
	{
		struct Stu stu;
		struct Stu* pStu = &stu;//结构成员访问
		stu.age = 20;//结构成员访问
		set_age1(stu);
		pStu->age = 20;//结构成员访问
		set_age2(pStu);
		return 0;
	}