#include "header.h"

void game()
{
	int i, j;		// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;

	system("cls");		// ȭ�� �����
	box(0, 0, 21, 20);		// ��Ʈ���� ���� �� �׸���(�ϴ� ���� �̰ɷ�..) �� ĭ�� ��ǥ�� (x * 2, y)

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