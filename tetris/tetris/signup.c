#include "interface.h"

char signup()
{
	Information information;

	system("cls");		// ȭ�� �����
	Cursorview(1);		// Ŀ�� ���̱�

	box(10, 5, 10, 1);
	printf("�̸� : ");
	box(10, 10, 10, 1);
	printf("���̵� : ");
	box(10, 15, 10, 1);
	printf("��й�ȣ : ");

	return 0;
}