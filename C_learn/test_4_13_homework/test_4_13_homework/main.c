#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//1.дһ���������ж�һ�����ǲ�������

//�ڽ������ 1 ֮ǰ���ȴ�ӡ��100-200֮�������
/*
int main()
{
	int i = 0;//i,j����ѭ������
	int j = 0;
	int count = 0;//ͳ�������ĸ���
	
	for (i = 100; i <= 200; i++)//�Ż�һ��i=101��i+2������������������Դͷ��СĿ��
	{
		int flag = 1;//������־λ��1-->Ϊ������0-->������
		for (j = 2; j <= i - 1; j++)//j<=sqrt(i),��Сѭ������()
		{
			if (i % j == 0)
			{
				flag = 0;
				break;//һ�������ˣ�������ѭ���ж�Ϊ����������־λҲ�ı�
			}
		}
		if (flag == 1)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n��������Ϊ��%d\n", count);//ͨ����ʽ���Ʒ������������Ҫ�ĸ�ʽ
	return 0;
}
*/

//���Ž������1
//�ж����Ƿ�Ϊ����

//void PrimeNum(int x)//�����漰��һ������������������⣨��
//{
//	int i = 0;//����ѭ��������Ϊʹ�����2 - i-1��������
//	int flag = 1;//������־λ��1Ϊ�أ�0Ϊ���ء�
//	for (i = 2; i <= x - 1; i++)
//	{
//		if (x % i == 0)
//		{
//			flag = 0;//��ʱ˵������xΪ������
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("num = %d ������", x);
//	}
//	else
//	{
//		printf("num = %d Ϊ����", x);
//	}
//}
//
//int main()
//{
//	//��������
//	int num = 0;
//	printf("������һ����:>");
//	scanf("%d", &num);
//
//	//�ж��Ƿ�Ϊ����
//	PrimeNum(num);
//
//	return 0;
//}

//�Ż��ϱߴ���

int IsPrime(int x)
{
	int j = 0;
	for (j = 2; j <= sqrt(x); j++)//������С�ڵ���sqrt(x),�ŶԷ����©��121��169��������
	{
		if (x % j == 0)
		{
			return 0;//return 0;ֱ�ӽ�������������½��ۣ�����break�Ļ���û����ô�ã���ࡣ
		}
	}
		return 1;
}
int main()
{
	int i = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		if (IsPrime(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n��������Ϊ:>%d\n", count);
	return 0;
}