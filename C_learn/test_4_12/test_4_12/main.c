#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

//1.计算n的阶乘

//int main()
//{
//	int n = 0;
//	printf("请输入n:>");
//	scanf("%d", &n);
//	int sum = 1;
//	int i = 0;//控制外部for循环的变量
//	int j = n;//在循环中每次减少1，即n*(n-1)*(n-2)....*(1)
//	//
//	
///*	
//for (i = 1; i <= n; i++)
//	{
//		sum *= j;
//		j--;
//		if (0 == j)
//			break;//乘到1时跳出循环
//	}
//*/
//	for (i = 1; i <= n; i++)
//	{
//		sum = sum * i;
//
//	}
//	printf("\nsum = %d", sum);
//	return 0;
//}


//2.计算 1!+2!+3!+……+10!

//int main()
//{
//	int sum = 1;
//	int i = 0;
//	int total = 0;//共计
//	
//	for (i = 1; i <= 10; i++)
//	{
//		sum = sum * i;
//		total = total + sum ;
//	}
//	printf("%d", total);
//
//	return 0;
//}

// 3. 在一个有序数组中查找具体的某个数字n。（讲解二分查找）
//int main()
//{
//	//先用遍历的方法实现
//	int arr[] = {0,1,2,3,4,5,6,6,9,120};
//	int i = 0;
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);//用这样的方式来计算出数组的长度
//	printf("请输入要查找的数字:>");
//	scanf("%d", &k);
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] == k)
//		{
//			printf("下标为:%d\n", i);
//			break;//找到之后就跳出循环，如果没有这一句话，循环就会继续执行,打印出每一个为输入的下标志
//		}
//	}
//	if (sz == i)//上边遍历了整个数组，都未找到指定的数据，此时下标变为sz，说明未查找到该数据
//		printf("未查找到该数字");	
//	return 0;
//}

//下面用二分法来实现
/*
int main()
{
	//int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int arr[] = { 0,4,6,9,10,22,77,88,99,100 };
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组长度
	int left = 0;
	int right = sz - 1;//右下标
	int k = 0;
	printf("请输入要查找的数字:>");
	scanf("%d", &k);

	int i = 0;//控制循环变量
	while (left <= right)//这个时候说明中间还有元素，方可继续二分，跳出循环说明
	{	
		int mid = (left + right) / 2; //不要放在了循环外边
		//为了防止left + right越界，可以有下面的操作
		//mid = left + (right  - left) / 2; //避免了溢出
		if (arr[mid] < k)
		{
			left = mid + 1;//mid对应的不对，因而左边为mid+1
			//mid = (left + right) / 2;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
			//mid = (left + right) / 2;
		}
		else
		{
			printf("找到了，下标为:%d", mid);
			break;
		}	
	}
	if (left > right)//
	{
		printf("找不到了");
	}	
	return 0;
}
*/

//4. 编写代码，演示多个字符从两端移动，向中间汇聚。
//int main()
//{
//	char arr1[] = "welcome to bit!!!!";
//	char arr2[] = "##################";
//	int i = 0, j = 0;//两数组下标及循环控制变量
//	int sz = sizeof(arr1) / sizeof(arr1[0]);//这里可能用strlen()函数可能会好一些，因为这个函数不会将\0统计进去，后面编程内容更加清晰
//	for (i = 0; i < (sz - 1) / 2; i++)
//	{
//		arr2[i] = arr1[i];
//		arr2[sz - 2 - i] = arr1[sz - 2 - i];//减去2是应为字符串类型的数组，会占用一个空间存'\0'
//		printf("%s\n", arr2);
//	}
//	return 0;
//}
//下面是对上边的优化
/*
int main()
{
	char arr1[] = "welcome to bit!!!!";
	char arr2[] = "##################";
	int i = 0, j = 0;//两数组下标及循环控制变量
	//int sz = sizeof(arr1) / sizeof(arr1[0]);//这里可能用strlen()函数可能会好一些，因为这个函数不会将\0统计进去，后面编程内容更加清晰
	int sz = strlen(arr1);
	for (i = 0; i < sz / 2; i++)
	{
		arr2[i] = arr1[i];
		arr2[sz - 1 - i] = arr1[sz - 1 - i];//减去2是应为字符串类型的数组，会占用一个空间存'\0'
		printf("%s\n", arr2);
		Sleep(500);//休眠半秒，该函数由Windows.h提供
		//清理屏幕
		system("cls");//system()是一个系统函数，由stdlib.h提供
	}
	printf("%s\n", arr2);
	return 0;
}
*/

//5. 编写代码实现，模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，
//  如果密码正确则提示登录成，如果三次均输入错误，则退出程序。)
/*
#include<string.h>
int main()
{
	char pwd[] = "zhanghaosen123";
	char pwd1[15];
	int i = 0;
	printf("请输入密码:>");
	
	for (i = 0; i < 3; i++)
	{
		scanf("%s", pwd1);//这个地方不需要取地址，因为数组名本来就是地址
		//if (pwd == pwd1)// C语言中不能用 == 来比较字符串是否相等
		int t = strcmp(pwd, pwd1);
		if (strcmp(pwd , pwd1) == 0) 
		{
			printf("密码正确登陆成功！");
			break;
		}
		else
		{
			printf("密码错误，请重新输入:>");

		}

	}
	return 0;
}
*/

//猜数字小游戏
//电脑产生一个随机数(1~100)，告诉猜大了，猜小了，直到猜对（结束）

void menu()
{
	printf("******************************\n");
	printf("*********** 1.play ***********\n");
	printf("*********** 0.exit ***********\n");
	printf("******************************\n");
}

void game()
{	
	int guess = 0;
	//1.生成随机数
	//RAND_MAX(32767);
	//time()函数返回值为time_t,参数是一个指针（这里传了一个空指针）还用到了强制类型转换为srand()需要的无符号整形
	//srand((unsigned int)time(NULL));//Sets a random starting point;void srand(unsigned int seed);,seed随机，其生成的rand便随机，给个时间戳
	//该函数返回一个整形的随机值，0~RAND_MAX，The rand function returns a pseudorandom integer in the range 0 to RAND_MAX
	
	int ret = rand() % 100 + 1;//给他模100，余数为0-99，再加一就是需要的1-100
	//printf("%d\n", ret);//调试用

	//2.猜数字
	while (1)
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");

		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你猜对了\n");
			break;
		}
	}	
}
int main()
{
	srand((unsigned int)time(NULL));//整个工程只需要设置一次就好
	//首先需要打印菜单
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				//printf("玩游戏\n");
				game();//这里是猜数字游戏的逻辑
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入:>\n");
				break;
		}			
	}
	while (input);
	return 0;
}