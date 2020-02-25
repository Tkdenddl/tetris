#pragma once
#include "interface.h"
#include <conio.h>
#include <time.h>
#include <string.h>

#define SWAP(type, x, y) do{ type t = x; x = y; y = t;} while(0)
#define NEXT 7		// ���� ���� ��Ʈ�ι̳��� ������ ������ ����

typedef struct {
	char name[10];
	char id[20];
	char password[20];
} Information;

typedef struct {
	char id[20];
	int time;		// ��Ͽ����� ǥ��
	int score;
} RECORD;

typedef struct {
	COORD center;		// �߽������� ��ǥ
	COORD block[3];		// ������ ������ ��ǥ
	int t_color;		// ��Ʈ�ι̳� ��
} Tetromino;

typedef struct {
	char situation;			// ��Ʈ���� �� �ش� ��ǥ�� ��Ȳ 0: ��, 1: ��
	int t_color;			// ��Ʈ���� �� �ش� ��ǥ�� ��
} Tetris;

Information* login();
void signup();
int game();					// ������ ��ȯ�ϵ��� ������
void init_tetromino(Tetromino* tetp);
void print_tetromino(Tetromino* tetp);
void rotate_tetromino(Tetris grid[][12], Tetromino* tetp);
void erase_tetromino(Tetromino* tetp);
int down_tetromino(Tetris grid[][12], Tetromino* tetp);
int right_tetromino(Tetris grid[][12], Tetromino* tetp);
int left_tetromino(Tetris grid[][12], Tetromino* tetp);
void set_grid(Tetris grid[][12], Tetromino* tetp);
char check_grid(Tetris grid[][12]);		// ���ڻ��¸� üũ�ؼ� �ϼ��� ���� ������ �� ���� ���ְ� ����. ��ȯ���� ���� ���� ����
void draw_grid(Tetris grid[][12]);		// ������ ��Ʈ�ι̳�� �׸���
char is_overlap(Tetris grid[][12], Tetromino* tetp);		// ��Ʈ�ι̳밡 ������ �ڸ��� �����ִ°� -> ������ �������� ����