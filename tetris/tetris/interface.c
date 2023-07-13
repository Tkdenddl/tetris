#include "interface.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


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

void box(int g, int s, int gl, int sl, int mode, const char* message)
{
	int x, y;
	if (mode) color(A, B);
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
	printf(message);
	color(C, B);
	return;
}

void clearSound1()
{
	PlaySound(TEXT("sound/Clear1.wav"), 0, SND_ASYNC);
	return;
}

void clearSound2()
{
	PlaySound(TEXT("sound/Clear2.wav"), 0, SND_ASYNC);
	return;
}

void clearSound3()
{
	PlaySound(TEXT("sound/Clear3.wav"), 0, SND_ASYNC);
	return;
}

void clearSound4()
{
	PlaySound(TEXT("sound/Clear4.wav"), 0, SND_ASYNC);
	return;
}