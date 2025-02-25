#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

//int main()
//{
//	//FILE* pf = fopen("test.txt","r");//相对路径，打开的是当前工程文件夹下的文件
//	FILE* pf = fopen("C:\\Users\\Zhang\\Desktop\\test.txt", "r");//绝对路径的形式来打开
//	//双斜杠是转义单个斜杠
//	
//	//若文件打开失败返回NULL所以要判断
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//写文件
//
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;//让其失忆
//	return 0;
//}

//int main()
//{
	/*FILE* pf = fopen("test.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}*/
	//写文件
	//fputc('a', pf);
	//int i = 'a';
	//for (i = 'a'; i < 'z'; i++)
	//{
	//	fputc(i, pf);//一次写一个字符，多次写入
	//}


	//FILE* pf = fopen("test.txt", "r");
	//if (pf == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 1;
	//}
	////读文件
	////printf("%c\n", fgetc(pf));//顺序读，指针会自动往下一个位置移动，读error返回EOF
	//int ch = 0;
	//while ((ch = fgetc(pf))!= EOF)
	//{
	//	printf("%c ", ch);
	//}
	 
	//写一行数据
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));//这里的优点是，即拿到，又打印
//		perror("fopen");//理解为打印错误信息，字符串是提示位置
//		return 1;
//	}
//
//	fputs("hello bit",pf);//写文件的时候，会把文件的内容清空再写数据（模式改为a追加）
//	//读一行数据
//	char arr[20];
//	fgets(arr,10,pf);//最多读num-1个数据，因为数组末尾加了一个 \0 
//	printf("%s\n", arr);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");//以写的方式打开文件
//	if (pf == NULL)//检查是否创建成功
//	{
//		perror(fopen);
//		return 1;
//	}
//	//fputc('a',pf);//写入一个字符a
//	int i = 'a';
//	for (i = 'a'; i < 'z'; i++)
//	{
//		fputc(i , pf);
//	}
//
//	fclose(pf);//关闭指针
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//以写的方式打开文件
//	if (pf == NULL)//检查是否创建成功
//	{
//		perror(fopen);
//		return 1;
//	}
//	//printf("%c ", fgetc(pf));//pf指针会自动加一
//	//printf("%c ", fgetc(pf));
//	//printf("%c ", fgetc(pf));
//	//printf("%c ", fgetc(pf));
//	int c = 0;
//	while ((c = fgetc(pf)) != EOF)//读取每一个字符的方法
//	{
//		printf("%c ", c);
//	}
//
//
//	fclose(pf);//关闭指针
//	pf = NULL;
//
//	return 0;
//}

//读文件中一个字符串的方法
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");//以写的方式打开文件
//	if (pf == NULL)//检查是否创建成功
//	{
//		perror(fopen);
//		return 1;
//	}
//	char str[28] = {0};//定义的空间要比读取的空间大
//	fgets(str, 28, pf);//若读取失败，会返回一个空指针。大小-1，加了'\0'
//	printf("%s", str);
//
//	fclose(pf);//关闭指针
//	pf = NULL;
//
//	return 0;
//}

//往文件中写入字符串
//int main()
//{
//	FILE* pf = fopen("test.txt", "a");//以写的方式打开文件
//	if (pf == NULL)//检查是否创建成功
//	{
//		perror(fopen);
//		return 1;
//	}
//
//	fputs(" hello , haosen", pf);
//
//	fclose(pf);//关闭指针
//	pf = NULL;
//
//	return 0;
//}


//fprintf的用法
//struct Info
//{
//	char name[30];
//	int age;
//	char sex[20];
//};
//int main()
//{
//	struct Info stu = {"zhs",24,"boy"};
//	//开文件指针
//	FILE* pf = fopen("test.txt", "w");//以写的方式打开文件
//	if (pf == NULL)//检查是否创建成功
//	{
//		perror("fopen");//这里参数是一个字符串
//		return 1;
//	}
//	//操作文件
//	fprintf(pf, "%s %d %s", stu.name, stu.age, stu.sex);//pf是把数据写入文件
//	fprintf(stdout, "%s %d %s", stu.name, stu.age, stu.sex);//stdout是把数据打印到屏幕
//
//	fclose(pf);//关闭指针
//	pf = NULL;
//
//	return 0;
//}


//二进制的读和写

//struct Info
//{
//	char name[30];
//	int age;
//	char sex[20];
//};

//读的版本
//int main()
//{
//	struct Info stu = { "zhanghaosen",50,"nan" };
//	//我想把张三的信息以二进制的形式写道文件中
//	//打开文件
//	FILE* pf = fopen("test.txt", "wb");
//	
//	//判断是否打开成功
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//二进制的方式写
//	fwrite(&stu, sizeof(struct Info), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//读的版本
//int main()
//{
//	struct Info stu = { 0 };
//	//我想把张三的信息以二进制的形式读文件中
//	//打开文件
//	FILE* pf = fopen("test.txt", "rb");
//	
//	//判断是否打开成功
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//二进制的方式的读
//	fread(&stu, sizeof(struct Info), 1,  pf);
//	printf("%s %d %s", stu.name, stu.age, stu.sex);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct Info stu = { "zhanghaosen",23,"nan" };
//	struct Info tmp = { 0 };
//	char buff[100] = {0};
//	//这个函数的本质是把结构体中的内容按照指定格式合并成一个字符串，存放到数组buff中
//	//把stu之中的格式化数据转化成字符串放到buff之中
//	sprintf(buff, "%s %s %d", stu.name, stu.sex,stu.age);//这里相对应的输出格式一定不能错
//	//"zhanghaosen nan 23"
//	printf("字符串：%s\n", buff);//把一个格式化数据转换成字符串
//
//	sscanf(buff,"%s %s %d", tmp.name, tmp.sex, &(tmp.age));
//	printf("格式化：%s %s %d\n", tmp.name, tmp.sex, tmp.age);
//	//从字符串buff中获取一个格式化数据到tmp之中
//	return 0;
//}

int main()
{
	FILE* pf = fopen("test.txt", "r");//以写的方式打开文件
	if (pf == NULL)//检查是否创建成功
	{
		perror(fopen);
		return 1;
	}
	//读文件
	//定位文件指针
	fseek(pf, 3, SEEK_SET);
	int ch = fgetc(pf);
	printf("%c", ch);

	fclose(pf);//关闭指针
	pf = NULL;

	return 0;
}