#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = {0};
////	赋值
//	for (i = 0; i < 10; i++)
//	{
//		arr[i]=i;
//	}
//
////	打印
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//1!+2!+3!+...+n!//n的阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//
//	for (int j = 1; j <= n; j++)
//	{
//		int ret = 1;//ret置位为1
//		for (int i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n", sum);
//
//	return 0;
//} 

//下面是一个有缺陷的代码

//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}//这里会死循环
//	return 0;
//}
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;//此处是为了把 \0 也拷贝
//}


//非常简洁的写法
//#include<assert.h>
//void my_strcpy(char* dest, const char* src)
//{
//	//断言
//	assert(src != NULL);
//	assert(dest != NULL);//以上两句的意思是当传过来的指针为空指针的时候终止程序
//
//	//比如 h 赋值给 *dest 值为h的ascii码值，不为0，会继续循环直到遇到 \0
//	while (*dest++ = *src++)//这里是赋值语句，' \0 'ascii值为0
//	{
//		;
//	}
//}

//为什么库里边返回的是char*？而非上边的void，因为这样就可以实现链式访问，返回值做新的函数的参数
//strcpy返回的是目标空间的起始地址
char* my_strcpy(char* dest, const char* src)
{
	//断言
	assert(src != NULL);
	assert(dest != NULL);//以上两句的意思是当传过来的指针为空指针的时候终止程序
	char* ret = dest;
	//比如 h 赋值给 *dest 值为h的ascii码值，不为0，会继续循环直到遇到 \0
	while (*dest++ = *src++)//这里是赋值语句，' \0 'ascii值为0
	{
		;
	}

	return ret;
}

//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";//{ 0 };
//	char arr2[] =   "hello bit";
//	my_strcpy(arr1, arr2);
//	//strcpy在拷贝字符串的时候，会把源字符串中的 \0 也拷贝过去
//
//	printf("%s\n", arr1);
//	
//	return 0;
//}


int main()
{

	//int num = 10;
	//num = 20;
	//printf("%d\n", num);
	//可以轻松修改num的值

	//const int num = 10;
	//num = 20;//语句有误，num不能被修改
	//可以绕过const修改num值
	
	//int* p = &num;
	//*p = 20;//门锁着，翻窗户进来

	//const int* p = &num;
	//*p = 20;//不能改了

	//const修饰指针变量
	//1、const放在 * 的左边
	//意思是：p指向的对象不能通过p来改变了，但是p本身的值(某变量本身的地址)是可以改变的
//	const int num = 10;
//	const int* p = &num;
//	//*p = 20;//err
//	p = 222;//正确，因为p本身的地址是可以改变的

	//2、const放在 * 的右边
	//意思是：p指向的对象可以通过p来改变的，但是不能修改p变量本身的值
	const num = 10;
	int* const p = &num;
	*p = 100;//可以改变p指向的值
	//p = 99;//但是不可以修改p本身的值

	//3、*的左边和右边，都加const，就兼具上边两个作用

	printf("%d\n", num);

	return 0;
}