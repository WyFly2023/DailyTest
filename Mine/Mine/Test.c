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
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//设置雷
	SetMine(mine, ROW, COL);
	//展示界面
	DisplayBoard(show, ROW, COL);
	//排查雷
	FindMine(mine,show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default :
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}