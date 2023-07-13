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
	int i;			// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int end = 0;
	int clean = 0;		// 다른 메뉴를 갔다 왔을 때만 전체 창 지우는 작업 실행
	Menu menu = LOGIN;
	Information info;		// 사용자 정보

	console(40, 25);		// 콘솔 창 크기 설정
	CursorView(0);		// 커서 숨기기
	DWORD prevMode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &prevMode);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), prevMode & ~ENABLE_QUICK_EDIT_MODE);
	/* 드래그(빠른 편집) 방지 */
	while (end == 0) {
		if (clean) {
			system("cls");
			clean = 0;
		}
		switch(menu) {
		case LOGIN:
			box(13, 5, 9, 1, 1, " 로그인");
			box(13, 10, 9, 1, 0, "회원가입");
			box(13, 15, 9, 1, 0, "게임종료");
			break;
		case SIGNUP:
			box(13, 5, 9, 1, 0, " 로그인");
			box(13, 10, 9, 1, 1, "회원가입");
			box(13, 15, 9, 1, 0, "게임종료");
			break;
		case TERMINATE:
			box(13, 5, 9, 1, 0, " 로그인");
			box(13, 10, 9, 1, 0, "회원가입");
			box(13, 15, 9, 1, 1, "게임종료");
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