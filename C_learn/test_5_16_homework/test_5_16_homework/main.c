#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//��ָ��ķ�ʽ��ӡ����
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p+i));
//	}
//	printf("\n");
//	return 0;
//}

//void Print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	return 0;
//}

//����һ���ַ���
//void Reverse(char* p)
//{
//	int left = 0;
//	int right = 0 ;
//	while (*(p + right) != '\0')
//	{
//		right += 1;
//	}
//	while (left < right-1)
//	{
//		char tmp = '0';
//		tmp = *(p + left);
//		*(p + left) = *(p + right-1);
//		*(p + right-1) = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char str[10001] = {0};
//	/*scanf("%s", &str);*/
//	gets(str);//��ȡ�����ַ����ķ�ʽ֮һ
//
//	Reverse(str);
//	printf("%s\n", str);
//
//	return 0;
//}


//#include<string.h>
//int main()
//{
//	char str[10001] = { 0 };
//	int left = 0;
//	int right = 0;
//	gets(str);
//	right = strlen(str) - 1;
//	while (left < right)
//	{
//		char tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		left++;
//		right--;
//	}
//	printf("%s\n", str);
//	return 0;
//}

//������� Sn = a + aa + aaa + aaaa + aaaaa
//int main()
//{
//	int a = 0;
//	int n = 0;
//	scanf("%d %d", &a,&n);
//	
//	int sum = 0;
//	int k = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		k = k * 10 + a;//�ؼ��Ĳ�ִ���
//		sum += k;
//	}
//	printf("%d", sum);
//	return 0;
//}

//��ӡˮ�ɻ���
//�����Ŀ��Ҫ���Ƿ������⣬��Ҫ��ѭ���ڲ��ı�ѭ�������������ᵼ����ѭ��;
//#include<math.h>
//int main()
//{
//	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
//	int i;
//	for (i = 0; i <= 100000; i++)
//	{
//		//�ж�һ�����ǲ���һ��ˮ�ɻ���
//		//1.�ж�i�Ǹ���λ��-->n
//		int n = 1;//һ��������Ϊ1λ��
//		int tmp = i; //����ѭ���ڲ��ı�ѭ����ֵ
//		int sum = 0;
//		while (tmp / 10)
//		{
//			n++;
//			tmp /= 10;
//		}
//		//2.���������λ�����ּ�n�η�
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}
//#include<math.h>
//int Narcissistic_number(int i)//�ж�ˮ�ɻ����ĺ�����װ
//{
//	//�ж�һ�����ǲ���һ��ˮ�ɻ���
//		//1.�ж�i�Ǹ���λ��-->n
//	int n = 1;//һ��������Ϊ1λ��
//	int tmp = i; //����ѭ���ڲ��ı�ѭ����ֵ
//	int sum = 0;
//	while (tmp / 10)
//	{
//		n++;
//		tmp /= 10;
//	}
//	//2.���������λ�����ּ�n�η�
//	tmp = i;
//	while (tmp)
//	{
//		sum += pow(tmp % 10, n);
//		tmp /= 10;
//	}
//	if (sum == i)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int i;
//	for (i = 0; i <= 100000; i++)
//	{
//		if (Narcissistic_number(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//��ӡ����
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	int i = 0;
//	for (i = 0; i < line; i++)
//	{
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ*��
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	//��ӡ�±�
//	for (i = 0; i < line - 1; i++)
//	{
//		//��ӡ�ո�
//		int j = 0;
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//		//��ӡ * ��
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)//��һ���Ƚ���
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//
//}

//����ˮ���⣬һԪһƿ��ˮ��������ƿ��1ƿ��ˮ��20Ԫ���Ժȶ�����ˮ
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);

	total = money;
	empty = money;


	//�û�
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;//��ƿ��Ϊ��������ˮ����ʣ�µĵ�����ˮƿ��
	}

	printf("%d",total);
	return 0;
}
