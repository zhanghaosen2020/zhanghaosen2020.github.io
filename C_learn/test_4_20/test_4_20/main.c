#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


////�ú����������δ�ӡÿһλ
//void Print(int num)
//{
//	if (num > 9)
//	{
//		Print(num / 10);
//	}
//	printf("%d ", num % 10);
//}
//
//
//int main()
//{
//	int num = 0;
//	printf("����������:>");
//	scanf("%d",&num);
//	Print(num);
//	return 0;
//}

//����׳�
//int Factorial(int n)
//{
//	if (n > 1)
//	{
//		return n * Factorial(n - 1);
//		n--;
//	}
//	else
//		return 1;
//
//}
//
//int main()
//{
//	int n = 0;
//	printf("��������:>");
//	scanf("%d", &n);
//	int ret = Factorial(n);
//	printf("%d", ret);
//	return 0;
//}


//ģ��Strlen����
//int Strlen(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + Strlen(str + 1);
//}
//
//int main()
//{
//	char str[] = "abcdfe";
//	int len = Strlen(str);
//	printf("%d", len);
//	return 0;
//}


//�ַ�������
//����취(Ӧ���뵽���ǣ��ַ�����ʵ�����������Ƶģ���ȫ����ͨ���±꽻��������ʵ����Ҫ�Ĺ���)
//int main()
//{
//	char str[] = "abcdef";
//	int left = 0;
//	// int right=strlen(str)-1;
//	int right = sizeof(str) / sizeof(str[0]) - 2;//���������±꣬sizeof��strlen���������ǰ�߼���'\0',���߲����㣬��������
//	while (left < right)
//	{
//		char tmp = '0';
//		tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		right--;
//		left++;
//	}
//	printf("%s\n", str);
//	return 0;
//}

//�ú����ķ�ʽʵ��(�ǵݹ�)
//void ReverseString(char str[])
//{
//		int left = 0;
//	 int right=strlen(str)-1;//��������ں�����ֱ������ַ�������
//	 //sizeofֻ����㴫��ȥ����Ԫ�صĳ��ȣ�strlen����ʱ��ӵ�һ��Ԫ�ص�ַλ��һֱ����ֱ������\0
//	 //sizeof�������鴫������Ԫ�ص�ַ���������ʧЧ
//	//int right = sizeof(str) / sizeof(str[0]) - 2;//���������±꣬sizeof��strlen���������ǰ�߼���'\0',���߲����㣬��������
//	while (left < right)
//	{
//		char tmp = '0';
//		tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	char str[] = "abcdef";
//	ReverseString(str);
//	printf("%s", str);
//	return 0;
//}

//һ�������ķ�ʽ
//void ReverseString(char* str)
//{
//	char tmp = *str;//1.��a���浽��ʱ������
//	int len = strlen(str);
//	*str = *(str + len - 1);//2.��g�滻a
//	*(str + len - 1) = '\0';//3.ԭ����g�д�\0,����ݹ�
//	if (strlen(str + 1) > 2)
//		ReverseString(str + 1);//4.�ݹ�
//	*(str + len - 1) = tmp;//��ԭ����g��\0 ��aȡ��
//}
//int main()
//{
//	char str[] = "abcdef";
//	ReverseString(str);
//	printf("%s", str);
//	return 0;
//}

//�����ʱ�Ľ���취
//void ReverseString(char* str, int left, int right)
//{
//	char tmp = *(str+left);
//	*(str+left) = *(str + right);
//	*(str + right) = tmp;
//	left++;
//	right--;
//	if (left < right)//��һ���޶�������������Ҫѧ��
//	{
//		ReverseString(str, left, right);
//	}
//}


//����һ���е�Сbug�ĵط������ַ���Ϊż����ʱ�����м��Ԫ�ؽ��������Σ�(û�дﵽ������Ч��)
//void ReverseString(char str[], int left, int right)
//{
//	char tmp = str[left];
//	str[left] = str[right];
//	str[right] = tmp;
//	if (left < right)
//		ReverseString(str, left+1, right-1);
//}
 
//���İ汾
//void ReverseString(char str[], int left, int right)
//{
// if (left < right)
//	{
//		char tmp = str[left];
//		str[left] = str[right];
//		str[right] = tmp;
//		ReverseString(str, left+1, right-1);
//  }
//}

//int main()
//{
//	char str[] = "abcdefghjk";
//	int right = strlen(str)-1;
//	ReverseString(str,0,right);
//	printf("%s", str);
//	return 0;
//}

//����һ������ÿλ֮��
//�ǵݹ��д��
//int DigitSum(int n)
//{
//	int sum = 0;
//	while (n > 9)
//	{
//		sum = sum + n % 10;
//		n /= 10;
//	}
//	return sum+n;
//}

//�ݹ��д��
//int DigitSum(int n)
//{
//	if (n > 9)//��һ��������˳���ӡ���ֵ�ÿһλ
//		return  n % 10 + DigitSum(n / 10);
//	else
//		return n;//��һ����ֹ���뵥������
//}
//
//int main()
//{
//	int num = 0;
//	printf("������һ����:>");
//	scanf("%d", &num);
//	int ret = DigitSum(num);
//	printf("%d", ret);
//
//
//	return 0;
//}


//�ݹ�ʵ��n��k�η�
//��ʽ
//k=0->1
//k>0->n*Pow(n,k-1)
//k<0->1.0/Pow(n,-k)

//double Pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	else if (k > 0)
//		return n * Pow(n, k - 1);
//	else
//		return 1.0 / Pow(n, -k);
//}
//
//int main()
//{
//	int n, k;
//	n = k = 0;
//	printf("������n��k(�ÿո����):>");
//	scanf("%d %d", &n, &k);
//	double sum = Pow(n, k);
//	printf("%lf\n", sum);
//
//	return 0;
//}

//������������
//int main()
//{
//	char arr1[] = "hellow";
//	char arr2[] = "nihaoy";
//	int i = 0;
//	int len = strlen(arr1);
//	for (i = 0; i < len ; i++)
//	{
//		char tmp = '0';
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	printf("%s\n%s\n", arr1, arr2);
//	return 0;
//}
void Init(int* arr,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		*(arr + i) = 0;
	}
}

void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);//*(arr+i)
	}
}

Reverse(int* arr,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int tmp = 0;
		tmp = *arr;
		*arr = *(arr + sz - 1);
		*(arr + sz - 1) = tmp;
	}
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	printf("\n");
	Reverse(arr,sz);
	Print(arr, sz);//��ӡ�����ÿһ��Ԫ��
	printf("\n");
	Init(arr,sz);//��ʼ������Ԫ��ȫΪ0;
	printf("\n");

	Print(arr, sz);//��ӡ�����ÿһ��Ԫ��

	//int i = 0;
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	
	
	return 0;
}