#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//enum Day
//{
//	Mon,//0
//	Tues,//1
//	Wed,//2
//	Thur,//3
//	Fir,//4
//	Sat,//5
//	Sun//6
//	//Ĭ�ϵĿ���ȡֵ�Ǵ�0����
//};
//
//int check_sys()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//
//int Check_sys()//�ⷽ��̫������
//{
//	union Un
//	{
//		int a;
//		char c;
//	}u;
//	u.a = 1;
//	return u.c;//���˼·���ϱߵķ���������һ��
//	//����1����С�ˣ�����0���Ǵ��
//
//}
//
//
//int main()
//{
//	//union Un u;
//	//printf("%u\n", sizeof(u));//4
//
//	//�жϼ�����Ĵ洢�Ǵ�˴洢����С�˴洢
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С�˴洢");
//	}
//	else
//	{
//		printf("��˴洢");
//	}
//
//	union Un2
//	{
//		short c[7];
//		int i;
//	};
//	//��������Ľ����ʲô��
//	//printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	return 0;
//}

#include<string.h>
#include<errno.h>
#include<stdlib.h>
//int main()
//{
//
//	//��̬�ڴ濪��
//	//malloc�ķ���ֵһ��Ҫ����һ����Ч�Ե��жϣ��������Ұָ��
//	int* p = (int*)malloc(40);//���ڴ�ռ�����40�ֽڿռ䣬����int*�ķ�ʽ��ȡ����
//	if (p == NULL)//������ȷ��������ڴ�ռ��ǳɹ���
//	{
//		printf("%s\n", strerror(errno));
//		return 1;//������ӡ������Ϣ����ֹ�������������һ���쳣����ֵ1
//	}
//	//ʹ�øոտ��ٵĿռ�
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	free(p);//������ڴ�ָ��Ŀռ�黹�ˣ�����p��Ȼ�����ǿ�ռ�ĵ�ַ
//	//������Ҫ�ֶ��ͷ�
//	p = NULL;//��p�ÿգ�����ʧ��
//
//	//����10�����͵Ŀռ�
//	int* ptr = calloc(10, sizeof(int));
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//��ӡ
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%d\n", *(ptr+i));
//		printf("%d ", ptr[i]);
//		
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(40);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	//ʹ�ã������ռ����Ϊ1��2��3��4��...10
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p[i] = i + 1;
	}
	//�ռ䲻������
	int*ptr = (int*)realloc(p, 80);
	if (ptr != NULL)
	{
		p = ptr;
		ptr = NULL;//��һ������ȱ��Ŷ�������p���ͷŵ��ˣ�����ͨ��ptr�ҵ�֮ǰ�Ŀռ䣬����Σ��
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;
	return 0;
}