#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define B 0	//����  /����(0), ��ο� �Ķ�(16), ��ο� �ʷ�(32), ��ο� �ϴ�(48), ��ο� ����(64), ��ο� ����(80), ��ο� ���(96), ȸ��(112), ��ο� ȸ��(128), �Ķ�(144), �ʷ�(160), �ϴ�(176), ����(192), ���� (208), ���(224), �Ͼ�(240) 
#define C 15		//�⺻���ڻ�   /����(0), ��ο� �Ķ�(1), ��ο� �ʷ�(2), ��ο� �ϴ�(3), ��ο� ����(4), ��ο� ����(5), ��ο� ���(6), ȸ��(7), ��ο� ȸ��(8), �Ķ�(9), �ʷ�(10), �ϴ�(11), ����(12), ����(13), ���(14), �Ͼ�(15) 
#define A 10		//�������ڻ�

enum {
    UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, ENTER = 13, EXIT = 101, BACKSPACE = 8
};


void gotoxy(int x, int y);			// Ŀ�� �̵� �Լ� (����, ����) 
void console(int g, int s);			// �ܼ� ũ�� ���� �Լ�(����, ����) 
void color(int a, int b);			// �� ���� �Լ� (����, ���ڻ�) 
void CursorView(char show);			// Ŀ�� ����� �Լ� 0: �����, 1: ��Ÿ���� 
void box(int g, int s, int gl, int sl, int mode, const char* message);	// x��ǥ, y��ǥ, x����, y����, �޼���, ���(1:����, 0: �⺻)
void clearSound1();
