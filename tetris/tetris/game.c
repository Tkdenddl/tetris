#include "header.h"

void game()
{
	int i, j;		// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int run = 1;
	int block_num = 6;				// 현재 내려가고 있는 테트로미노 번호 저장 변수
	Tetromino tetromino[7];			// 7개의 테트로미노  정보가 들어있는 배열
	Tetris grid[22][12];		// 테트리스 판 관리 배열
	clock_t start, end;
	char timer = 0;		// 타이머 on:1 off:0

	srand((unsigned)time(NULL));	// 난수 시드값 초기화

	system("cls");		// 화면 지우기
	box(0, 0, 21, 20);		// 테트리스 게임 판 그리기(일단 대충 이걸로..) 각 칸의 좌표는 (x * 2, y)

	init_tetromino(tetromino);		// 테트로미노 정보 만들기

	for (i = 1; i <= 20; i++)		// 테트리스 판 관리 배열 초기화
	{
		for (j = 1; j <= 10; j++) {
			grid[i][j].situation = 0;
			grid[i][j].t_color = 15;
		}
		grid[i][0].situation = 1;		// 테트리스 옆면 설정
		grid[i][11].situation = 1;
	}
	for (j = 1; j <= 10; j++)		// 테트리스 바닥판 설정
		grid[i][j].situation = 1;

	tetromino[block_num].center.X = 5;
	tetromino[block_num].center.Y = 3;

	while (run) {
		while (!kbhit()) {		// 키보드 입력 감지할 때까지
			if (timer)
			{
				if (end - start >= DELAY)
				{
					erase_tetromino(&tetromino[block_num]);
					if (down_tetromino(grid, &tetromino[block_num]) == 0)		// 테트로미노가 바닥에 닿았으면
					{
						print_tetromino(&tetromino[block_num]);
						set_grid(grid, &tetromino[block_num]);
						check_grid(grid);

						block_num = rand() % 7;			// 새로운 테트로미노(원래는 먼저 정해놓아야 함, 지금은 임시로)
						tetromino[block_num].center.X = 5;
						tetromino[block_num].center.Y = 3;
					}
					print_tetromino(&tetromino[block_num]);
					timer = 0;		// 타이머 초기화
				}
			}
			else
			{
				timer = 1;
				start = clock();
			}
			end = clock();
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
			rotate_tetromino(grid, &tetromino[block_num]);
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
			run = 0;
			break;
		default:
			break;
		}

	}

	return;
}