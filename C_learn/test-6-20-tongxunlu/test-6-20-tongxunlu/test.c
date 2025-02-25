#define _CRT_SECURE_NO_WARNINGS
/*
实现一个通讯录：人的信息，包括名字，年龄，性别，电话，地址
要求：存放100个人的信息，增删查改联系人，排序，显示联系人
test.c    测试功能
contact.c 通讯录相关实现
contact.h 通信录相关声明
*/
#include "contact.h"
enum Option
{
	EXIT,//0
	ADD,//1
	DEL,//2
	SEARCH,//3
	MODIFY,//4
	SHOW,//5
	SORT//6
	//默认是有值的，优化了代码
};
void menu()
{
	printf("*************************************\n");
	printf("******  1.add         2.del    ******\n");
	printf("******  3.search      4.modify ******\n");
	printf("******  5.show        6.sort   ******\n");
	printf("******  0.exit                 ******\n");
	printf("*************************************\n");


}
int main()
{
	int input = 0;

	Contact con;//通讯录
	//初始化通讯录
	InitContact(&con);//结构体传参，传址调用
	do
	{
		menu();//简易菜单
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}