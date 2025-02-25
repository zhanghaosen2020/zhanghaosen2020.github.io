#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//分支if-else与switch  和  循环语句while   for   do while
//int main()
//{
//	//if-else语句注意，默认下面只执行一条语句若要执行多条语句，需要{}框起来
//	//养成规范的代码书写格式
////下面这段代码不会有任何的执行结果，else只和最近的if匹配 若加{}更加容易阅读
////    int a = 0;
////    int b = 2;
////    if (a == 1)
////    {
////        if (b == 2)
////            printf("hehe\n");
////        else
////            printf("haha\n");
////    }
////
//////1、变量的命名(有意义、规范)
////    char frist_name[20];
////    char FristName[20];
//////2、空格、空行、换行
////    int a = 10;// = 两边有空格
//
//
//	// 练习 2.1.3
//	//int i = 1;
//	//while (i <= 100)
//	//{
//	//	if (0 != (i % 2))
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//	i++;
//	//}
//
//
//	//switch用于多多分支语句
//	int day = 0;
//	scanf("%d", &day);
//
///*	switch (day)//switch中要放整形变量(代表各种情况)，这个整形变量之决定case的入口，下面的case也会执行
//	{
//	case 1://case后必须是整型常量表达式 1，2，3等
//		printf("星期1\n");
//		break;
//	case 2://放个字符也可以，因为字符本质上是一个ascii码值为整形常量
//		printf("星期2\n");
//		break;
//	case 3:
//		printf("星期3\n");
//		break;
//	case 4:
//		printf("星期4\n");
//		break;
//	case 5:
//		printf("星期5\n");
//		break;
//	case 6:
//		printf("星期6\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//	}
//*/
//
//	//现在需求变了，输入1~5，weekday6~7weekend
//	switch (day)//简化了代码，break按逻辑要求使用更加方便
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;//建议加上，逻辑上可以不用
//	default:
//		printf("选择错误！");
//		break;
//	}
//	return 0;
//}


//循环语句
//int main()
//{
//	//1.while循环 //continue 的作用是跳过本次循环后边的代码，直接去判断进行下一次循环的判断
//	//打印1~10
//	int i = 1;
//	while (i <= 10)
//	{
//		if (5 == i)
//			break;//这两句话的意思是当i==5的时候，跳出循环，打印了1~4
//				//break跳出整个语句
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

int main()
{
	//int ch = 0;
	//ch = getchar();//getchar()函数得到的是键盘敲入的ascii码值，返回值是int类型的，可以用打印函数打印出来
	//printf("%c\n", ch);//%c打印出ch数值对应的字符(ascii)

	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	putchar(ch);//输入一个字符按一个回车，输入缓冲区里边有两个字符，getchar一次只拿一个，a != EOF putchar读一个再
	//	//来一次循环读 \n ,才进入下一次按字符加回车这个循环
	//}


	//举个例子(输入缓冲区中的\n、空格)
	//假设密码是一个字符串
	char password[20] = { 0 };
	printf("请输入密码:>");
	scanf("%s", password);//数组名本身就是一个地址，因此这里不用取地址符

	//getchar();//此处读取了 \n   简单的清理了一部分缓存
	int ch = 0;
	while ((ch = getchar()) != '\n')//清理一串缓存
	{
		;
	}


	printf("请确认密码(Y/N):>");
	int ret = getchar();
	if ('Y' == ret)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}



	return 0;
}