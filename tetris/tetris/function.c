#include "header.h"

void init_tetromino(Tetromino* tetp)
{
	// ��Ʈ�ι̳� ��
	tetp[0].t_color = 0;
	tetp[1].t_color = 0;
	tetp[2].t_color = 0;
	tetp[3].t_color = 0;
	tetp[4].t_color = 0;
	tetp[5].t_color = 0;
	tetp[6].t_color = 0;

	// ��Ʈ���̳븶�� ���ͺ�Ͽ� ���� ������ ����� �������ǥ
	tetp[0].block[0].X = 1, tetp[0].block[0].Y = 0;
	tetp[0].block[1].X = 0, tetp[0].block[1].Y = -1;
	tetp[0].block[2].X = 1, tetp[0].block[2].Y = -1;

	tetp[1].block[0].X = 0, tetp[1].block[0].Y = 2;
	tetp[1].block[1].X = 0, tetp[1].block[1].Y = 1;
	tetp[1].block[2].X = 0, tetp[1].block[2].Y = -1;

	tetp[2].block[0].X = -1, tetp[2].block[0].Y = 0;
	tetp[2].block[1].X = 0, tetp[2].block[1].Y = -1;
	tetp[2].block[2].X = 1, tetp[2].block[2].Y = -1;

	tetp[3].block[0].X = -1, tetp[3].block[0].Y = 0;
	tetp[3].block[1].X = 0, tetp[3].block[1].Y = 1;
	tetp[3].block[2].X = 1, tetp[3].block[2].Y = 1;

	tetp[4].block[0].X = -1, tetp[4].block[0].Y = 0;
	tetp[4].block[1].X = 0, tetp[4].block[1].Y = -1;
	tetp[4].block[2].X = 0, tetp[4].block[2].Y = -2;

	tetp[5].block[0].X = 1, tetp[5].block[0].Y = 0;
	tetp[5].block[1].X = 0, tetp[5].block[1].Y = -1;
	tetp[5].block[2].X = 0, tetp[5].block[2].Y = -2;

	tetp[6].block[0].X = -1, tetp[6].block[0].Y = 0;
	tetp[6].block[1].X = 0, tetp[6].block[1].Y = 1;
	tetp[6].block[2].X = 1, tetp[6].block[2].Y = 0;

	return;
}

void print_tetromino(Tetromino* tetp)
{
	gotoxy(tetp->center.X * 2, tetp->center.Y);
	printf("��");

	for (int i = 0; i < 3; i++)
	{
		gotoxy((tetp->block[i].X + tetp->center.X) * 2, tetp->block[i].Y + tetp->center.Y);
		printf("��");
	}

	return;
}

void rotate_tetromino(Tetromino* tetp)
{
	for (int i = 0; i < 3; i++)
	{
		tetp->block[i].Y *= -1;
		SWAP(short, tetp->block[i].X, tetp->block[i].Y);
	}
}

void erase_tetromino(Tetromino* tetp)
{
	gotoxy(tetp->center.X * 2, tetp->center.Y);
	printf("  ");

	for (int i = 0; i < 3; i++)
	{
		gotoxy((tetp->block[i].X + tetp->center.X) * 2, tetp->block[i].Y + tetp->center.Y);
		printf("  ");
	}
}

int down_tetromino(Tetris grid[][11], Tetromino* tetp)
{
	if (grid[tetp->center.Y + 1][tetp->center.X].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y + 1][tetp->center.X + tetp->block[0].X].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y + 1][tetp->center.X + tetp->block[1].X].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y + 1][tetp->center.X + tetp->block[2].X].situation == 0
		&& tetp->center.Y + 1 <= 20
		&& tetp->center.Y + tetp->block[0].Y + 1 <= 20
		&& tetp->center.Y + tetp->block[1].Y + 1 <= 20
		&& tetp->center.Y + tetp->block[2].Y + 1 <= 20) {
		tetp->center.Y++;
		return 1;		// ������ ����
	}
	else
		return 0;		// ������ ����
}

int right_tetromino(Tetris grid[][11], Tetromino* tetp)
{
	if (grid[tetp->center.Y][tetp->center.X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X + 1].situation == 0
		&& tetp->center.X + 1 <= 10
		&& tetp->center.X + tetp->block[0].X + 1 <= 10
		&& tetp->center.X + tetp->block[1].X + 1 <= 10
		&& tetp->center.X + tetp->block[2].X + 1 <= 10) {
		tetp->center.X++;
		return 1;		// ������ �̵� ����
	}
	else
		return 0;		// ������ �̵� ����
}

int left_tetromino(Tetris grid[][11], Tetromino* tetp)
{
	if (grid[tetp->center.Y][tetp->center.X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X - 1].situation == 0
		&& tetp->center.X - 1 >= 1
		&& tetp->center.X + tetp->block[0].X - 1 >= 1
		&& tetp->center.X + tetp->block[1].X - 1 >= 1
		&& tetp->center.X + tetp->block[2].X - 1 >= 1) {
		tetp->center.X--;
		return 1;		// ���� �̵� ����
	}
	else
		return 0;		// ���� �̵� ����
}
