#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EasyMode 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��ʼ��
void InitBoard(char board[ROWS][COLS], int row, int col,char set);
//չʾ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//������
void SetMine(char mine[ROWS][COLS], int row, int col);
//����
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

