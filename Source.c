#include <stdio.h>
#include <time.h> // 세탁기 작동시간은 50분이니 50분뒤 종료시간 표시 참조링크 https://url.kr/idm58x
#include <windows.h> 
#include <conio.h> // 방향키 입력 받는 헤더파일, 참조링크 https://url.kr/8rk6ng, 
//_getch _kbhit 설명 <= https://url.kr/w5azx8 네이버 블로그
// 총 7층, 세탁기(50분) 3대, 건조기(50분) 1대
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
int floor;

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void fullscreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

int main(void) {
	int num; // 숫자 입력
	char select; // 방향키 입력
	fullscreen();
	CursorView(0);
	// 방향키로 메뉴 입력을 받는게 좋을 것 같음, 우선 번호입력 / 방향키 입력폼을 두개다 해둠.
	printf("■■■■■■■■■■■■■■■■■\n");
	printf("■                              ■\n");
	printf("■     이용시설 현황 시스템     ■\n");
	printf("■   (1)세탁기 이용현황 조회    ■\n");
	printf("■   (2)세탁기 이용현황 등록    ■\n");
	printf("■                              ■\n");
	printf("■     번호입력을 통해 선택     ■\n");
	printf("■                              ■\n");
	printf("■■■■■■■■■■■■■■■■■\n");

	
	while (1) {
		num = _getch();
		switch (num) {
		case '1':
			inquiry();
			break;
		case '2':
			registeration();
			break;
		default:
			break;
		}
	}
	return 0;
}
	/*while (1) {
		if (_kbhit()) {
			select = _getch();
			if (select == -32) {
				select = _getch();
				switch (select) {
				case LEFT:
					inquiry();
					break;
				case RIGHT:
					registeration();
					break;
				}
			}
		}
	}
	return 0;
}*/
	int inquiry() { //조회
	system("cls");
	printf("이용시설 현황 조회을 선택하셨습니다.\n");
	
	Sleep(1000);
	system("cls");
	
	printf("현황을 조회하실 층수를 입력하세요.(1~7층)\n");
	floor = _getch();
	
	switch (floor) {

	}
	return 0; 
}

	int registeration() { //등록
	system("cls");
	printf("이용시설 현황 등록을 선택하셨습니다.\n");
	
	Sleep(1000);
	system("cls");


	return 0;
}
