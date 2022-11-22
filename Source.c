#include <stdio.h>
#include <time.h> // 세탁기 작동시간은 50분이니 (1)50분 카운트다운 (2)현재시간 + 50분해서 작동종료시간 표기, 참조링크 https://url.kr/idm58x
#include <windows.h>
#include <conio.h> // 방향키 입력 받는 헤더파일, 참조링크 https://url.kr/8rk6ng, 네이버 블로그
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int main(void) {
	int num;
	char select;

	// 방향키로 메뉴 입력을 받는게 좋을 것 같음, 우선 번호입력 / 방향키 입력폼을 두개다 해둠.
	printf("■■■■■■■■■■■■■■■■■\n");
	printf("■                              ■\n");
	printf("■     이용시설 현황 시스템     ■\n");
	printf("■   (1)세탁기 이용현황 조회    ■\n");
	printf("■   (2)세탁기 이용현황 등록    ■\n");
	printf("■                              ■\n");
	printf("■ (←)이용현황 조회            ■\n");
	printf("■            이용현황 등록(→) ■\n");
	printf("■      방향키를 통해 선택      ■\n");
	printf("■                              ■\n");
	printf("■■■■■■■■■■■■■■■■■\n");

	/* printf("선택 : ");
	scanf_s("%d", &num);
	
	switch (num) {
	case 1:
		inquiry();
		break;
	case 2:
		registeration();
		break;
	}  */

	while (1) {
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
}

int inquiry() { //조회
	system("cls");
	printf("이용시설 현황 조회을 선택하셨습니다.\n");
	
	Sleep(1000);
	system("cls");
	

	return 0; 
}

int registeration() { //등록
	system("cls");
	printf("이용시설 현황 등록을 선택하셨습니다.\n");
	
	Sleep(1000);
	system("cls");


	return 0;
}
