#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ��
//���磺
//���룺1234����� 1 2 3 4
/*
void Print(unsigned int n)
{
	if (n > 9)
	{
		Print(n / 10);
		//n = n / 10;
		//Print(n);
	}
	printf("%u ",n%10);
}
int main()
{
	unsigned int num = 0;
	printf("������һ������:>");
	scanf("%u", &num);
	//while (num)//����1234 ���4 3 2 1������˳�����
	//{
	//	printf("%u ", num % 10);//%u��ָ��ӡ�޷�������
	//	num = num / 10;
	//}
	Print(num);//����һ��ר��ʵ�ֹ��ܵĴ�ӡ����
	return 0;
}
*/
#include<string.h>
//��д��������������ʱ���������ַ�������
//ģ��ʵ��strlen
// //�������ֶ��巽ʽ
// unsigned int MyStrlen(char str[])//��������д���������ʽ
/*
unsigned int MyStrlen(char* str)  //��������д��ָ�����ʽ
{
	int count = 0;
	while(*str != '\0')
	{
		count += 1;
		str += 1;
	}
	return count;
}
*/

//�õݹ�ķ�ʽ��ʵ����������(�ɲ�������ʱ����)
//unsigned int MyStrlen(char* str)
//{
//	if (*str != '\0')
//		return 1 + MyStrlen(str + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	//int len = (unsigned int)strlen("abc");//ע��strlen�ķ���ֵ��һ��size_t�޷�������ֵ����Ӧ�ַ�������
//	char arr[] = "abcdooo";
//	int len = MyStrlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//дһ��n�Ľ׳˺���������ʵ��

//int main()
//{	
//	//��������
//	int n = 0;
//	int sum = 1;
//	//����
//	printf("����������n:>");
//	scanf("%d", &n);
//
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	printf("sum = %d", sum);
//	return 0;
//}

//�����ú�������ʽ��дN�Ľ׳�
//factorial�׳˺���   n<=1 ret=0;n>1  ret = n * factorail(n-1)
//int Factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * Factorial(n - 1);
//	}
//}
//int main()
//{
//	//����
//	int n = 0;
//	printf("����������n:>");
//	scanf("%d", &n);
//
//	//�ݹ�ʵ��
//	int ret = Factorial(n);
//
//	//���
//	printf("%d! = %d\n", n, ret);
//	return 0;
//}

//���n��쳲�������
//쳲�����1 1 2 3 5 8 13 21 34 55...

//���˹�ʽ֮�� n!, Fabonacci(n)�õݹ鶼�ǳ�����(����ʱ���õķǳ���)

//�ݹ�(���ǺõĽⷨ)
//int Fibonacci(int n)//ʱ�临�ӶȺܸߣ����˴������ظ����㣩��n = 50��ʱ����ܾã�
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}

//���������⣨������ʱ�临�ӶȽ����˺ܶ࣬��ʱ������ȵݹ鷽��Ķࣩ
int Fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;

	while (n >= 3)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	//����
	int n = 0;
	printf("����������n:>");
	scanf("%d", &n);

	//����
	int ret = Fibonacci(n);

	//��ӡ
	printf("\nFabonacci(%d) = %d\n", n, ret);
}