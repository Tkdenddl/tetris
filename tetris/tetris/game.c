#include "header.h"

int game(MODE mode)
{
	int i, j;		// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int run = 1;
	
	Tetromino tetromino[8];			// 7개의 테트로미노  정보가 들어있는 배열
	Tetris grid[22][12];		// 테트리스 판 관리 배열
	clock_t start, end;
	char timer = 0;		// 타이머 on:1 off:0
	short delay = 1000;		// 테트로미노가 떨어지는 간격: 밀리초
	int score = 0;		// 점수: 1줄 -> 줄당 100, 2줄 -> 줄당 300, 3줄 -> 줄당 500, 4줄 -> 줄당 1000
	
	srand((unsigned)time(NULL));	// 난수 시드값 초기화
	int block_num = rand() % 7;				// 현재 내려가고 있는 테트로미노 번호 저장 변수
	int next_block = rand() % 7;			// 다음 내려올 테트로미노

	init_tetromino(tetromino);		// 테트로미노 정보 만들기

	system("cls");		// 화면 지우기
	box(0, 0, 21, 20);		// 테트리스 게임 판 그리기(일단 대충 이걸로..) 각 칸의 좌표는 (x * 2, y)
	box(23, 0, 14, 1);
	printf("점수 : %6d", score);
	box(23, 3, 14, 5);
	tetromino[NEXT] = tetromino[next_block];
	tetromino[NEXT].center.X = 15;
	tetromino[NEXT].center.Y = 6;
	print_tetromino(&tetromino[NEXT]);


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
	for (j = 1; j <= 10; j++)		// 테트리스 윗판 설정
		grid[0][j].situation = 0;


	tetromino[block_num].center.X = 5;
	tetromino[block_num].center.Y = 2;

	while (run) {
		while (!kbhit()) {		// 키보드 입력 감지할 때까지
			Sleep(10);
			if (timer)
			{
				if (end - start >= delay)
				{
					erase_tetromino(&tetromino[block_num]);
					if (down_tetromino(grid, &tetromino[block_num]) == 0)		// 테트로미노가 바닥에 닿았으면
					{
						print_tetromino(&tetromino[block_num]);
						set_grid(grid, &tetromino[block_num]);
						switch (check_grid(grid))
						{
						case 1:
							score += 100;
							gotoxy(32, 1);
							printf("%6d", score);
							break;
						case 2:
							score += 600;
							gotoxy(32, 1);
							printf("%6d", score);
							break;
						case 3:
							score += 1500;
							gotoxy(32, 1);
							printf("%6d", score);
							break;
						case 4:
							score += 4000;
							gotoxy(32, 1);
							printf("%6d", score);
							break;
						default:
							break;
						}

						block_num = next_block;			// 새로운 테트로미노(원래는 먼저 정해놓아야 함, 지금은 임시로)
						tetromino[block_num].center.X = 5;
						tetromino[block_num].center.Y = 2;
						
						erase_tetromino(&tetromino[NEXT]);
						next_block = rand() % 7;
						tetromino[NEXT] = tetromino[next_block];
						tetromino[NEXT].center.X = 15;
						tetromino[NEXT].center.Y = 6;
						print_tetromino(&tetromino[NEXT]);
						
						if (is_overlap(grid, &tetromino[block_num]))			// 게임이 끝나면
						{
							print_tetromino(&tetromino[block_num]);
							run = 0;
							Sleep(1000);
							break;
						}

						if (delay > 100)
							delay -= mode;
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

	return score;
}