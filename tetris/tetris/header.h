#pragma once
#include "interface.h"
#include <conio.h>
#include <time.h>
#include <string.h>

#define SWAP(type, x, y) do{ type t = x; x = y; y = t;} while(0)
#define NEXT 7		// ���� ���� ��Ʈ�ι̳��� ������ ������ ����
#define RESET 1	   // 1�̸� ��� ��� �ʱ�ȭ
#define LETTER_LIMIT 9		// �Է¹޴� ���̵�, ��� �ִ� ���ڼ�

typedef struct {
	char id[20];
	char password[20];
	char onoff;		// 1: on  0: off
} Information;

typedef struct {
	char id[20];
	int time;		// ��Ͽ����� ǥ��
	int score;
} Record;

typedef struct {
	COORD center;		// �߽������� ��ǥ
	COORD block[3];		// ������ ������ ��ǥ
	int t_color;		// ��Ʈ�ι̳� ��
} Tetromino;

typedef struct {
	char situation;			// ��Ʈ���� �� �ش� ��ǥ�� ��Ȳ 0: ��, 1: ��
	int t_color;			// ��Ʈ���� �� �ش� ��ǥ�� ��
} Tetris;

typedef enum {
	EASY = 4, NORMAL = 16, HARD = 64
} Mode;

int my_gets(char buffer[], int limit);
void admin_page();
void mypage(Information* information);
Information login();
void signup();
int game(Mode mode);					// ������ ��ȯ�ϵ��� ������, ��带 �μ��� �޵��� ��
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
int add_record(Record *record, Mode mode);							// ��� �߰��Լ�
void remove_record(const char id[]);									// ��� �����Լ�
void remove_account(Information* information);
void add_account(Information* information);
char search_id(Information* information);		// ���̵� ã�� 0: ���� 1: ����.