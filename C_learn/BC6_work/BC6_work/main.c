#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//��һ����ҵ����ӡ��һ��С�ɻ�����printf��
//int main()
//{
//	printf("     **     \n");
//	printf("     **     \n");
//	printf("************\n");
//	printf("************\n");
//	printf("    *  *    \n");
//	printf("    *  *    \n");
//	return 0;
//}

//��һ����ҵ�����ѧ����Ϣ
//int main()
//{
//	printf("Name	Age    Gender\n");
//	printf("---------------------\n");
//	printf("Jack	18     man\n");
//
//	return 0;
//}

//��һ����ҵ��������Ϣ
//int main()
//{
//	printf("I lost my cellphone��\n");
//
//
//	return 0;
//}

//��һ����ҵ��������ʽ��ֵ
//int main()
//{
//	int a = 40, c = 212;
//	int sum = 0;
//	sum = (-8 + 22) * a - 10 + c / 2;
//	printf("%d\n", sum);
//	return 0;
//}


//������룬��ӡ�����ʲô��Ϊʲô����ͻ��'\0'����Ҫ�ԣ�
//int main()
//{
    //char arr1[] = "bit";
    //char arr2[] = { 'b', 'i', 't' };
    //char arr3[] = { 'b', 'i', 't', '\0' };
    //printf("%s\n", arr1);
    //printf("%s\n", arr2);
    //printf("%s\n", arr3);
    //printf("%d\n", strlen(arr1));
    //printf("%d\n", strlen(arr2));
    //printf("%d\n", strlen(arr3));
  
  //  int arr[10] = { 1 };
  //  char ch[11] = { "hello worl" };
  //  char ch1[]   = { "hello worl" };
  //  printf("ch = %s\n", ch);
  //  printf("ch1 = %s\n", ch1);

  //  /* int n = 10;
  //  int arr[n] = { 0 };  //������������� */
  //return 0;
//}

  //��ҵ,�Ƚ��������Ĵ�С
//int Max(int x, int y)
//{
//    if (x > y)
//        return x;
//    else
//        return y;
//}
//int main()
//{
//    int a = 0, b = 0;
//    scanf("%d %d", &a, &b);
//    printf("%d", Max(a, b));
//    return 0;
//}

//��ҵ
int Functiton(int x)
{
    if (x > -10000 && x < 10000)
    {
        if (x < 0)
            return 1;
        else if (x > 0)
            return -1;
        else
            return 0;
    }
    else
        printf("�����ֵ������Χ!\0");
   
}

int main()
{
    int a = 0;
    scanf("%d", &a);
    printf("%d", Functiton(a));

    return 0;
}

