#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define B 0	//배경색  /검정(0), 어두운 파랑(16), 어두운 초록(32), 어두운 하늘(48), 어두운 빨강(64), 어두운 보라(80), 어두운 노랑(96), 회색(112), 어두운 회색(128), 파랑(144), 초록(160), 하늘(176), 빨강(192), 보라 (208), 노랑(224), 하양(240) 
#define C 15		//기본글자색   /검정(0), 어두운 파랑(1), 어두운 초록(2), 어두운 하늘(3), 어두운 빨강(4), 어두운 보라(5), 어두운 노랑(6), 회색(7), 어두운 회색(8), 파랑(9), 초록(10), 하늘(11), 빨강(12), 보라(13), 노랑(14), 하양(15) 
#define A 10		//강조글자색

enum {
    UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, ENTER = 13, EXIT = 101, BACKSPACE = 8
};


void gotoxy(int x, int y);			// 커서 이동 함수 (가로, 세로) 
void console(int g, int s);			// 콘솔 크기 변경 함수(가로, 세로) 
void color(int a, int b);			// 색 변경 함수 (배경색, 글자색) 
void CursorView(char show);			// 커서 숨기는 함수 0: 숨기기, 1: 나타내기 
void box(int g, int s, int gl, int sl, int mode, const char* message);	// x좌표, y좌표, x길이, y길이, 메세지, 모드(1:강조, 0: 기본)
void clearSound1();
