#include "header.h"

typedef enum {
	NAME, ID, PASSWORD, MAKE, BACK
} Infomenu;

Information* login()
{
	int end = 0;
	int key;
	Infomenu infomenu = ID;
	Information information;
	Information data;
	FILE* p_file;
	do {
		p_file = fopen("informations.dat", "rb");
	} while (p_file == NULL);

	while (end == 0) {
		system("cls");
		switch (infomenu) {
		case ID:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			color(A, B);
			box(0, 5, 9, 1);
			printf(" ���̵�");
			color(C, B);
			box(0, 10, 9, 1);
			printf("��й�ȣ");
			box(0, 15, 9, 1);
			printf(" �α���");
			box(0, 20, 9, 1);
			printf(" ������");
			break;
		case PASSWORD:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(0, 5, 9, 1);
			printf(" ���̵�");
			color(A, B);
			box(0, 10, 9, 1);
			printf("��й�ȣ");
			color(C, B);
			box(0, 15, 9, 1);
			printf(" �α���");
			box(0, 20, 9, 1);
			printf(" ������");
			break;
		case MAKE:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(0, 5, 9, 1);
			printf(" ���̵�");
			box(0, 10, 9, 1);
			printf("��й�ȣ");
			color(A, B);
			box(0, 15, 9, 1);
			printf(" �α���");
			color(C, B);
			box(0, 20, 9, 1);
			printf(" ������");
			break;
		case BACK:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(0, 5, 9, 1);
			printf(" ���̵�");
			box(0, 10, 9, 1);
			printf("��й�ȣ");
			box(0, 15, 9, 1);
			printf(" �α���");
			color(A, B);
			box(0, 20, 9, 1);
			printf(" ������");
			color(C, B);
			break;
		}
		key = getch();
		switch (key) {
		case UP:
			if (infomenu > ID)
				infomenu--;
			break;
		case DOWN:
			if (infomenu < BACK)
				infomenu++;
			break;
		case ENTER:
			switch (infomenu) {
			case ID:
				gotoxy(14, 6);
				CursorView(1);
				scanf("%s", &data.id);
				CursorView(0);
				break;
			case PASSWORD:
				gotoxy(14, 11);
				CursorView(1);
				scanf("%s", &data.password);
				CursorView(0);
				break;
			case MAKE:
				fseek(p_file, 0, SEEK_SET);
				while (feof(p_file) == 0) {
					fread(&information, sizeof(information), 1, p_file);
					if (strcmp(data.id, information.id) == 0 && strcmp(data.password, information.password) == 0)
					{
						fclose(p_file);		// ���� ��Ʈ�� �ݳ�
						return &information;
					}
				}
				gotoxy(0, 0);
				printf("�α��ο� �����߽��ϴ�.");
				break;
			case BACK:
				end = 1;
			}
			break;
		default:
			break;
		}
	}

	fclose(p_file);		// ���� ��Ʈ�� �ݳ�
	return NULL;
}

void signup()
{
	FILE* p_file;
	int i;			// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	Infomenu infomenu = NAME;
	Information information;
	
	do {
		p_file = fopen("informations.dat", "ab");
	} while (p_file == NULL);

	while (end == 0) {
		system("cls");		// ȭ�� �����
		switch (infomenu) {
		case NAME:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(12, 15, 25, 1);
			color(A, B);
			box(0, 5, 9, 1);
			printf("  �̸�");
			color(C, B);
			box(0, 10, 9, 1);
			printf(" ���̵�");
			box(0, 15, 9, 1);
			printf("��й�ȣ");
			box(0, 20, 9, 1);
			printf("��������");
			break;
		case ID:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(12, 15, 25, 1);
			box(0, 5, 9, 1);
			printf("  �̸�");
			color(A, B);
			box(0, 10, 9, 1);
			printf(" ���̵�");
			color(C, B);
			box(0, 15, 9, 1);
			printf("��й�ȣ");
			box(0, 20, 9, 1);
			printf("��������");
			break;
		case PASSWORD:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(12, 15, 25, 1);
			box(0, 5, 9, 1);
			printf("  �̸�");
			box(0, 10, 9, 1);
			printf(" ���̵�");
			color(A, B);
			box(0, 15, 9, 1);
			printf("��й�ȣ");
			color(C, B);
			box(0, 20, 9, 1);
			printf("��������");
			break;
		case MAKE:
			box(12, 5, 25, 1);
			box(12, 10, 25, 1);
			box(12, 15, 25, 1);
			box(0, 5, 9, 1);
			printf("  �̸�");
			box(0, 10, 9, 1);
			printf(" ���̵�");
			box(0, 15, 9, 1);
			printf("��й�ȣ");
			color(A, B);
			box(0, 20, 9, 1);
			printf("��������");
			color(C, B);
			break;
		}
		key = getch();
		switch (key) {
		case UP:
			if (infomenu > NAME)
				infomenu--;
			break;
		case DOWN:
			if (infomenu < MAKE)
				infomenu++;
			break;
		case ENTER:
			switch (infomenu) {
			case NAME:
				gotoxy(14, 6);
				CursorView(1);
				scanf("%s", &information.name);
				CursorView(0);
				break;
			case ID:
				gotoxy(14, 11);
				CursorView(1);
				scanf("%s", &information.id);
				CursorView(0);
				break;
			case PASSWORD:
				gotoxy(14, 16);
				CursorView(1);
				scanf("%s", &information.password);
				CursorView(0);
				break;
			case MAKE:
				fwrite(&information, sizeof(information), 1, p_file);
				end = 1;
				break;
			}
			break;
		default:
			break;
		}
	}

	fclose(p_file);
	return 0;
}

void init_tetromino(Tetromino* tetp)
{
	// ��Ʈ�ι̳� ��
	tetp[0].t_color = 14;
	tetp[1].t_color = 11;
	tetp[2].t_color = 12;
	tetp[3].t_color = 10;
	tetp[4].t_color = 6;
	tetp[5].t_color = 9;
	tetp[6].t_color = 13;

	// ��Ʈ���̳븶�� ���ͺ�Ͽ� ���� ������ ����� �������ǥ
	tetp[0].block[0].X = 1, tetp[0].block[0].Y = 0;
	tetp[0].block[1].X = 0, tetp[0].block[1].Y = -1;
	tetp[0].block[2].X = 1, tetp[0].block[2].Y = -1;

	tetp[1].block[0].X = 0, tetp[1].block[0].Y = 1;
	tetp[1].block[1].X = 0, tetp[1].block[1].Y = -1;
	tetp[1].block[2].X = 0, tetp[1].block[2].Y = 2;

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
	color(tetp->t_color, B);
	printf("��");

	for (int i = 0; i < 3; i++)
	{
		gotoxy((tetp->block[i].X + tetp->center.X) * 2, tetp->block[i].Y + tetp->center.Y);
		printf("��");
	}
	color(C, B);
	return;
}

void rotate_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	short x, y;
	int i;
	int count = 0;

	for (i = 0; i < 3; i++)
	{
		x = tetp->center.X - tetp->block[i].Y;
		y = tetp->center.Y + tetp->block[i].X;
		if (grid[y][x].situation == 1)
			count++;
	}
	if (count == 0) 
		for (i = 0; i < 3; i++) {
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

int down_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	if (grid[tetp->center.Y + 1][tetp->center.X].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y + 1][tetp->center.X + tetp->block[0].X].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y + 1][tetp->center.X + tetp->block[1].X].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y + 1][tetp->center.X + tetp->block[2].X].situation == 0
		) {
		tetp->center.Y++;
		return 1;		// ������ ����
	}
	else
		return 0;		// ������ ����
}

int right_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	if (grid[tetp->center.Y][tetp->center.X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X + 1].situation == 0
		) {
		tetp->center.X++;
		return 1;		// ������ �̵� ����
	}
	else
		return 0;		// ������ �̵� ����
}

int left_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	if (grid[tetp->center.Y][tetp->center.X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X - 1].situation == 0
		) {
		tetp->center.X--;
		return 1;		// ���� �̵� ����
	}
	else
		return 0;		// ���� �̵� ����
}

void set_grid(Tetris grid[][12], Tetromino* tetp)		// ��Ʈ�ι̳밡 �� ������ �����Ǹ� ������ �� �κ��� situation�� 1��
{
	grid[tetp->center.Y][tetp->center.X].situation = 1;
	grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X].situation = 1;
	grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X].situation = 1;
	grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X].situation = 1;
	grid[tetp->center.Y][tetp->center.X].t_color = tetp->t_color;
	grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X].t_color = tetp->t_color;
	grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X].t_color = tetp->t_color;
	grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X].t_color = tetp->t_color;

	return;
}

char check_grid(Tetris grid[][12])		// ���ڻ��¸� üũ�ؼ� �ϼ��� ���� ������ �� ���� ���ְ� ����. ��ȯ���� ���� ���� ����
{
	char result = 0;
	int i, j, k, l;
	char count = 0;

	for (i = 1; i <= 20; i++)
	{
		for (j = 1; j <= 10; j++)
			if (grid[i][j].situation)		// ä����������
				count++;
		if (count == 10)		// ��� ä���� ������ 
		{
			for (k = i; k >= 1; k--)
				for (l = 1; l <= 10; l++)
					grid[k][l] = grid[k - 1][l];		// �Ʒ�ĭ�� ������ ��ĭ���� �ٲ�
			result++;
		}
		count = 0;
	}

	draw_grid(grid);
	return result;
}

void draw_grid(Tetris grid[][12])		// ������ ��Ʈ�ι̳�� �׸���
{
	int i, j;

	for (i = 1; i <= 20; i++)
		for (j = 1; j <= 10; j++)
		{
			gotoxy(j * 2, i);
			if (grid[i][j].situation) {
				color(grid[i][j].t_color, B);
				printf("��");
				color(C, B);
			}
			else
				printf("  ");

		}

	return;
}

char is_overlap(Tetris grid[][12], Tetromino* tetp)		// ��Ʈ�ι̳밡 ������ �ڸ��� �����ִ°� -> ������ �������� ����
{
	if (grid[tetp->center.Y][tetp->center.X].situation)
		return 1;
	for (int i = 0; i < 3; i++)
		if (grid[tetp->center.Y + tetp->block[i].Y][tetp->center.X + tetp->block[i].X].situation)
			return 1;

	return 0;
}