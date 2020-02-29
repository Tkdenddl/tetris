#include "header.h"

int game(MODE mode)
{
	int i, j;		// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int run = 1;
	
	Tetromino tetromino[8];			// 7���� ��Ʈ�ι̳�  ������ ����ִ� �迭
	Tetris grid[22][12];		// ��Ʈ���� �� ���� �迭
	clock_t start, end;
	char timer = 0;		// Ÿ�̸� on:1 off:0
	short delay = 1000;		// ��Ʈ�ι̳밡 �������� ����: �и���
	int score = 0;		// ����: 1�� -> �ٴ� 100, 2�� -> �ٴ� 300, 3�� -> �ٴ� 500, 4�� -> �ٴ� 1000
	
	srand((unsigned)time(NULL));	// ���� �õ尪 �ʱ�ȭ
	int block_num = rand() % 7;				// ���� �������� �ִ� ��Ʈ�ι̳� ��ȣ ���� ����
	int next_block = rand() % 7;			// ���� ������ ��Ʈ�ι̳�

	init_tetromino(tetromino);		// ��Ʈ�ι̳� ���� �����

	system("cls");		// ȭ�� �����
	box(0, 0, 21, 20);		// ��Ʈ���� ���� �� �׸���(�ϴ� ���� �̰ɷ�..) �� ĭ�� ��ǥ�� (x * 2, y)
	box(23, 0, 14, 1);
	printf("���� : %6d", score);
	box(23, 3, 14, 5);
	tetromino[NEXT] = tetromino[next_block];
	tetromino[NEXT].center.X = 15;
	tetromino[NEXT].center.Y = 6;
	print_tetromino(&tetromino[NEXT]);


	for (i = 1; i <= 20; i++)		// ��Ʈ���� �� ���� �迭 �ʱ�ȭ
	{
		for (j = 1; j <= 10; j++) {
			grid[i][j].situation = 0;
			grid[i][j].t_color = 15;
		}
		grid[i][0].situation = 1;		// ��Ʈ���� ���� ����
		grid[i][11].situation = 1;
	}
	for (j = 1; j <= 10; j++)		// ��Ʈ���� �ٴ��� ����
		grid[i][j].situation = 1;
	for (j = 1; j <= 10; j++)		// ��Ʈ���� ���� ����
		grid[0][j].situation = 0;


	tetromino[block_num].center.X = 5;
	tetromino[block_num].center.Y = 2;

	while (run) {
		while (!kbhit()) {		// Ű���� �Է� ������ ������
			Sleep(10);
			if (timer)
			{
				if (end - start >= delay)
				{
					erase_tetromino(&tetromino[block_num]);
					if (down_tetromino(grid, &tetromino[block_num]) == 0)		// ��Ʈ�ι̳밡 �ٴڿ� �������
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

						block_num = next_block;			// ���ο� ��Ʈ�ι̳�(������ ���� ���س��ƾ� ��, ������ �ӽ÷�)
						tetromino[block_num].center.X = 5;
						tetromino[block_num].center.Y = 2;
						
						erase_tetromino(&tetromino[NEXT]);
						next_block = rand() % 7;
						tetromino[NEXT] = tetromino[next_block];
						tetromino[NEXT].center.X = 15;
						tetromino[NEXT].center.Y = 6;
						print_tetromino(&tetromino[NEXT]);
						
						if (is_overlap(grid, &tetromino[block_num]))			// ������ ������
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
					timer = 0;		// Ÿ�̸� �ʱ�ȭ
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