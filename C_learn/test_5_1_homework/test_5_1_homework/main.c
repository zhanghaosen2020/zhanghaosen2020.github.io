#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//дһ���������ض����Ʋ�����1�ĸ���

//��1��λ���������ж�
//int Count(int n)
//{
//	int count = 0;//ͳ��1�ĸ���
//	int i = 0;//ѭ������
//	for (i = 0; i < 32; i++)
//	{
//	//	if((n>>i)&1 == 1)//Ч��ͬ��
//		if ((n & (1 << i)) != 0)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//��2��ȡ��ÿһλ���ж�
//ȱ���ǣ������㸺���Ķ�����1�ĸ���ʱ�������

//int Count(int n)
//�Ľ��汾
//int Count(unsigned int n)
//{
//	int count = 0;//ͳ��1�ĸ���
//	while (n / 2 != 0)//������ж�����д�������⣬�ܻ�©ͳ��һλ
//	while(n)//��nΪ0֮��n�Ķ�����λ�Ͳ�������1��
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//		}
//		n /= 2;
//	}
//	return count;
//}

//��3��ʮ��NB��һ���㷨
//int Count(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);//Ӧ��ϸϸ��ĥ����ߵ��ŵ�//Google������Ŀ
//		count++;
//	}
//}
//
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int count = Count(num);
//	printf("%d\n", count);
//
//
//	return 0;
//}


//�����������Ķ���������Ӧλ�Ĳ�ͬ����  (���Ǻ�����ģ�黯���Ĳ��ã��������ģ��ֱ�ӽ��������������ܱȽϳ���ͬ�Ķ�����λ���ź�)
// ������һ�����������Ŀ
//int Count(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);//Ӧ��ϸϸ��ĥ����ߵ��ŵ�//Google������Ŀ
//		count++;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n,&m);
//	int count = Count(n^m);
//	printf("%d\n", count);
//	return 0;
//}
// 
//ȡ��ÿһλ��Ȼ��һһ�Ƚ�Ҳ��һ�ֽ������
//int Count_Diff_Bit(int m, int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((m & (1 << i)) != (n & (1 << i))))
//		{
//			count++;
//
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int count = Count_Diff_Bit(m, n);
//	printf("%d\n", count);
//	return 0;
//}

//��ӡһ��������λ������λ��ż��λ
int main()
{
	//����
	int num = 0;
	scanf("%d", &num);

	//��ȡ����λ
	int i = 0;
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	printf("\n");
	//��ȡż��λ
	for (i = 32; i >= 2; i -= 2)
	{
		printf("%d ", ((num >> i) & 1));
	}
	//�˴�����Ū����ˣ�(num>>i)��(num<<i)�����ַ�ʽȡ��ÿһλ�ķ����ǲ�ͬ�ģ�ǰ��ȡ���ľ���1��0���߲�����

	return 0;
}