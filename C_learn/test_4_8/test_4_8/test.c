#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//字符串相关
//int main()
//{
//	//'a',单引号括起来的是字符类型
//	//C语言中没有字符串的数据类型，但可以将字符串存入一个数组中
//	char arr[] = "asdfgh";//字符串的结尾以“\0”为结束标志也会占用一个空间 ,打印时会有用终止标志 //7
//	char arr2[] = {'a','b','c','d','e','f'};//没有以\0占位，占6个字符空间
//	//char arr2[] = { 'a','b','c','d','e','\0' };//没有以\0占位，占6个字符空间
//	printf("%s\n",arr);
//	printf("%s\n", arr2);
//	int len = strlen(arr);//strlen统计字符串长度的时侯，会以\0为分割，但不会计入长度
//	printf("%d\n",len);
//	printf("%d\n", strlen(arr2));
//	return 0;
//}


//转义字符(即转变字符的意思)
//int main()
//{
//	printf("abc\n");
//	printf("abcn\n");
//
//	printf("abc\0df\n");
//	//printf("abc0df\n");
//
//	return 0;
//}


//常见转义字符
//三字母词 如：??) --> ]  \   ??(  --> [ 一些古老的编译器会将这类符号解析成其他东西

//%d - 打印整形
//%c - 打印字符
//%s - 打印字符串
//%f - 打印浮点数（float） %lf - 打印double
//%zu - 答应sizeof的返回值
//int main()
//{	
//	printf("%c\n",'\'');//  \'让其可以和'''区分开
//	printf("%s\n", "\"");//  \"让其可以和"""区分开
//	printf("abc\\0df\n");//  \\的妙用
//	printf("c:\test\test.c\n");//打印路径时，\t这类字符会被理解为制表符
//	printf("c:\\test\\test.c\n");//如此才可以打印出带\td的地址
//	printf("\a");//系统蜂鸣一声
//	
//	
//	printf("%c\n",'\130');// \\  \ddd表示将ddd代表的八进制数字转化为十进制而后对应的ascii码组打印出来
//	printf("%c\n", '\x60');// \\ \xdd表示将dd代表的十六进制数字转化为十进制后对应的ascii码组打印出来
//	
//	//printf("%d\n", strlen("c:\test\628\test.c"));
//	int len = strlen("c:\test\628\test.c");
//	printf("len = %d\n", len);//  len = 14
//
//	printf("c:\test\628\test.c\n");
//	return 0;
//}



//选择语句和循环语句
//选择语句
//int main()
//{
//	int input = 0;
//	printf("加入比特\n");
//	printf("要好好学习吗(0/1)？\n");
//	scanf("%d",&input);
//	if (input == 1)
//	{
//		printf("好offer！\n");
//	}
//	else
//	{
//		printf("卖红薯\n");
//	}
//	return 0;
//}

//循环语句
//int main()
//{
//	int line = 0;
//	printf("加入比特持续学习");
//	while (line <= 20000)
//	{
//		printf("写代码中%d\n", line);
//		line++;
//	}
//	if (line >= 20000)
//	{
//		printf("恭喜，你已走上人生巅峰！");
//	}
//	else
//	{
//		printf("完蛋还要继续加油努力");
//	}
//
//	return 0;
//}

////讲解函数
//Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int x, y;
//	printf("请输入两个数用空格隔开：\n");
//	scanf("%d %d", &x, &y);
//	printf("sum = %d\n", Add(x, y));
//	return 0;
//}

//数组
int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义了一个数组   存放一组相同类型的数

	printf("%d\n",arr[8]);
	int i = 0;
	while ( i < 10 )
	{
		printf("%d ", arr[i]);
		i++;
	}
	return 0;
}