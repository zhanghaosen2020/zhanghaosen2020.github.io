#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//��ӡָ��ͼ��

//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) == 1)
//	{
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < num; i++)
//		{
//			for (j = 0; j < num; j++)
//			{
//				if ((i == j) || (i + j == num - 1))
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//��ӡָ�����·ݵ�����

//case���
//ƽ�꣺31 28 31 30 31 30 31 31 30 31 30 31
//���꣺31 29 31 30 31 30 31 31 30 31 30 31
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	while(scanf("%d %d", &year, &month)==2)
//	{
//		switch (month)
//		{
//			case 1:
//			case 3:
//			case 5:
//			case 7:
//			case 8:
//			case 10:
//			case 12: {
//				printf("31\n");
//				break;
//			}
//			case 4:
//			case 6:
//			case 9:
//			case 11:
//			{
//				printf("30\n");
//				break;
//			}
//			case 2:
//			{
//				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//				{
//					printf("29\n");
//				}
//				else
//				{
//					printf("28\n");
//				}
//				break;
//			}
//			default :
//				break;
//			}
//	}
//	return 0;
//}

//����(��bug)
//int Is_leapyear(int year)
//{
//	if ((year % 4 == 0 && year % 400 != 0) || year % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int d[11] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (scanf("%d%d", &year, &month)==2)
//	{
//		if (Is_leapyear(year) == 1)
//		{
//			d[1] += 1;
//		}
//		printf("%d", d[month + 1]);
//	}
//	return 0;
//}