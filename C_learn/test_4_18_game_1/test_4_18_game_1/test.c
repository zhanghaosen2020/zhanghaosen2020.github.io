#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char ret = 0;//接收判断输赢的约定变量
	//存放棋子* #的数组
	char board[ROW][COL] = {0};
	//初始化棋盘函数
	InitBoard(board, ROW, COL);
	//打印棋盘函数
	DisplayBoard(board,ROW,COL);

	//下棋
	while (1)
	{
		PlayerMove(board,ROW,COL);
		//玩家下完之后就应该判断输赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board,ROW,COL);
		//也得判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局");
	}
	DisplayBoard(board, ROW, COL);
}

void menu()
{
	printf("**************************************\n");
	printf("************	1.play	  ************\n");
	printf("************	0.exit	  ************\n");
	printf("**************************************\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机数的生成起点


	do
	{ 
		menu();//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				game();//测试功能	printf("玩游戏\n");
				break;
			}
			case 0:
			{	
				printf("退出游戏\n");
				break; 
			}
			default:
			{	
				printf("输入错误\n");
				break;
			}
		}
	} while (input);

	return 0;
}