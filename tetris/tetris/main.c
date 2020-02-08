#include <stdio.h>
#include "header.h"

typedef enum {
	START, TERMINATE
} Menu;

int main(void)
{
	int i;			// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int end = 0;
	Menu menu = START;

	console(40, 25);		// 콘솔 창 크기 설정
	CursorView(0);		// 커서 숨기기

	while (end == 0) {
		system("cls");		// 화면 지우기
		switch(menu) {
		case START:
			color(A, B);
			box(13, 5, 10, 1);
			printf("게임 시작");
			color(C, B);
			box(13, 10, 10, 1);
			printf("게임 종료");
			break;
		case TERMINATE:
			box(13, 5, 10, 1);
			printf("게임 시작");
			color(A, B);
			box(13, 10, 10, 1);
			printf("게임 종료");
			color(C, B);
			break;
		}
		key = getch();		// 키보드 입력
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
				game();		// 게임 시작
				break;
			case TERMINATE:
				end = 1;
				break;
			}
		}
	}

	return 0;
}