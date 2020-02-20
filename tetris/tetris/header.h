#pragma once
#include "interface.h"
#include <conio.h>

typedef struct {
	COORD center;		// 중심조각의 좌표
	COORD block[3];		// 나머지 조각의 좌표
	int t_color;		// 테트로미노 색
} Tetromino;

typedef struct {
	char situation;			// 테트리스 판 해당 좌표의 상황 0: 빔, 1: 참
} Tetris;



void game();
void init_tetromino(Tetromino* tetp);
void print_tetromino(Tetromino* tetp);
