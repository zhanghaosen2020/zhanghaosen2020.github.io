#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <string.h>

//��ӡ�������
//int main()
//{
//    int arr[10][10] = { 0 };//����һ����ά����
//    //���������ǵ�����
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < 10; i++)
//    {
//        for (j = 0; j <= i; j++)
//        {
//            if (j == 0 || i == j )
//            {
//                arr[i][j] = 1;
//            }
//            if (i > 1 && j > 0)
//            {
//                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//            }
//        }       
//    }
//    //��ӡ������
//    for (i = 0; i < 10; i++)
//    {
//        for (j = 0; j <= i; j++)
//        {
//            printf("%4d", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//1�����������ַ�
//void left_round(char* s, int k, int len)
//{
//	int time = k % len;//������ȡ���м��δ�ķ�ת��
//	int i = 0;
//	for (i = 0; i < time; i++)
//	{
//		char tmp = *s;
//		int j = 0;
//		for (j = 0; j < len - 1; j++)//ÿ�δ�ת��߽��еı����ĸ���
//		{
//			*(s + j) = *(s + j + 1);
//		}
//		*(s + j) = tmp;//��ʱ��j��δ��Ϊ0
//	}
//}
////strlen�ǿ⺯���������ں�����ֱ�������������鳤�ȣ�sizeof��ֻ��������������
//int main() 
//{
//	char str[] = "abcd";
//	int len = strlen(str);//�ַ�������
//	int k = 0;
//	printf("����������λ��:>");
//	scanf("%d", &k);
//	left_round(str, k, len);
//	printf("%s\n", str);
//
//	return 0;
//}

//2�������ַ�����
//#include<assert.h>
//#include<string.h>
////Ŀ���ǵ����ַ���
//void str_reverse(char* left, char* right)
//{
//	assert(left && right);//���ԣ�����ָ��Ϊ��
//
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_round(char* str, int k)
//{
//	//��ת����ֶ�
//	int len = strlen(str);
//	k %= len;//��һ����Ϊ�˷�ֹԽ��
//	str_reverse(str, str + k - 1);
//	str_reverse(str+k, str + len-1);
//	str_reverse(str, str + len - 1);
//}
//
//int main() 
//{
//	char str[] = "abcdef";
//	int len = strlen(str);//�ַ�������
//	int k = 0;
//	printf("����������λ��:>");
//	scanf("%d", &k);
//	left_round(str, k);
//	printf("%s\n", str);
//
//	return 0;
//}


//���Ͼ���Ĳ��ң��������±�
//struct Point
//{
//	int x;
//	int y; 
//};
//struct Point find_num(int arr[3][3],int c,int r,int num)
//{
//	int x = 0;
//	int y = c - 1;
//	struct Point P = { .x = -1,.y = -1 };
//	while ((x <= r - 1) && (y >= 0))
//	{
//		if (num > arr[x][y])
//		{
//			x++;
//		}
//		else if (num < arr[x][y])
//		{
//			y--;
//		}
//		else
//		{
//			P.x = x;
//			P.y = y;
//			return P;
//		}
//	}
//	return P;//��־δ�ҵ���
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	printf("������Ҫ���ҵ�����:>");
//	int num = 0;
//	scanf("%d", &num);
//	struct Point ret = find_num(arr, 3, 3,num);
//	printf("%d %d",ret.x,ret.y);
//	return 0;
//}

//���Ͼ�����Ҳ����ز���(������,��ַ���ö����ýṹ��)
//int find_num(int arr[3][3], int* px, int *py, int num)
//{
//	int x = 0;
//	int y = *py - 1;
//	while ((x <= *px - 1) && (y >= 0))
//	{
//		if (num > arr[x][y])
//		{
//			x++;
//		}
//		else if (num < arr[x][y])
//		{
//			y--;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	*px = -1;
//	*py = -1;
//	return 0;//��־δ�ҵ���
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	printf("������Ҫ���ҵ�����:>");
//	int num = 0;
//	scanf("%d", &num);
//	int x = 3;
//	int y = 3;//����ʹ�ô�ַ���õķ�����ȽϽṹ�巵��������ӵĽ�ʡ��Դ�������Ƿ�������ʱ��Ҫ�����λx,y������
//	int ret = find_num(arr, &x, &y, num);
//	if (ret == 1)
//	{
//		printf("�ҵ���\n");
//		printf("����Ϊ��%d,%d",x,y);
//	}
//	else
//	{
//		printf("δ�ҵ�\n");
//	}
//	return 0;
//}


//�ж�arr2�Ƿ���arr1��ת������
//int is_left_round(char *arr1,char*arr2)
//{
//	int len = strlen(arr1);
//	int i = 0;
//	for (i = 0; i < len - 1; i++)
//	{
//		char tmp = arr1[0];
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			arr1[j] = arr1[j + 1];
//		}
//		arr1[j] = tmp;
//		if (strcmp(arr1, arr2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "cdefgab";
//	//�ж�arr2�Ƿ���arr1��ת������
//	int ret = is_left_round(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("YES");
//	}
//	else
//	{
//		printf("NO");
//	}
//	return 0;
//}

//�����������ÿ⺯��
int is_left_round(char* arr1, char*arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	strncat(arr1, arr1,len1);
	char* ret = strstr(arr1, arr2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[20] = "abcdefg";
	char arr2[] = "cdefgab";
	//�ж�arr2�Ƿ���arr1��ת������
	int ret = is_left_round(arr1, arr2);
	if (ret == 1)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}