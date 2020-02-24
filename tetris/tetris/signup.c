#include "interface.h"

char signup()
{
	Information information;

	system("cls");		// 화면 지우기
	Cursorview(1);		// 커서 보이기

	box(10, 5, 10, 1);
	printf("이름 : ");
	box(10, 10, 10, 1);
	printf("아이디 : ");
	box(10, 15, 10, 1);
	printf("비밀번호 : ");

	return 0;
}