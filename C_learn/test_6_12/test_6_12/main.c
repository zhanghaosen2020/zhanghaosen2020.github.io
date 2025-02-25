#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <assert.h>
#include <string.h>

//打印杨辉三角
//int main()
//{
//    int arr[10][10] = { 0 };//定义一个二维数组
//    //填充杨辉三角的内容
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
//    //打印三角形
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

//1、暴力左旋字符
//void left_round(char* s, int k, int len)
//{
//	int time = k % len;//用来求取进行几次大的反转，
//	int i = 0;
//	for (i = 0; i < time; i++)
//	{
//		char tmp = *s;
//		int j = 0;
//		for (j = 0; j < len - 1; j++)//每次大反转里边进行的变量的覆盖
//		{
//			*(s + j) = *(s + j + 1);
//		}
//		*(s + j) = tmp;//此时的j还未归为0
//	}
//}
////strlen是库函数，可以在函数里直接求完整的数组长度，sizeof才只能在主函数里求
//int main() 
//{
//	char str[] = "abcd";
//	int len = strlen(str);//字符串长度
//	int k = 0;
//	printf("请输入左旋位数:>");
//	scanf("%d", &k);
//	left_round(str, k, len);
//	printf("%s\n", str);
//
//	return 0;
//}

//2、三段字符逆序法
//#include<assert.h>
//#include<string.h>
////目的是倒序字符串
//void str_reverse(char* left, char* right)
//{
//	assert(left && right);//断言，避免指针为空
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
//	//翻转左边字段
//	int len = strlen(str);
//	k %= len;//这一步是为了防止越界
//	str_reverse(str, str + k - 1);
//	str_reverse(str+k, str + len-1);
//	str_reverse(str, str + len - 1);
//}
//
//int main() 
//{
//	char str[] = "abcdef";
//	int len = strlen(str);//字符串长度
//	int k = 0;
//	printf("请输入左旋位数:>");
//	scanf("%d", &k);
//	left_round(str, k);
//	printf("%s\n", str);
//
//	return 0;
//}


//杨氏矩阵的查找，并返回下标
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
//	return P;//标志未找到了
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	printf("请输入要查找的数字:>");
//	int num = 0;
//	scanf("%d", &num);
//	struct Point ret = find_num(arr, 3, 3,num);
//	printf("%d %d",ret.x,ret.y);
//	return 0;
//}

//杨氏矩阵查找并返回参数(方法二,传址调用而不用结构体)
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
//	return 0;//标志未找到了
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	printf("请输入要查找的数字:>");
//	int num = 0;
//	scanf("%d", &num);
//	int x = 3;
//	int y = 3;//这里使用传址调用的方法相比较结构体返回坐标更加的节省资源，问题是反复查找时，要多次置位x,y的坐标
//	int ret = find_num(arr, &x, &y, num);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//		printf("坐标为：%d,%d",x,y);
//	}
//	else
//	{
//		printf("未找到\n");
//	}
//	return 0;
//}


//判断arr2是否是arr1旋转得来的
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
//	//判断arr2是否是arr1旋转得来的
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

//方法二，借用库函数
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
	//判断arr2是否是arr1旋转得来的
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