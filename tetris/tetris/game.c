#include "header.h"

void game()
{
	int i, j;		// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int end = 0;
	Tetromino tetromino[7];			// 7개의 테트로미노  정보가 들어있는 배열
	Tetris tetris[20][10];		// 테트리스 판 관리 배열

	system("cls");		// 화면 지우기
	box(0, 0, 21, 20);		// 테트리스 게임 판 그리기(일단 대충 이걸로..) 각 칸의 좌표는 (x * 2, y)

	init_tetromino(tetromino);		// 테트로미노 정보 만들기

	for (i = 0; i < 20; i++)		// 테트리스 판 관리 배열 초기화
		for (j = 0; j < 10; j++)
			tetris[i][j].situation = 0;

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
			break;
		case DOWN:
			break;
		case RIGHT:
			break;
		case LEFT:
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