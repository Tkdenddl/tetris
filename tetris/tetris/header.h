#pragma once
#include "interface.h"
#include <conio.h>

typedef struct {
	int t_color;		// ��Ʈ�ι̳� ��
} Tetromino;

typedef struct {
	char situation;			// ��Ʈ���� �� �ش� ��ǥ�� ��Ȳ 0: ��, 1: ��
} Tetris;



void game();
void init_tetromino(Tetromino** tetp);
