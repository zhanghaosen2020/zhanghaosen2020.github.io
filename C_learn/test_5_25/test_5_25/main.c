#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
//模拟实现strlen函数
//int my_strlen(const char* p)
//{
//	int count = 0;
//	assert(p != NULL);//防止传递过来的地址是空指针
//	while (*p++)
//	{
//		count++;
//	}
//	return count;
//}
//
////这里模拟实现了strcpy函数
//void my_strcpy(char* dst, const char* res)
//{
//	assert(res != NULL);
//	while (*res)
//	{
//		*dst++ = *res++;
//	}
//}
//
//int main()
//{
//	char arr[100] = "i am ironman!";
//	char arr1[100] = "";
//	int len = my_strlen(arr);
//	my_strcpy(arr1, arr);
//	printf("%s长度为 = %d\n",arr,len);
//	printf("%s", arr1);
//	return 0;
//}

//调整奇数偶数顺序
//使得奇数全部位于偶数之前
void move_odd_even(int arr[], int sz)
{
	int left = 0;
	int right = sz;
	while (left < right)
	{
		//从左往右寻找偶数

		//下边寻找奇偶数的方式，如若输入的数字全部为奇数或者偶数，程序会跑飞的，还需要限定条件
		while ((arr[left] % 2 == 1)&&(left<right))//当进入了循环说明数字为奇数，然后left++再次判断是否为奇数，如若不是，left下标就是偶数
		{							//和下边找出来的奇数进行交换，达到目的
			left++;
		}
		//从右往左寻找奇数
		while ((arr[right] % 2 == 0)&&(left<right))
		{
			right--;
		}
		//交换
		if (left < right)
		{
			int tmp = 0;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;

			left++;//跳过一个元素
			right--;
		}
	}
}
int main()
{
	//输入
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		scanf("%d", arr + i);//或者&arr[i]
	}
	
	//调整
	move_odd_even(arr,sz-1);
	//输出
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}