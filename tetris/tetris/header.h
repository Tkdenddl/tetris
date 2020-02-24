#pragma once
#include "interface.h"
#include <conio.h>
#include <time.h>
#include <string.h>

#define SWAP(type, x, y) do{ type t = x; x = y; y = t;} while(0)
#define NEXT 7		// 다음 나올 테트로미노의 정보를 저장할 보초

typedef struct {
	char name[10];
	char id[20];
	char password[20];
	int easy_record;
	int normal_record;
	int hard_record;
} Information;

typedef struct {
	COORD center;		// 중심조각의 좌표
	COORD block[3];		// 나머지 조각의 좌표
	int t_color;		// 테트로미노 색
} Tetromino;

typedef struct {
	char situation;			// 테트리스 판 해당 좌표의 상황 0: 빔, 1: 참
	int t_color;			// 테트리스 판 해당 좌표의 색
} Tetris;

Information* login();
void signup();
void game();
void init_tetromino(Tetromino* tetp);
void print_tetromino(Tetromino* tetp);
void rotate_tetromino(Tetris grid[][12], Tetromino* tetp);
void erase_tetromino(Tetromino* tetp);
int down_tetromino(Tetris grid[][12], Tetromino* tetp);
int right_tetromino(Tetris grid[][12], Tetromino* tetp);
int left_tetromino(Tetris grid[][12], Tetromino* tetp);
void set_grid(Tetris grid[][12], Tetromino* tetp);
char check_grid(Tetris grid[][12]);		// 격자상태를 체크해서 완성된 줄이 있으면 그 줄을 없애고 내림. 반환값은 없앤 줄의 개수
void draw_grid(Tetris grid[][12]);		// 고정된 테트로미노들 그리기