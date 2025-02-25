#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int* p = (int*)malloc(40);
//	if (NULL == p)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i <= 10; i++)//这里造成了越界访问，导致程序会出问题
//	{
//		p[i] = i;
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//struct S
//{
//	int n;
//	int arr[];//柔性数组成员
//};
//int main()
//{
//	//int sz = sizeof(struct S);
//	//printf("%d\n", sz);//4,柔性数组不会计算如字节大小
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);//动态的开辟了一块空间
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	ps->n = 100;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//
//	//体现柔性数组的地方
//	struct S* ptr=(struct S*)realloc(ps, sizeof(struct S) + 80);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//		ptr = NULL;
//	}
//
//	free(ps);
//	ps = NULL;
//	return 0;
//}
struct S
{
	int a;
	int* arr;
}s;
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		return 1;
	}
	ps->a = 100;
	ps->arr = (int*)malloc(40);
	if (ps->arr == NULL)
	{
		return 1;
	}
	//使用
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}

	//调整
	int* ptr = (int*)realloc(ps->arr, 80);
	if (ptr != NULL)
	{
		ps = ptr;
	}
	//释放
	free(ps->arr);
	free(ps);
	ps = NULL;
	return 0;
}