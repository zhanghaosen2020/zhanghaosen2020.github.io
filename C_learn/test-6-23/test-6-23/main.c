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
//	for (i = 0; i <= 10; i++)//���������Խ����ʣ����³���������
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
//	int arr[];//���������Ա
//};
//int main()
//{
//	//int sz = sizeof(struct S);
//	//printf("%d\n", sz);//4,�������鲻��������ֽڴ�С
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 40);//��̬�Ŀ�����һ��ռ�
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
//	//������������ĵط�
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
	//ʹ��
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}

	//����
	int* ptr = (int*)realloc(ps->arr, 80);
	if (ptr != NULL)
	{
		ps = ptr;
	}
	//�ͷ�
	free(ps->arr);
	free(ps);
	ps = NULL;
	return 0;
}