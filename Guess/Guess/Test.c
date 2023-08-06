#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void menu()
{
	printf("*****************\n");
	printf("******1.play*****\n");
	printf("******0.exit*****\n");
	printf("*****************\n");
}

void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;
	while (1)
	{
		printf("猜数字：\n");
		scanf("%d", &guess);

		if (ret < guess)
			printf("猜大了\n");
		else if (ret > guess)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("程序已退出\n");
			break;
		default:
			printf("选择错误请1s后重新选择\n");
			Sleep(1000);
			system("cls");
		}
	} while (input);

}

int main()
{
	srand((unsigned int)time(NULL));

	test();

	return 0;
}