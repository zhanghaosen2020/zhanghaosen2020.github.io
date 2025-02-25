#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)//这一步是将棋子全部初始化为空格(占位)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//这个代码比较挫，ROW COL一旦发生改变就不行了
//版本1
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//打印分割信息
//		if (i < row - 1)		// 过滤一下,最后一行不打印
//		printf("---|---|---\n");
//	}
//}

//版本2
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印数据
	//	printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//打印分割信息
		//if (i < row - 1)		// 过滤一下,最后一行不打印
		//	printf("---|---|---\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");//这两步是把 ---|  拆分为 ---  |  让后边 | 可以按需求过滤
			}
			printf("\n");
		}
	}
}

//玩家移动
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("玩家下棋\n");

	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		if (((x >= 1) && (x <= row)) && ((y >= 1) && (y <= col)))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*' ;
				break;
			}
			else
			{
				printf("坐标被占用，不能下棋，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重输入\n");
		}
	}
}

//电脑下棋  (让电脑不容易输)
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");

	int x = 0;
	int y = 0;

	//生成随机值

	while (1)
	{
		x = rand() % row;//0-2
		y = rand() % col;//0-2
		if (board[x][y] == ' ')
			{
				board[x][y] = '#';//我这里有个小错误  ''里边只能放一个字符，由于按空格的习惯，让其填充了空格而不自知
				break;
			}
	}
}

//1-满  0-不满
int IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)//可以用循环嵌套，写的更加不挫
{
	//行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//列
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//...到这儿没人赢（判断平局）没人赢但棋盘满
	if (IsFull(board, row, col))
	{
		return 'Q';
	}

	//游戏继续
	return 'C';
}
