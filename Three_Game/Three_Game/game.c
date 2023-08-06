#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		//打印数据
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋：\n");

	while (1)
	{
		printf("请输入落子的坐标\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已占有，请重新输入：\n");
		}
		else
			printf("输入坐标有误，请重新输入：\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	//printf("电脑下棋:\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//判断棋盘是否满
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	//判断三行
	for(int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] 
		 && board[i][1] == board[i][2] 
		 && board[i][0] != ' ')
			return board[i][0];
	}
	//判断三列
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] 
		 && board[1][i] == board[2][i] 
		 && board[0][i] != ' ')
			return board[0][i];
	}
	//判断主对角线
	if (board[0][0] == board[1][1] 
	 && board[1][1] == board[2][2] 
	 && board[1][1] != ' ')
		return board[1][1];
	//判断副对角线
	if (board[0][2] == board[1][1] 
	 && board[1][1] == board[2][0] 
	 && board[1][1] != ' ')
		return board[0][0];

	//判断是否平局
	if (IsFull(board, row, col))
		return 'Q';
	return 'C';
}