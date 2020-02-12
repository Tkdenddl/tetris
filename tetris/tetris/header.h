#pragma once
#include "interface.h"
#include <conio.h>

typedef struct {
	int t_color;		// 테트로미노 색
} Tetromino;

typedef struct {
	char situation;			// 테트리스 판 해당 좌표의 상황 0: 빔, 1: 참
} Tetris;



void game();
void init_tetromino(Tetromino** tetp);
