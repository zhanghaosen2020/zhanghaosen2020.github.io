#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
//int main()
//{
//	char arr1[] = "abcdef";//abcdef\0
//	int len = strlen(arr1);//起始地址到 \0 结束 计数
//	
//	char arr2[] = { 'b','i','t' };//如若这样初始化的话，没有以 \0 结尾，进而用上述函数得出随机值
//	
//	//int len = strlen(arr2);//这样子统计出来的长度是没有意义的
//	return 0;
//}

//模拟实现字符串函数

//计数器方法
//指针-指针
//递归的方式
//size_t my_strlen(const char* str)
//{
//	size_t count = 0;
//	assert(str);
//	while ((*str) != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	size_t n = my_strlen(arr);
//	printf("%u\n", n);
//	return 0;
//}

//int main()
//{
//	char name[20] = { 0 };
//	strcpy(name, "zhangsan");
//	//上面这样不麻烦吗？不如 name = "zhangsan";这样会报错，name是一个地址，地址是一个常量，不能被赋值
//	printf("%s\n", name);
//	return 0;
//}

//模拟实现strcpy
//char* my_strcpy(char* dest, const char* sour)
//{
//	assert(dest);
//	assert(sour);
//	char* ret = dest;
//	/*while (*sour != '\0')*/
//	while (*sour)
//	{
//		*dest++ = *sour++;
//	}
//	*dest = *sour;
//	//*dest = '\0';
//	return ret;
//}
//char* my_strcpy(char* dest, const char* sour)
//{
//	//assert(dest);
//	//assert(sour);
//	assert(dest && sour);
//	char* ret = dest;
//	while (*dest++ = *sour++)//既赋值又判断
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcedf";
//	char arr2[20] = { 0 };
//	my_strcpy(arr2,arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//字符串追加函数
//char* my_strcat(char* dest, const char* sour)
//{
//	assert(dest && sour);
//	char* ret = dest;
//	//找到目标空间的\0(末尾)
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//拷贝
//	while (*dest = *sour)
//	{
//		dest++;
//		sour++;
//	}
//
//}
//int main()
//{
//	char arr1[20] = "hello ";
//	//strcat(arr1, "world");
//	my_strcat(arr1, "world");
//	printf("%s\n", arr1);
//	return 0;
//}

//字符串比较函数
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
///*	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;*/ //麻烦了
//	return (*str1 - *str2);//ascll码值直接比较
//}
//int main()
//{
//	char arr1[20] = "zhaogsan";
//	char arr2[] = "zhangsanfeng";
//	//比较两个字符串是否相等
//	int ret = my_strcmp(arr1, arr2);
//	if (ret < 0)
//		printf("arr1 < arr2\n");
//	else if (ret > 0)
//		printf("arr1 > arr2\n");
//	else
//		printf("arr1 = arr2\n");
//
//	return 0;
//}


//上边是长度不受限制的字符串函数
//可以考虑长度受限制字符串函数



//查找子串函数strstr
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "hello bit";
//	strncpy(arr1, arr2, 6);
//
//	char str[] = "my name is zhanghaosen";
//	char substr[] = "zhanghaosen";
//	
//	char* ret = strstr(str, substr);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}	
//}


//模拟实现strstr函数
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);//保证传递的指针有效
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* p = str1;
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)p;//直接返回的话p是char*的，没有const，因而需要强制类型转换一下
//		}
//		p++;
//	}
//	return NULL;
//}
//int main()
//{
//	char str[] = "my name is zhanghaosen";
//	char substr[] = "zhanghaosen";
//	char* ret = my_strstr(str, substr);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}	
//}


//strtok用来切割字符串
//int main()
//{
//	const char* sep = ".@";
//	char email[] = "zhanghaosen@chongqingyoudian.com.ney";
//	char cpemail[40] = { 0 };
//	strcpy(cpemail, email);
//	char* ret = NULL;
//
//	for (ret = strtok(cpemail, sep);ret!='\0';ret=strtok(NULL,sep))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//strerror
//c语言的库函数，在执行失败的时候，都会设置错误码
//功能是将错误码转换为对应的错误信息
//int main()
//{
//	//printf("%s\n", strerror(0));
//	//printf("%s\n", strerror(1));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(4));
//	//	No error
//	//	Operation not permitted
//	//	No such file or directory
//	//	Interrupted function call
//
//	//errno - C语言设置的一个全局的错误码存放变量
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//
//	}
//	else
//	{
//		//
//	}
//
//	return 0;
//}

#include<ctype.h>

//int main()
//{
//	//int a = isspace(' ');//判断是不是空白字符
//	//printf("%d\n", a);
//	int a = isdigit(' ');
//	printf("%d\n", a);
//
//	printf("%c\n", tolower('W'));//大小的写转换函数
//	return 0;
//}


//模拟实现memcpy
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//这样子处理使得力度最为细腻让其一个字节一个字节的换
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7 };
//	int arr2[9] = {0};
//	memcpy(arr2, arr1, sizeof(arr1));//内存拷贝数据
//
//	float arr3[] = { 1.0,2.0,3.0,4.0 };
//	float arr4[8] = { 0.0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//
//	int arr5[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memcpy(arr5 + 2, arr5, 20);
//	memmove(arr5 + 2, arr5, 20);
//
//
//	return 0;
//}

//模拟实现memmove函数
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src); 
//	void* ret = dest;
//
//	if (dest < src)
//	{
//		//从前向后拷贝
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后向前拷贝
//		while (num--)//这一步妙不可言
//		{
//			*((char*)dest + num) = *((char*)src + num);//拿出尾巴上的字节交换
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 2, arr1,20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	return 0;
//}

int main()
{
	int arr1[] = { 1,2,3,4,5 };//01 00 00 00'02 00 00 00'03 00 00 00'04 00 00 00
	int arr2[] = { 1,3,2 };
	int ret = memcmp(arr1, arr2, 12);
	printf("%d\n", ret);

	char arr[] = "hello bit";
	//memset(arr, 'x', 5);
	memset(arr+6, '+', 3);

	printf("%s\n", arr);
	return 0;
}