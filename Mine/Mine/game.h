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

//初始化
void InitBoard(char board[ROWS][COLS], int row, int col,char set);
//展示棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);
//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

