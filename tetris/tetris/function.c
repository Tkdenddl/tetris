#include "header.h"

typedef enum {
	ID, PASSWORD, MAKE, BACK
} Infomenu;

typedef enum {
	MYPASSWORD, MODE, START, RECORD, MYEXIT
} Mymenu;

typedef enum {
	REMOVE, ADEXIT
} Adminmenu;

void admin_page() 
{
	int end = 0;
	int end2 = 0;
	char key;
	int size;
	int idx = 0;
	int cursorIdx = 0;
	int i;
	Adminmenu adminmenu = REMOVE;
	FILE* fp1;
	Information* info_list;
	while (!end) {
		system("cls");
		switch (adminmenu) {
		case REMOVE:
			box(0, 0, 9, 1, 1, "REMOVE");
			box(15, 0, 9, 1, 0, "EXIT");
			break;
		case ADEXIT:
			box(0, 0, 9, 1, 0, "REMOVE");
			box(15, 0, 9, 1, 1, "EXIT");
			break;
		}
		key = getch();
		switch (key) {
		case LEFT:
			if (adminmenu > REMOVE) adminmenu--;
			break;
		case RIGHT:
			if (adminmenu < ADEXIT) adminmenu++;
			break;
		case ENTER:
			switch (adminmenu) {
			case REMOVE:
				if (!(fp1 = fopen("informations.dat", "rb+"))) {
					fprintf(stderr, "informations.dat 파일을 열지 못했습니다.");
					return;
				}
				fseek(fp1, 0, SEEK_END);
				size = ftell(fp1)/sizeof(Information);
				info_list = (Information*)malloc(size*sizeof(Information));
				fseek(fp1, 0, SEEK_SET);
				for (i = 0; i < size; i++) {
					fread(&info_list[i], sizeof(Information), 1, fp1);
				}
				fclose(fp1);
				box(0, 4, 36, 15, 0, "");
				printf("%-15s%-15s", "ID", "PASSWORD");
				idx = 0;
				cursorIdx = 0;
				end2 = 0;
				while (!end2) {
					box(15, 21, 5, 1, 0, "");
					printf("%d/%d", idx + 1, (size - 1) / 13 + 1);
					for (i = idx * 13; i < idx * 13 + 13; i++) {
						gotoxy(2, 6 + i%13);
						if (cursorIdx == i) color(A, B);
						if (i >= size) printf("%-15s%-15s", "blank", "blank");
						else printf("%-15s%-15s", info_list[i].id, info_list[i].password);
						color(C, B);
					}

					key = getch();
					switch (key) {
					case UP:
						if (cursorIdx > 0) cursorIdx--;
						if (cursorIdx % 13 == 12 && idx > 0) idx--;
						break;
					case DOWN:
						if (cursorIdx < size-1) cursorIdx++;
						if (cursorIdx % 13 == 0 && idx < (size - 1) / 13) idx++;
						break;
					case LEFT:
						if (idx > 0) idx--;
						cursorIdx = idx * 13;
						break;
					case RIGHT:
						if (idx < (size - 1) / 13) idx++;
						cursorIdx = idx * 13;
						break;
					case ENTER:
						remove_record(info_list[cursorIdx].id);
						remove_account(&info_list[cursorIdx]);
						end2 = 1;
						break;
					}
				}
				free(info_list);
				break;
			case ADEXIT:
				end = 1;
				break;
			}
			break;
		}
	}
}

int my_gets(char buffer[], int limit)
{
	char temp;
	int i;
	for (i = 0; i < limit; i++) {
		temp = getchar();
		if (temp == '\n') {
			buffer[i] = 0;
			return i > 0;				// 정상 입력시 1 반환
		}
		buffer[i] = temp;
	}
	buffer[i] = 0;
	rewind(stdin);					// 표준입력 버퍼 비우기
	return 0;						// 글자수 초과 입력시 0 반환
}

void mypage(Information* information)
{
	int i;
	char end = 0;
	char modeend = 0;
	int key;
	char tpassword[20];
	Mymenu mymenu = MYPASSWORD;
	Mode mymode = NORMAL;
	Record record;
	int rank;		// 기록순위
	Record temp;
	int clean = 1;		// 다른 메뉴에서 넘어갈 때만 화면 지우도록

	while (end == 0) {
		if (clean) {
			system("cls");
			clean = 0;
		}
		switch (mymenu) {
		case MYPASSWORD:
			box(0, 0, 20, 1, 0, "");
			printf("ID : %s", information->id);
			box(0, 4, 9, 1, 1, "PASSWORD");
			box(0, 8, 7, 1, 0, " mode");
			box(10, 8, 7, 1, mymode == EASY, " easy");
			box(19, 8, 7, 1, mymode == NORMAL, "normal");
			box(28, 8, 7, 1, mymode == HARD, " hard");
			box(0, 12, 6, 1, 0, "start");
			box(0, 16, 7, 1, 0, "record");
			box(0, 20, 5, 1, 0, "exit");
			break;
		case MODE:
			box(0, 0, 20, 1, 0, "");
			printf("ID : %s", information->id);
			box(0, 4, 9, 1, 0, "PASSWORD");
			box(0, 8, 7, 1, 1, " mode");
			box(10, 8, 7, 1, mymode == EASY, " easy");
			box(19, 8, 7, 1, mymode == NORMAL, "normal");
			box(28, 8, 7, 1, mymode == HARD, " hard");
			box(0, 12, 6, 1, 0, "start");
			box(0, 16, 7, 1, 0, "record");
			box(0, 20, 5, 1, 0, "exit");
			break;
		case START:
			box(0, 0, 20, 1, 0, "");
			printf("ID : %s", information->id);
			box(0, 4, 9, 1, 0, "PASSWORD");
			box(0, 8, 7, 1, 0, " mode");
			box(10, 8, 7, 1, mymode == EASY, " easy");
			box(19, 8, 7, 1, mymode == NORMAL, "normal");
			box(28, 8, 7, 1, mymode == HARD, " hard");
			box(0, 12, 6, 1, 1, "start");
			box(0, 16, 7, 1, 0, "record");
			box(0, 20, 5, 1, 0, "exit");
			break;
		case RECORD:
			box(0, 0, 20, 1, 0, "");
			printf("ID : %s", information->id);
			box(0, 4, 9, 1, 0, "PASSWORD");
			box(0, 8, 7, 1, 0, " mode");
			box(10, 8, 7, 1, mymode == EASY, " easy");
			box(19, 8, 7, 1, mymode == NORMAL, "normal");
			box(28, 8, 7, 1, mymode == HARD, " hard");
			box(0, 12, 6, 1, 0, "start");
			box(0, 16, 7, 1, 1, "record");
			box(0, 20, 5, 1, 0, "exit");
			break;
		case MYEXIT:
			box(0, 0, 20, 1, 0, "");
			printf("ID : %s", information->id);
			box(0, 4, 9, 1, 0, "PASSWORD");
			box(0, 8, 7, 1, 0, " mode");
			box(10, 8, 7, 1, mymode == EASY, " easy");
			box(19, 8, 7, 1, mymode == NORMAL, "normal");
			box(28, 8, 7, 1, mymode == HARD, " hard");
			box(0, 12, 6, 1, 0, "start");
			box(0, 16, 7, 1, 0, "record");
			box(0, 20, 5, 1, 1, "exit");
			break;
		}
		key = getch();
		switch (key) {
		case UP:
			if (mymenu > MYPASSWORD)
				mymenu--;
			break;
		case DOWN:
			if (mymenu < MYEXIT)
				mymenu++;
			break;
		case ENTER:
			clean = 1;
			switch (mymenu) {
			case MYPASSWORD:
				CursorView(1);
				box(12, 4, 25, 1, 0, "current: ");
				my_gets(tpassword, LETTER_LIMIT);
				if (strcmp(tpassword, information->password) == 0) {
					box(12, 4, 25, 1, 0, "alter : ");
					my_gets(information->password, LETTER_LIMIT);
					replace_account(information);
				}
				else {
					box(12, 4, 25, 1, 0, "wrong!\a");
					Sleep(1000);
				}
				CursorView(0);
				break;
			case MODE:
				modeend = 0;
				while (modeend == 0) {
					box(10, 8, 7, 1, mymode == EASY, " easy");
					box(19, 8, 7, 1, mymode == NORMAL, "normal");
					box(28, 8, 7, 1, mymode == HARD, " hard");
					key = getch();
					switch (key) {
					case RIGHT:
						if (mymode < HARD)
							mymode *= 4;
						break;
					case LEFT:
						if (mymode > EASY)
							mymode /= 4;
						break;
					case ENTER:
						modeend = 1;
						break;
					default:
						break;
					}
				}
				break;
			case START:
				record.score = game(mymode);		// 게임 시작
				record.time = time(NULL);
				strcpy(record.id, information->id);


				rank = add_record(&record, mymode);
				if (rank) {
					system("cls");
					print_record(mymode);
					box(15, 0, 22, 1, 0, "");
					printf("%2d등%5d점%10s", rank, record.score, information->id);
					getch();
				}
				break;
			case RECORD:
				system("cls");
				print_record(mymode);
				getch();
				break;
			case MYEXIT:
				information->onoff = 0;					// 로그아웃
				replace_account(information);
				end = 1;
				break;
			}
			break;
		default:
			break;
		}
	}
	return;
}

Information login()
{
	int end = 0;
	int key;
	int key2;		// password 작업
	int i;		// password 작업에 쓰이는 변수.. 
	static char hiding_password[LETTER_LIMIT + 1][2*LETTER_LIMIT + 1] = {
		"",
		"●",
		"●●",
		"●●●",
		"●●●●",
		"●●●●●",
		"●●●●●●",
		"●●●●●●●",
		"●●●●●●●●",
		"●●●●●●●●●"
	};
	int p_length = 0;		// password 길이
	int success = 0;			// 로그인 성공여부
	Infomenu infomenu = ID;
	Information information = {
		NULL, NULL, 0 };
	Information data = {
		NULL, NULL, 0 };
	FILE* p_file;

	system("cls");		// 지금 상태에서는 처음에 한번만 지워도 됨. 나중에 문제가 될 수도 있음
	while (end == 0) {
		switch (infomenu) {
		case ID:
			box(12, 5, 25, 1, 0, data.id);
			box(12, 10, 25, 1, 0, hiding_password[p_length]);
			box(0, 5, 9, 1, 1, " 아이디");
			box(0, 10, 9, 1, 0, "비밀번호");
			box(0, 15, 9, 1, 0, " 로그인");
			box(0, 20, 9, 1, 0, " 나가기");
			break;
		case PASSWORD:
			box(12, 5, 25, 1, 0, data.id);
			box(12, 10, 25, 1, 0, hiding_password[p_length]);
			box(0, 5, 9, 1, 0, " 아이디");
			box(0, 10, 9, 1, 1, "비밀번호");
			box(0, 15, 9, 1, 0, " 로그인");
			box(0, 20, 9, 1, 0, " 나가기");
			break;
		case MAKE:
			box(12, 5, 25, 1, 0, data.id);
			box(12, 10, 25, 1, 0, hiding_password[p_length]);
			box(0, 5, 9, 1, 0, " 아이디");
			box(0, 10, 9, 1, 0, "비밀번호");
			box(0, 15, 9, 1, 1, " 로그인");
			box(0, 20, 9, 1, 0, " 나가기");
			break;
		case BACK:
			box(12, 5, 25, 1, 0, data.id);
			box(12, 10, 25, 1, 0, hiding_password[p_length]);
			box(0, 5, 9, 1, 0, " 아이디");
			box(0, 10, 9, 1, 0, "비밀번호");
			box(0, 15, 9, 1, 0, " 로그인");
			box(0, 20, 9, 1, 1, " 나가기");
			break;
		}
		key = getch();
		switch (key) {
		case UP:
			if (infomenu > ID)
				infomenu--;
			break;
		case DOWN:
			if (infomenu < BACK)
				infomenu++;
			break;
		case ENTER:
			switch (infomenu) {
			case ID:
				box(12, 5, 25, 1, 0, "");		// 아이디 다시 입력받기 위해 써져있던 거 지우기
				gotoxy(14, 6);
				CursorView(1);
				my_gets(data.id, LETTER_LIMIT);
				CursorView(0);
				break;
			case PASSWORD:
				box(12, 10, 25, 1, 0, "");		// 비밀번호 다시 입력받기 위해 써져있던 거 지우기
				gotoxy(14, 11);
				CursorView(1);
				i = 0;
				while ((key2 = getch()) != ENTER)
				{
					if (key2 == BACKSPACE && i > 0)		// backspace
					{
						i--;
						printf("\b\b");
						printf("  ");
						printf("\b\b");
						continue;
					}
					else if (i >= LETTER_LIMIT - 1)
						continue;
					else if (isprint(key2))		// 프린트 가능한 문자만 받는다.
					{
						data.password[i++] = key2;
						printf("●");
					}
				}
				data.password[i] = '\0';
				p_length = strlen(data.password);
				CursorView(0);
				break;
			case MAKE:
				p_file = fopen("informations.dat", "rb");
				fseek(p_file, 0, SEEK_SET);
				while (feof(p_file) == 0) {
					fread(&information, sizeof(information), 1, p_file);
					if (strcmp(data.id, information.id) == 0 && strcmp(data.password, information.password) == 0)
					{
						information.onoff = 1;
						end = 1;
						success = 1;
						break;
					}
				}
				fclose(p_file);		// 파일 스트림 반납
				break;
			case BACK:
				end = 1;
				break;
			}
			break;
		default:
			break;
		}
	}
	if (!success) information.onoff = 0;
	return information;
}

void signup()
{
	FILE* p_file;
	int i;			// 반복문 제어 변수
	int key;		// 키보드 입력 값
	int end = 0;
	int wrong_id = 1;
	int wrong_password = 1;
	Infomenu infomenu = ID;
	Information information = {
			NULL, NULL, 0 };
	
	do {
		p_file = fopen("informations.dat", "ab+");
	} while (p_file == NULL);

	system("cls");		// 지금 상태에서는 처음에 한번만 지워도 됨. 나중에 문제가 될 수도 있음
	while (end == 0) {
		switch (infomenu) {
		case ID:
			box(12, 5, 25, 1, 0, information.id);
			box(12, 10, 25, 1, 0, information.password);
			box(0, 5, 9, 1, 1, " 아이디");
			box(0, 10, 9, 1, 0, "비밀번호");
			box(0, 15, 9, 1, 0, "계정생성");
			box(0, 20, 9, 1, 0, " 나가기");
			break;
		case PASSWORD:
			box(12, 5, 25, 1, 0, information.id);
			box(12, 10, 25, 1, 0, information.password);
			box(0, 5, 9, 1, 0, " 아이디");
			box(0, 10, 9, 1, 1, "비밀번호");
			box(0, 15, 9, 1, 0, "계정생성");
			box(0, 20, 9, 1, 0, " 나가기");
			break;
		case MAKE:
			box(12, 5, 25, 1, 0, information.id);
			box(12, 10, 25, 1, 0, information.password);
			box(0, 5, 9, 1, 0, " 아이디");
			box(0, 10, 9, 1, 0, "비밀번호");
			box(0, 15, 9, 1, 1, "계정생성");
			box(0, 20, 9, 1, 0, " 나가기");
			break;
		case BACK:
			box(12, 5, 25, 1, 0, information.id);
			box(12, 10, 25, 1, 0, information.password);
			box(0, 5, 9, 1, 0, " 아이디");
			box(0, 10, 9, 1, 0, "비밀번호");
			box(0, 15, 9, 1, 0, "계정생성");
			box(0, 20, 9, 1, 1, " 나가기");
			break;
		}
		key = getch();
		switch (key) {
		case UP:
			if (infomenu > ID)
				infomenu--;
			break;
		case DOWN:
			if (infomenu < BACK)
				infomenu++;
			break;
		case ENTER:
			switch (infomenu) {
			case ID:
				box(12, 5, 25, 1, 0, "");
				gotoxy(14, 6);
				CursorView(1);
				if (!my_gets(information.id, LETTER_LIMIT)) {
					box(12, 15, 25, 1, 0, "between 1 to 9");
					Sleep(1000);
					wrong_id = 1;
				}
				else wrong_id = 0;
				CursorView(0);
				break;
			case PASSWORD:
				box(12, 10, 25, 1, 0, "");
				gotoxy(14, 11);
				CursorView(1);
				if (!my_gets(information.password, LETTER_LIMIT)) {
					box(12, 15, 25, 1, 0, "between 1 to 9");
					Sleep(1000);
					wrong_password = 1;
				}
				else wrong_password = 0;
				CursorView(0);
				break;
			case MAKE:
				if (wrong_password + wrong_id != 0) {
					box(12, 15, 25, 1, 0, "wrong type!");
					Sleep(1000);
				}
				else if (search_id(&information)) {
					box(12, 15, 25, 1, 0, "existing id!");
					Sleep(1000);
				}
				else {
					information.onoff = 0;
					fwrite(&information, sizeof(information), 1, p_file);
					end = 1;
				}
				break;
			case BACK:
				end = 1;
				break;
			}
			break;
		default:
			break;
		}
	}

	int t = fclose(p_file);
	return 0;
}

void init_tetromino(Tetromino* tetp)
{
	// 테트로미노 색
	tetp[0].t_color = 14;
	tetp[1].t_color = 11;
	tetp[2].t_color = 12;
	tetp[3].t_color = 10;
	tetp[4].t_color = 6;
	tetp[5].t_color = 9;
	tetp[6].t_color = 13;

	// 테트리미노마다 센터블록에 대한 나머지 블록의 상대적좌표
	tetp[0].block[0].X = 1, tetp[0].block[0].Y = 0;
	tetp[0].block[1].X = 0, tetp[0].block[1].Y = -1;
	tetp[0].block[2].X = 1, tetp[0].block[2].Y = -1;

	tetp[1].block[0].X = 0, tetp[1].block[0].Y = 1;
	tetp[1].block[1].X = 0, tetp[1].block[1].Y = -1;
	tetp[1].block[2].X = 0, tetp[1].block[2].Y = 2;

	tetp[2].block[0].X = -1, tetp[2].block[0].Y = 0;
	tetp[2].block[1].X = 0, tetp[2].block[1].Y = -1;
	tetp[2].block[2].X = 1, tetp[2].block[2].Y = -1;

	tetp[3].block[0].X = -1, tetp[3].block[0].Y = 0;
	tetp[3].block[1].X = 0, tetp[3].block[1].Y = 1;
	tetp[3].block[2].X = 1, tetp[3].block[2].Y = 1;

	tetp[4].block[0].X = -1, tetp[4].block[0].Y = 0;
	tetp[4].block[1].X = 0, tetp[4].block[1].Y = -1;
	tetp[4].block[2].X = 0, tetp[4].block[2].Y = -2;

	tetp[5].block[0].X = 1, tetp[5].block[0].Y = 0;
	tetp[5].block[1].X = 0, tetp[5].block[1].Y = -1;
	tetp[5].block[2].X = 0, tetp[5].block[2].Y = -2;

	tetp[6].block[0].X = -1, tetp[6].block[0].Y = 0;
	tetp[6].block[1].X = 0, tetp[6].block[1].Y = 1;
	tetp[6].block[2].X = 1, tetp[6].block[2].Y = 0;

	return;
}

void print_tetromino(Tetromino* tetp)
{
	gotoxy(tetp->center.X * 2, tetp->center.Y);
	color(tetp->t_color, B);
	printf("▩");

	for (int i = 0; i < 3; i++)
	{
		gotoxy((tetp->block[i].X + tetp->center.X) * 2, tetp->block[i].Y + tetp->center.Y);
		printf("▩");
	}
	color(C, B);
	return;
}

void rotate_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	short x, y;
	int i;
	int count = 0;

	for (i = 0; i < 3; i++)
	{
		x = tetp->center.X - tetp->block[i].Y;
		y = tetp->center.Y + tetp->block[i].X;
		if (grid[y][x].situation == 1)
			count++;
	}
	if (count == 0) 
		for (i = 0; i < 3; i++) {
			tetp->block[i].Y *= -1;
			SWAP(short, tetp->block[i].X, tetp->block[i].Y);
		}
}

void erase_tetromino(Tetromino* tetp)
{
	gotoxy(tetp->center.X * 2, tetp->center.Y);
	printf("  ");

	for (int i = 0; i < 3; i++)
	{
		gotoxy((tetp->block[i].X + tetp->center.X) * 2, tetp->block[i].Y + tetp->center.Y);
		printf("  ");
	}
}

int down_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	if (grid[tetp->center.Y + 1][tetp->center.X].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y + 1][tetp->center.X + tetp->block[0].X].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y + 1][tetp->center.X + tetp->block[1].X].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y + 1][tetp->center.X + tetp->block[2].X].situation == 0
		) {
		tetp->center.Y++;
		return 1;		// 내리기 성공
	}
	else
		return 0;		// 내리기 실패
}

int right_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	if (grid[tetp->center.Y][tetp->center.X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X + 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X + 1].situation == 0
		) {
		tetp->center.X++;
		return 1;		// 오른쪽 이동 성공
	}
	else
		return 0;		// 오른쪽 이동 실패
}

int left_tetromino(Tetris grid[][12], Tetromino* tetp)
{
	if (grid[tetp->center.Y][tetp->center.X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X - 1].situation == 0
		&& grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X - 1].situation == 0
		) {
		tetp->center.X--;
		return 1;		// 왼쪽 이동 성공
	}
	else
		return 0;		// 왼쪽 이동 실패
}

void set_grid(Tetris grid[][12], Tetromino* tetp)		// 테트로미노가 다 내려가 고정되면 격자의 그 부분의 situation을 1로
{
	grid[tetp->center.Y][tetp->center.X].situation = 1;
	grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X].situation = 1;
	grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X].situation = 1;
	grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X].situation = 1;
	grid[tetp->center.Y][tetp->center.X].t_color = tetp->t_color;
	grid[tetp->center.Y + tetp->block[0].Y][tetp->center.X + tetp->block[0].X].t_color = tetp->t_color;
	grid[tetp->center.Y + tetp->block[1].Y][tetp->center.X + tetp->block[1].X].t_color = tetp->t_color;
	grid[tetp->center.Y + tetp->block[2].Y][tetp->center.X + tetp->block[2].X].t_color = tetp->t_color;

	return;
}

char check_grid(Tetris grid[][12])		// 격자상태를 체크해서 완성된 줄이 있으면 그 줄을 없애고 내림. 반환값은 없앤 줄의 개수
{
	char result = 0;
	int i, j, k, l;
	char count = 0;

	for (i = 1; i <= 20; i++)
	{
		for (j = 1; j <= 10; j++)
			if (grid[i][j].situation)		// 채워져있으면
				count++;
		if (count == 10)		// 모두 채워져 있으면 
		{
			for (k = i; k >= 1; k--)
				for (l = 1; l <= 10; l++)
					grid[k][l] = grid[k - 1][l];		// 아래칸의 정보를 위칸으로 바꿈
			result++;
		}
		count = 0;
	}

	draw_grid(grid);
	return result;
}

void draw_grid(Tetris grid[][12])		// 고정된 테트로미노들 그리기
{
	int i, j;

	for (i = 1; i <= 20; i++)
		for (j = 1; j <= 10; j++)
		{
			gotoxy(j * 2, i);
			if (grid[i][j].situation) {
				color(grid[i][j].t_color, B);
				printf("▩");
				color(C, B);
			}
			else
				printf("  ");

		}

	return;
}

char is_overlap(Tetris grid[][12], Tetromino* tetp)		// 테트로미노가 고정된 자리와 겹쳐있는가 -> 게임이 끝났는지 판정
{
	if (grid[tetp->center.Y][tetp->center.X].situation)
		return 1;
	for (int i = 0; i < 3; i++)
		if (grid[tetp->center.Y + tetp->block[i].Y][tetp->center.X + tetp->block[i].X].situation)
			return 1;

	return 0;
}

int add_record(Record *record, Mode mode)							// 기록 추가함수
{
	FILE* fp1, * fp2;
	Record buffer;
	int count = 1;
	int result;			// 기록의 인덱스(반환값)
	char flag = 1;

	if (record->score == 0) return 0;

	switch (mode) {
	case EASY:
		fp1 = fopen("easyrecords.dat", "rb");
		break;
	case NORMAL:
		fp1 = fopen("normalrecords.dat", "rb");
		break;
	case HARD:
		fp1 = fopen("hardrecords.dat", "rb");
		break;
	}

	if (fp1 == NULL)
		fprintf(stderr, "records.dat 파일 열기 실패 /n");


	fp2 = fopen("temp.dat", "wb");
	if (fp2 == NULL)
		fprintf(stderr, "temp.dat 파일 열기 실패 /n");


	while (fread(&buffer, sizeof(Record), 1, fp1))
	{
		if (flag && record->score > buffer.score)
		{
			fwrite(record, sizeof(Record), 1, fp2);
			result = count;
			flag = 0;
		}
		fwrite(&buffer, sizeof(Record), 1, fp2);
		count++;
	}

	if (flag)		// 기록이 꼴지라면
	{
		fwrite(record, sizeof(Record), 1, fp2);
		result = count;
	}

	fclose(fp1);
	fclose(fp2);

	switch (mode) {
	case EASY:
		remove("easyrecords.dat");
		rename("temp.dat", "easyrecords.dat");
		break;
	case NORMAL:
		remove("normalrecords.dat");
		rename("temp.dat", "normalrecords.dat");
		break;
	case HARD:
		remove("hardrecords.dat");
		rename("temp.dat", "hardrecords.dat");
		break;
	}

	return result;
}

void remove_record(const char id[])							// 기록 삭제 함수
{
	FILE* fp1, * fp2, * fp3, * fp4;
	Record buffer;

	fp1 = fopen("easyrecords.dat", "rb+");
	fp2 = fopen("normalrecords.dat", "rb+");
	fp3 = fopen("hardrecords.dat", "rb+");


	if (fp1 == NULL)
		fprintf(stderr, "records.dat 파일 열기 실패 /n");
	fp4 = fopen("temp.dat", "wb");
	if (fp4 == NULL)
		fprintf(stderr, "temp.dat 파일 열기 실패 /n");


	while (fread(&buffer, sizeof(Record), 1, fp1))
	{
		if (strcmp(buffer.id, id) == 0)
			continue;
		fwrite(&buffer, sizeof(Record), 1, fp4);
	}
	fclose(fp1);
	fclose(fp4);
	remove("easyrecords.dat");
	rename("temp.dat", "easyrecords.dat");

	fp4 = fopen("temp.dat", "wb");
	while (fread(&buffer, sizeof(Record), 1, fp2))
	{
		if (strcmp(buffer.id, id) == 0)
			continue;
		fwrite(&buffer, sizeof(Record), 1, fp4);
	}
	fclose(fp2);
	fclose(fp4);
	remove("normalrecords.dat");
	rename("temp.dat", "normalrecords.dat");

	fp4 = fopen("temp.dat", "wb");
	while (fread(&buffer, sizeof(Record), 1, fp3))
	{
		if (strcmp(buffer.id, id) == 0)
			continue;
		fwrite(&buffer, sizeof(Record), 1, fp4);
	}
	fclose(fp3);
	fclose(fp4);
	remove("hardrecords.dat");
	rename("temp.dat", "hardrecords.dat");


	return;
}

void remove_account(Information* information)
{
	if (strcmp(information->id, "admin") == 0) return;
	FILE* fp1; 
	FILE* fp2; 
	Information buffer;
	while (!(fp1 = fopen("informations.dat", "rb+")));			// 파일이 안 열릴 때가 있어서 이렇게 해줘야 함
	while (!(fp2 = fopen("temp.dat", "wb+")));
	fseek(fp1, 0, SEEK_SET);
	while (1) {
		fread(&buffer, sizeof(Information), 1, fp1);
		if (feof(fp1)) break;					// 이상한 거 읽는거 방지
		if (strcmp(information->id, buffer.id) == 0 && strcmp(information->password, buffer.password) == 0) {
			continue;
		}
		fwrite(&buffer, sizeof(Information), 1, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	remove("informations.dat");
	rename("temp.dat", "informations.dat");

	return;
}

void add_account(Information* information)
{
	FILE* fp = fopen("informations.dat", "ab");

	fwrite(information, sizeof(Information), 1, fp);

	fclose(fp);

	return;
}

void replace_account(Information* information)
{
	FILE* fp;
	Information buffer;
	char idx = search_id(information);
	if (!(fp = fopen("informations.dat", "rb+"))) {
		fprintf(stderr, "informations.dat 파일을 열 수 없습니다.");
		return;
	}
	fseek(fp, (idx - 1) * sizeof(Information), SEEK_SET);
	fwrite(information, sizeof(Information), 1, fp);
	fclose(fp);
	return;
}

char search_id(Information* information)
{
	FILE* fp = fopen("informations.dat", "rb");
	Information buffer;
	char search = 0;
	char count = 0;

	fseek(fp, 0, SEEK_SET);
	while (!feof(fp)) {
		fread(&buffer, sizeof(Information), 1, fp);
		count++;
		if (strcmp(information->id, buffer.id) == 0) {
			search = count;
			break;
		}
	}
	fclose(fp);
	return search;
}

void print_record(Mode mode)
{
	Record temp;
	FILE* fp;
	int i;

	box(0, 0, 37, 23, 0, "기록순위");
	gotoxy(2, 3);
	printf("%s%10s%5s%-10s", "Rank", "Score", " ", "Player");

	switch (mode) {
	case EASY:
		fp = fopen("easyrecords.dat", "rb+");
		break;
	case NORMAL:
		fp = fopen("normalrecords.dat", "rb+");
		break;
	case HARD:
		fp = fopen("hardrecords.dat", "rb+");
		break;
	}

	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < 20; i++)
	{
		if (fread(&temp, sizeof(Record), 1, fp) == NULL)
			break;
		gotoxy(2, 4 + i);
		printf("%2d등%10d%5s%-10s", i + 1, temp.score, " ", temp.id);
	}
	fclose(fp);
}