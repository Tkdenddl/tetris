#include "interface.h"


void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void console(int g, int s)
{
	char d[30];
	color(C, B);
	sprintf(d, "mode con cols=%d lines=%d", g, s);
	system(d);
	return;
}
void color(int a, int b)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a | b);
	return;
}
void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void box(int g, int s, int gl, int sl)
{
	int x, y;
	gotoxy(g, s);
	printf("¦£");
	for (x = 1; x <= gl; x++)
		printf("¦¡");
	printf("¦¤ ");
	for (y = 1; y <= sl; y++)
	{
		gotoxy(g, ++s);
		printf("¦¢");
		for (x = 1; x <= gl; x++)
			printf(" ");
			printf("¦¢ ");
	}
	gotoxy(g, ++s);
	printf("¦¦");
	for (x = 1; x <= gl; x++)
		printf("¦¡");
	printf("¦¥ ");
	gotoxy(g + 2, s - sl);
	return;
}
