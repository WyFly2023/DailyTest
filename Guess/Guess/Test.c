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
		printf("�����֣�\n");
		scanf("%d", &guess);

		if (ret < guess)
			printf("�´���\n");
		else if (ret > guess)
			printf("��С��\n");
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
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
		printf("��ѡ��>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�������˳�\n");
			break;
		default:
			printf("ѡ�������1s������ѡ��\n");
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