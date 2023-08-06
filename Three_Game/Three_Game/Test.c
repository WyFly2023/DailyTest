#include"game.h"
void menu()
{
	printf("***********************\n");
	printf("******* 1.play ********\n");
	printf("******* 0.exit ********\n");
	printf("***********************\n");
}

void game()
{
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		system("cls");
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
		printf("玩家赢\n");

	else if (ret == '#')
		printf("电脑赢\n");

	else
		printf("平局\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);
	return 0;
}