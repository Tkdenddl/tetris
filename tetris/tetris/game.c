#include "header.h"

void game()
{
	int i, j;		// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int run = 1;
	int block_num = 6;				// ���� �������� �ִ� ��Ʈ�ι̳� ��ȣ ���� ����
	Tetromino tetromino[7];			// 7���� ��Ʈ�ι̳�  ������ ����ִ� �迭
	Tetris grid[22][12];		// ��Ʈ���� �� ���� �迭
	clock_t start, end;
	char timer = 0;		// Ÿ�̸� on:1 off:0

	srand((unsigned)time(NULL));	// ���� �õ尪 �ʱ�ȭ

	system("cls");		// ȭ�� �����
	box(0, 0, 21, 20);		// ��Ʈ���� ���� �� �׸���(�ϴ� ���� �̰ɷ�..) �� ĭ�� ��ǥ�� (x * 2, y)

	init_tetromino(tetromino);		// ��Ʈ�ι̳� ���� �����

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

	tetromino[block_num].center.X = 5;
	tetromino[block_num].center.Y = 3;

	while (run) {
		while (!kbhit()) {		// Ű���� �Է� ������ ������
			if (timer)
			{
				if (end - start >= DELAY)
				{
					erase_tetromino(&tetromino[block_num]);
					if (down_tetromino(grid, &tetromino[block_num]) == 0)		// ��Ʈ�ι̳밡 �ٴڿ� �������
					{
						print_tetromino(&tetromino[block_num]);
						set_grid(grid, &tetromino[block_num]);
						check_grid(grid);

						block_num = rand() % 7;			// ���ο� ��Ʈ�ι̳�(������ ���� ���س��ƾ� ��, ������ �ӽ÷�)
						tetromino[block_num].center.X = 5;
						tetromino[block_num].center.Y = 3;
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
			//	if(������ �ٴڿ� ������)
			//		if(������ ���� ������)
			//			���ְ� ����
			//			���� �߰�
			//		��� �ø�
			//	if(��� �÷��� ������)
			//		���ο� ���� ����
			//		��� ����
			//	���� �ð����� ���� ����.....
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