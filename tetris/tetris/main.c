#include <stdio.h>
#include "header.h"

typedef enum {
	LOGIN, SIGNUP, TERMINATE
} Menu;

int main(void)
{
	int i;			// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int end = 0;
	Menu menu = LOGIN;
	Information *info;		// 사용자 정보

	console(40, 25);		// 콘솔 창 크기 설정
	CursorView(0);		// 커서 숨기기

	while (end == 0) {
		system("cls");		// 화면 지우기
		switch(menu) {
		case LOGIN:
			color(A, B);
			box(13, 5, 9, 1);
			printf(" 로그인");
			color(C, B);
			box(13, 10, 9, 1);
			printf("회원가입");
			box(13, 15, 9, 1);
			printf("게임종료");
			break;
		case SIGNUP:
			box(13, 5, 9, 1);
			printf(" 로그인");
			color(A, B);
			box(13, 10, 9, 1);
			printf("회원가입");
			color(C, B);
			box(13, 15, 9, 1);
			printf("게임종료");
			break;
		case TERMINATE:
			box(13, 5, 9, 1);
			printf(" 로그인");
			box(13, 10, 9, 1);
			printf("회원가입");
			color(A, B);
			box(13, 15, 9, 1);
			printf("게임종료");
			color(C, B);
			break;
		}
		key = getch();		// 키보드 입력
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
				if ((info = login()) != NULL)
				{
					RECORD record;
					record.score = game();		// 게임 시작
					
					FILE* fp = fopen("records.dat", "a");
					if (fp == NULL)
					{
						fprintf(stderr, "records.dat 파일 열기 실패 /n");
						break;
					}
					
					record.time = time(NULL);
					strcpy(record.id, info->id);

					if (fwrite(&record, sizeof(RECORD), 1, fp) == NULL)
						fprintf(stderr, "records.dat 파일 쓰기 오류 /n");

					fclose(fp);
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