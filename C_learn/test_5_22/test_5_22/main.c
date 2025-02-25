#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//这里讲解debug和release版本的除去文件大小外的区别
//结合5-23板书，release版本下 i 和 arr 数组在栈区的开辟顺序和debug版本下是不同的
//int main()//x86环境下开辟空间有用
//{
//	int i=0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//printf("%p\n", arr);//用来检验在栈区的开辟顺序
//	//printf("%p\n", &i);
//	for (i = 0; i <= 12; i++)
//	{  
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	return 0;
//}

//数据在开辟的空间中是如何存在的？
//Vs编辑器是小端存储方式，低位在低地址，高位在高地址
//int main()
//{
//	int a = 20;
//	//00000000000000000000000000010100原码
//	//0x00 00 00 14 -->16进制
//	//00000000000000000000000000010100反码
//	//00000000000000000000000000010100补码
//	int b = -10;
//	//10000000000000000000000000001010-原码
//	//0x80 00 00 0a
//	//11111111111111111111111111110101-反码
//	//0xff ff ff f5
//	//11111111111111111111111111110110-补码
//	//0xff ff ff f6
//	return 0;
//}


//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d\n", a, b, c);//a=-1,b=-1,c=255
//	//
//
//	char x = -128;
//	printf("x = %u\n", x);
//	printf("x = %d\n", x);
//	return 0;
//}
#include<windows.h>
//int main()
//{
//	unsigned int i;//此处i为初始化
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(1000);//休眠1000毫秒
//	}//此代码最后的结果是死循环，当 i = -1时被存入了无符号类型的i之中，通过补码读出来就是个非常大的数 
//	return 0;
//}

//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	return 0;
//}

//int main()
//{	//size_t是strlen的返回值类型，无符号整形
//	if (strlen("abc") - strlen("abcdef") >= 0)
//		printf(">\n");
//	else
//		printf("<\n");
//	return 0;
//}

//int main()
//{
//	float f = 5.5;
//	//5.5(float) = 101.1(二进制) = 1.011 * 2^2
//	// S=0 , M=1.011 , E=2
//	//存储浮点数的时候，内存 S + E + M
//	//0(S) 10000001(E+127=129) 01100000000000000000000(不存1，存011，后边添0补位)
//	//0100  0000  1011  0000  0000  0000  0000  0000
//	//4		0	  b		0	  0     0     0     0	
//	return 0;
//}


//喝汽水问题
//int main()
//{
//	int money = 0;
//	scanf("%d", &money);
//	int total = 0;
//	int empty = 0;
//
//	empty = money;
//	total = money;
//
//	while (empty >= 2)
//	{
//		total+= empty / 2 ;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//	return 0;
//}
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);

	total = money;
	empty = money;


	//置换
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;//空瓶数为，换的汽水，加剩下的单个汽水瓶子
	}

	printf("%d", total);
	return 0;
}
