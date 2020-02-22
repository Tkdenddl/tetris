#include "header.h"

void game()
{
	int i, j;		// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int end = 0;
	int block_num = 6;				// 현재 내려가고 있는 테트로미노 번호 저장 변수
	Tetromino tetromino[7];			// 7개의 테트로미노  정보가 들어있는 배열
	Tetris grid[21][11];		// 테트리스 판 관리 배열

	system("cls");		// 화면 지우기
	box(0, 0, 21, 20);		// 테트리스 게임 판 그리기(일단 대충 이걸로..) 각 칸의 좌표는 (x * 2, y)

	init_tetromino(tetromino);		// 테트로미노 정보 만들기

	for (i = 1; i <= 20; i++)		// 테트리스 판 관리 배열 초기화
		for (j = 1; j <= 10; j++)
			grid[i][j].situation = 0;

	tetromino[block_num].center.X = 5;
	tetromino[block_num].center.Y = 5;

	while (end == 0) {
		while (!kbhit()) {		// 키보드 입력 감지할 때까지
			//	if(조각이 바닥에 닿으면)
			//		if(없어질 줄이 있으면)
			//			없애고 내림
			//			점수 추가
			//		깃발 올림
			//	if(깃발 올려져 있으면)
			//		새로운 조각 출현
			//		깃발 내림
			//	일정 시간마다 조각 내림.....
		}
		key = getch();
		switch (key) {
		case UP:
			erase_tetromino(&tetromino[block_num]);
			rotate_tetromino(&tetromino[block_num]);
			print_tetromino(&tetromino[block_num]);
			break;
		case DOWN:
			erase_tetromino(&tetromino[block_num]);
			down_tetromino(grid, &tetromino[block_num]);
			print_tetromino(&tetromino[block_num]);
			break;
		case RIGHT:
			erase_tetromino(&tetromino[block_num]);
			right_tetromino(grid, &tetromino[block_num]);
			print_tetromino(&tetromino[block_num]);
			break;
		case LEFT:
			erase_tetromino(&tetromino[block_num]);
			left_tetromino(grid, &tetromino[block_num]);
			print_tetromino(&tetromino[block_num]);
			break;
		case EXIT:		// e
			end = 1;
			break;
		default:
			break;
		}

	}

	return;
}