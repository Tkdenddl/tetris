#include "header.h"

void game()
{
	int i, j;		// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	Tetromino tetromino[7];			// 7���� ��Ʈ�ι̳�  ������ ����ִ� �迭
	Tetris tetris[20][10];		// ��Ʈ���� �� ���� �迭

	system("cls");		// ȭ�� �����
	box(0, 0, 21, 20);		// ��Ʈ���� ���� �� �׸���(�ϴ� ���� �̰ɷ�..) �� ĭ�� ��ǥ�� (x * 2, y)

	init_tetromino(tetromino);		// ��Ʈ�ι̳� ���� �����

	for (i = 0; i < 20; i++)		// ��Ʈ���� �� ���� �迭 �ʱ�ȭ
		for (j = 0; j < 10; j++)
			tetris[i][j].situation = 0;

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