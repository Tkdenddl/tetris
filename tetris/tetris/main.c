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
	remove("records.dat");
	fp = fopen("informations.dat", "wb");
	fclose(fp);
	fp = fopen("records.dat", "wb");
	fclose(fp);
#endif
	int i;			// �ݺ��� ���� ����
	int key;		// Ű���� �Է� ��
	int end = 0;
	Menu menu = LOGIN;
	Information info;		// ����� ����
	MODE mode = HARD;		// ������ ���̵�

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
				info = login();
				if (info.id[19] != 'N')
				{
					RECORD record;
					int rank;		// ��ϼ���
					record.score = game(mode);		// ���� ����
					record.time = time(NULL);
					strcpy(record.id, info.id);

					rank = add_record(&record);
					system("cls");
					box(0, 0, 21, 1);
					printf("%d \t %d \t %s", rank, record.score, info.id);

					// ��� ��� -> ���߿� �Լ�ȭ??
					RECORD temp;
					FILE* fp = fopen("records.dat", "rb");
					box(0, 3, 30, 15);
					printf("��ϼ���");
					for (int i = 0; i < 10; i++)
					{
						if (fread(&temp, sizeof(RECORD), 1, fp) == NULL)
							break;
						gotoxy(2, 4 + i);
						printf("%d: %d \t %s", i + 1, temp.score, temp.id);
					}
					
					_getch();
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