#include <stdio.h>
#include "header.h"

typedef enum {
	LOGIN, SIGNUP, TERMINATE
} Menu;

int main(void)
{
#if RESET
	FILE* fp;
	remove("informations.dat");
	remove("easyrecords.dat");
	remove("normalrecords.dat");
	remove("hardrecords.dat");
	fp = fopen("informations.dat", "wb");
	fclose(fp);
	fp = fopen("easyrecords.dat", "wb");
	fclose(fp);
	fp = fopen("normalrecords.dat", "wb");
	fclose(fp);
	fp = fopen("hardrecords.dat", "wb");
	fclose(fp);
#endif
	int i;			// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	int clean = 0;		// �ٸ� �޴��� ���� ���� ���� ��ü â ����� �۾� ����
	Menu menu = LOGIN;
	Information info;		// ����� ����

	console(40, 25);		// �ܼ� â ũ�� ����
	CursorView(0);		// Ŀ�� �����

	while (end == 0) {
		if (clean) {
			system("cls");
			clean = 0;
		}
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
			clean = 1;
			switch (menu) {
			case LOGIN:
				info = login();
				if (info.onoff == 1) {
					if (strcmp(info.id, "admin") == 0)
						admin_page();
					else mypage(&info);
				}
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