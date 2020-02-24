#include <stdio.h>
#include "header.h"

typedef enum {
	LOGIN, SIGNUP, TERMINATE
} Menu;

int main(void)
{
	int i;			// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	Menu menu = LOGIN;

	console(40, 25);		// �ܼ� â ũ�� ����
	CursorView(0);		// Ŀ�� �����

	while (end == 0) {
		system("cls");		// ȭ�� �����
		switch(menu) {
		case LOGIN:
			color(A, B);
			box(13, 5, 9, 1);
			printf(" �α���");
			color(C, B);
			box(13, 10, 9, 1);
			printf("ȸ������");
			box(13, 15, 9, 1);
			printf("��������");
			break;
		case SIGNUP:
			box(13, 5, 9, 1);
			printf(" �α���");
			color(A, B);
			box(13, 10, 9, 1);
			printf("ȸ������");
			color(C, B);
			box(13, 15, 9, 1);
			printf("��������");
			break;
		case TERMINATE:
			box(13, 5, 9, 1);
			printf(" �α���");
			box(13, 10, 9, 1);
			printf("ȸ������");
			color(A, B);
			box(13, 15, 9, 1);
			printf("��������");
			color(C, B);
			break;
		}
		key = getch();		// Ű���� �Է�
		switch (key) {
		case UP:
			if(menu > LOGIN) menu--;
			break;
		case DOWN:
			if (menu < TERMINATE) menu++;
			break;
		case ENTER:
			switch (menu) {
			case LOGIN:
				if(login() != NULL)
					game();		// ���� ����
				break;
			case SIGNUP:
				signup();
				break;
			case TERMINATE:
				end = 1;
				break;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}