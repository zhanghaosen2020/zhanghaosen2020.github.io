#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//�Ӵ�С���������������������մӴ�С��˳���ӡ����
//int main()//����д����̫����
//{
//	int a, b, c;
//	a = b = c = 0;
//
//	printf("��������������(�м��ÿո����):>");
//	scanf("%d %d %d", &a, &b, &c);
//
//		if ((a >= b) && (a >= c))
//		{
//			printf("%d ", a);
//			if (b >= c)
//			{
//				printf("%d %d\n", b,c);
//			}
//			else
//			{
//				printf("%d %d\n", c,b);
//			}
//		}
//		if ((b >= a) && (b >= c))
//		{
//			printf("%d ", b);
//			if (a >= c)
//			{
//				printf("%d %d\n", a, c);
//			}
//			else
//			{
//				printf("%d %d\n", c, a);
//			}
//		}
//		if ((c >= a) && (c >= b))
//		{
//			printf("%d ", c);
//			if (a >= b)
//			{
//				printf("%d %d\n", a, b);
//			}
//			else
//			{
//				printf("%d %d\n", b, a);
//			}
//		}
//	return 0;
//}

//int main()
//{
//
//	int a, b, c;
//	a = b = c = 0;
//	int tmp = 0;//����һ����������
//	
//	printf("��������������(�м��ÿո����):>");
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}


//�ϱ߸���һ�����ѽ�������ֵ�Ĺ��ܣ�д��������˳�㸴ϰ����ַ���úʹ�ֵ����
//��������ֵ�ĺ���
//void Swap(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//
//int main()
//{
//
//	int a, b, c;
//	a = b = c = 0;
//
//	printf("��������������(�м��ÿո����):>");
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

//дһ�������ӡ1-100֮������3�ı���
//int main()
//{ 
//	//����1-100������
//	int i = 0;
//	//for (i = 1; i <= 100; i++)
//	//{
//	//	if (i % 3 == 0)
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//}
//	for (i = 3; i <= 100; i+=3)//����һ�����ķ�ʽ
//	{
//			printf("%d ", i);
//	}
//
//
//	return 0;
//}

//���������������������ֵ����Լ��
// Ӳ��
//int main()
//{
//	int a, b;
//	a = b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
// 
//	int min = (a < b) ?  a : b;//�����Ŀ��������Ǻ���
//	int m = min;
//	while (1)
//	{
//		if (a % m == 0 && b % m == 0)
//		{
//			printf("%d\n", m);
//			break;
//		}
//		m--;
//	}
//	//for (m = min; m > 1; m--)
//	//{
//	//	if ((a % m == 0) && (b % m == 0))
//	//	{
//	//		printf("%d\n",m);
//	//		break;
//	//	}				
//	//}		
//	//printf("%d ", b);
//	return 0;
//}

//int main()
//{
//	int a, b;
//	a = b = 0;
//	int c = 0;
//	scanf("%d %d", &a, &b);
//
//	//����շת�����
//	//�ȵ���˳��
// ��������Ŀ����������㣬��ʮ�ָ�Ч��
//	if (a <= b)
//	{
//		int tmp = a;
//		a = b;
//		b = tmp;
//	}
//	//շת
//	do
//	{
//		c = a % b;
//		a = b;
//		b = c;
//		c = a % b;
//	}
//	while (c != 0);
//	printf("%d ", b);
//	return 0;
//}


//��ӡ1000-2000֮�������
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
//		{
//			printf("%d\t",i);
//		}
//	}
//	return 0;
//}
//
//#include<math.h>
////��ӡ100-200֮�������
//int main()
//{
//	����100-200����
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;//������־λ��1Ϊ������0Ϊ������
//		for (j = 2; j <=sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}


//1-100��������9�ĸ���
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100;i++)
//	{
//		//����д��©��һ����
//		//if ((i / 9 == 0) || (i % 10 == 9))
//		//{
//		//	count++;
//		//}
//		//�ж�ʮλ�ǲ���9
//		if (i / 10 == 9)
//			count++;
//		//�жϸ�λ�ǲ���9
//		if (i % 10 == 9)
//			count++;
//	}
//	printf("count = %d \n", count);
//	return 0;
//}


//����1/1-1/2+1/3-1/4+...-1/100
//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 != 0)
//		{
//			sum += (1.0 / i);
//		}
//		else
//		{
//			sum -= (1.0 / i);
//		}
//	}
//	printf("%lf \n", sum);
//	return 0;
//}

//�Ż��ϱߵĴ���(ʹ�临�ӶȽ���)
//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + flag * 1.0 / i;
//		flag = -flag;//����������ϱߣ�for���ֻ�õ�����ֵ���㣬�ϱ߻��õ����жϣ�Ч�ʻ��һЩ
//	}
//	printf("%lf \n", sum);
//	return 0;
//}

//�ҳ�ʮ�������е����ֵ�������������
int main()
{
	int arr[] = { 10,20,1,19,100,101,22,4,2,200 };
	int i = 0;
	int max = 0;
	max = arr[0] < arr[1] ? arr[1] : arr[0];
	for (i = 0; i < 9; i++)
	{
		//max = arr[i] < arr[i + 1] ? arr[i + 1] : arr[i];	
		max = max > arr[i + 1] ? max : arr[i + 1];
	}
	printf("max = %d \n", max);
	return 0;
}