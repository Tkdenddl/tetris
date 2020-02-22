#pragma once
#include "interface.h"
#include <conio.h>

#define SWAP(type, x, y) do{ type t = x; x = y; y = t;} while(0)


typedef struct {
	COORD center;		// �߽������� ��ǥ
	COORD block[3];		// ������ ������ ��ǥ
	int t_color;		// ��Ʈ�ι̳� ��
} Tetromino;

typedef struct {
	char situation;			// ��Ʈ���� �� �ش� ��ǥ�� ��Ȳ 0: ��, 1: ��
} Tetris;



void game();
void init_tetromino(Tetromino* tetp);
void print_tetromino(Tetromino* tetp);
void rotate_tetromino(Tetromino* tetp);
void erase_tetromino(Tetromino* tetp);
int down_tetromino(Tetris grid[][11], Tetromino* tetp);
int right_tetromino(Tetris grid[][11], Tetromino* tetp);
int left_tetromino(Tetris grid[][11], Tetromino* tetp);