#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char ret = 0;//�����ж���Ӯ��Լ������
	//�������* #������
	char board[ROW][COL] = {0};
	//��ʼ�����̺���
	InitBoard(board, ROW, COL);
	//��ӡ���̺���
	DisplayBoard(board,ROW,COL);

	//����
	while (1)
	{
		PlayerMove(board,ROW,COL);
		//�������֮���Ӧ���ж���Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board,ROW,COL);
		//Ҳ���ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��");
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
	srand((unsigned int)time(NULL));//������������������


	do
	{ 
		menu();//��ӡ�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				game();//���Թ���	printf("����Ϸ\n");
				break;
			}
			case 0:
			{	
				printf("�˳���Ϸ\n");
				break; 
			}
			default:
			{	
				printf("�������\n");
				break;
			}
		}
	} while (input);

	return 0;
}