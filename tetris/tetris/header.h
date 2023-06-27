#pragma once
#include "interface.h"
#include <conio.h>
#include <time.h>
#include <string.h>

#define SWAP(type, x, y) do{ type t = x; x = y; y = t;} while(0)
#define NEXT 7		// 다음 나올 테트로미노의 정보를 저장할 보초
#define RESET 1	   // 1이면 모든 기록 초기화
#define LETTER_LIMIT 9		// 입력받는 아이디, 비번 최대 글자수

typedef struct {
	char id[20];
	char password[20];
	char onoff;		// 1: on  0: off
} Information;

typedef struct {
	char id[20];
	int time;		// 기록연월일 표시
	int score;
} Record;

typedef struct {
	COORD center;		// 중심조각의 좌표
	COORD block[3];		// 나머지 조각의 좌표
	int t_color;		// 테트로미노 색
} Tetromino;

typedef struct {
	char situation;			// 테트리스 판 해당 좌표의 상황 0: 빔, 1: 참
	int t_color;			// 테트리스 판 해당 좌표의 색
} Tetris;

typedef enum {
	EASY = 4, NORMAL = 16, HARD = 64
} Mode;

int my_gets(char buffer[], int limit);
void admin_page();
void mypage(Information* information);
Information login();
void signup();
int game(Mode mode);					// 점수를 반환하도록 변경함, 모드를 인수로 받도록 함
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
char is_overlap(Tetris grid[][12], Tetromino* tetp);		// 테트로미노가 고정된 자리와 겹쳐있는가 -> 게임이 끝났는지 판정
int add_record(Record *record, Mode mode);							// 기록 추가함수
void remove_record(const char id[]);									// 기록 삭제함수
void remove_account(Information* information);
void add_account(Information* information);
char search_id(Information* information);		// 아이디 찾기 0: 없음 1: 있음.