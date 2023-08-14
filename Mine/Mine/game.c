#include"game.h"

void InitBoard(char board[ROWS][COLS], int row, int col,char set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 1; i <= row; i++)
	{
		//打印分割行
		for (int j = 1; j <= col; j++)
		{
			printf("---");
			printf("|");
		}
		printf("\n");

		if (col == 1)
			printf("|");
		//打印数据
		for (int j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			printf("|");
		}
		printf("\n");
	}
	for (int i = 1; i <= row; i++)
	{
		printf("---");	
		printf("|");
	}
	printf("\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EasyMode;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row * col - EasyMode)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标被排查了，请重新输入坐标\n");
			}

			else if (mine[x][y] == '1')
			{
				DisplayBoard(mine, ROW, COL);
				printf("很遗憾，你被炸死了\n");
				break;
			}
			else
			{
				//不是雷，就统计x,y坐标周围有几个雷
				int ret = GetMineCount(mine, x, y);
				show[x][y] = ret + '0';
				system("cls");
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
	if (win == row * col - EasyMode)
	{
		DisplayBoard(mine, ROW, COL);
		printf("恭喜你，排雷成功\n");
	}
}

