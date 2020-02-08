#include <stdio.h>
#include "header.h"

typedef enum {
	START, TERMINATE
} Menu;

int main(void)
{
	int i;			// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	Menu menu = START;

	console(40, 25);		// �ܼ� â ũ�� ����
	CursorView(0);		// Ŀ�� �����

	while (end == 0) {
		system("cls");		// ȭ�� �����
		switch(menu) {
		case START:
			color(A, B);
			box(13, 5, 10, 1);
			printf("���� ����");
			color(C, B);
			box(13, 10, 10, 1);
			printf("���� ����");
			break;
		case TERMINATE:
			box(13, 5, 10, 1);
			printf("���� ����");
			color(A, B);
			box(13, 10, 10, 1);
			printf("���� ����");
			color(C, B);
			break;
		}
		key = getch();		// Ű���� �Է�
		switch (key) {
		case UP:
			if(menu > 0) menu--;
			break;
		case DOWN:
			if (menu < 1) menu++;
			break;
		case ENTER:
			switch (menu) {
			case START:
				game();		// ���� ����
				break;
			case TERMINATE:
				end = 1;
				break;
			}
		}
	}

	return 0;
}