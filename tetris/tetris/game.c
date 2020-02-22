#include "header.h"

void game()
{
	int i, j;		// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	int block_num = 6;				// ���� �������� �ִ� ��Ʈ�ι̳� ��ȣ ���� ����
	Tetromino tetromino[7];			// 7���� ��Ʈ�ι̳�  ������ ����ִ� �迭
	Tetris grid[21][11];		// ��Ʈ���� �� ���� �迭

	system("cls");		// ȭ�� �����
	box(0, 0, 21, 20);		// ��Ʈ���� ���� �� �׸���(�ϴ� ���� �̰ɷ�..) �� ĭ�� ��ǥ�� (x * 2, y)

	init_tetromino(tetromino);		// ��Ʈ�ι̳� ���� �����

	for (i = 1; i <= 20; i++)		// ��Ʈ���� �� ���� �迭 �ʱ�ȭ
		for (j = 1; j <= 10; j++)
			grid[i][j].situation = 0;

	tetromino[block_num].center.X = 5;
	tetromino[block_num].center.Y = 5;

	while (end == 0) {
		while (!kbhit()) {		// Ű���� �Է� ������ ������
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