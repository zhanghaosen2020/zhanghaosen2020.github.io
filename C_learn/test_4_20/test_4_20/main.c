#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>


////该函数可以依次打印每一位
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
//	printf("请输入数字:>");
//	scanf("%d",&num);
//	Print(num);
//	return 0;
//}

//计算阶乘
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
//	printf("输入数字:>");
//	scanf("%d", &n);
//	int ret = Factorial(n);
//	printf("%d", ret);
//	return 0;
//}


//模拟Strlen函数
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


//字符串逆序
//常规办法(应该想到的是，字符串其实就是数组类似的，完全可以通过下标交换操作，实现想要的功能)
//int main()
//{
//	char str[] = "abcdef";
//	int left = 0;
//	// int right=strlen(str)-1;
//	int right = sizeof(str) / sizeof(str[0]) - 2;//这里求右下标，sizeof和strlen的区别就是前者计算'\0',后者不计算，做好区分
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

//用函数的方式实现(非递归)
//void ReverseString(char str[])
//{
//		int left = 0;
//	 int right=strlen(str)-1;//这里可以在函数中直接求出字符串长度
//	 //sizeof只会计算传进去的首元素的长度，strlen计算时会从第一个元素地址位置一直计算直到遇见\0
//	 //sizeof由于数组传的是首元素地址，因而方法失效
//	//int right = sizeof(str) / sizeof(str[0]) - 2;//这里求右下标，sizeof和strlen的区别就是前者计算'\0',后者不计算，做好区分
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

//一个参数的方式
//void ReverseString(char* str)
//{
//	char tmp = *str;//1.将a保存到零时变量中
//	int len = strlen(str);
//	*str = *(str + len - 1);//2.用g替换a
//	*(str + len - 1) = '\0';//3.原来的g中存\0,方便递归
//	if (strlen(str + 1) > 2)
//		ReverseString(str + 1);//4.递归
//	*(str + len - 1) = tmp;//将原来的g的\0 用a取代
//}
//int main()
//{
//	char str[] = "abcdef";
//	ReverseString(str);
//	printf("%s", str);
//	return 0;
//}

//多参数时的解决办法
//void ReverseString(char* str, int left, int right)
//{
//	char tmp = *(str+left);
//	*(str+left) = *(str + right);
//	*(str + right) = tmp;
//	left++;
//	right--;
//	if (left < right)//这一步限定条件的设置需要学会
//	{
//		ReverseString(str, left, right);
//	}
//}


//这是一个有点小bug的地方，当字符串为偶数个时，最中间的元素交换了两次，(没有达到交换的效果)
//void ReverseString(char str[], int left, int right)
//{
//	char tmp = str[left];
//	str[left] = str[right];
//	str[right] = tmp;
//	if (left < right)
//		ReverseString(str, left+1, right-1);
//}
 
//更改版本
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

//计算一个数的每位之和
//非递归的写法
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

//递归的写法
//int DigitSum(int n)
//{
//	if (n > 9)//这一步来自于顺序打印数字的每一位
//		return  n % 10 + DigitSum(n / 10);
//	else
//		return n;//这一步防止输入单个数字
//}
//
//int main()
//{
//	int num = 0;
//	printf("请输入一个数:>");
//	scanf("%d", &num);
//	int ret = DigitSum(num);
//	printf("%d", ret);
//
//
//	return 0;
//}


//递归实现n的k次方
//公式
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
//	printf("请输入n和k(用空格隔开):>");
//	scanf("%d %d", &n, &k);
//	double sum = Pow(n, k);
//	printf("%lf\n", sum);
//
//	return 0;
//}

//交换数组类容
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
	Print(arr, sz);//打印数组的每一个元素
	printf("\n");
	Init(arr,sz);//初始化数组元素全为0;
	printf("\n");

	Print(arr, sz);//打印数组的每一个元素

	//int i = 0;
	//for (i = 0; i < sz; i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	
	
	return 0;
}