#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h> // 세탁기 작동시간은 50분이니 종료시간 표시. 참조링크 https://url.kr/idm58x
#include <windows.h> 
#include <conio.h> // 방향키 입력 받는 헤더파일, 참조링크 https://url.kr/8rk6ng,
//_getch _kbhit 설명 <= https://url.kr/w5azx8 네이버 블로그
 //_getch를 통해 이중동작이 필요하지 않도록 함. 이는 사용자로 하여금 편의를 느끼게 해줌.
// 총 7층, 세탁기(50분) 3대, 건조기(50분) 1대
// esc 눌러서 프로그램 종료
/*	time_t timer;
    struct tm* t;
    timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
    t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

    printf("유닉스 타임 (Unix Time): %lld 초\n\n", timer);
    printf("현재 년: %d\n", t->tm_year + 1900);
    printf("현재 월: %d\n", t->tm_mon + 1);
    printf("현재 일: %d\n", t->tm_mday);
    printf("현재 시: %d\n", t->tm_hour);
    printf("현재 분: %d\n", t->tm_min);
    printf("현재 초: %d\n", t->tm_sec);
    printf("현재 요일: %d\n", t->tm_wday); // 일=0, 월=1, 화=2, 수=3, 목=4, 금=5, 토=6
    printf("올해 몇 번째 날: %d\n", t->tm_yday); // 1월 1일은 0, 1월 2일은 1
    printf("서머타임 적용 여부: %d\n", t->tm_isdst); // 실시 중이면 양수, 미실시면 0, 실시 정보가 없으면 음수*/

int floor, Userselect; //층 입력
int inquiry(); //조회
int registeration(); //등록

//("%d시 %d분 종료")를 담음
char A_1[30] = "             ", A_2[30] = "             ", A_3[30] = "             ", A_4[30] = "             ";
char B_1[30] = "             ", B_2[30] = "             ", B_3[30] = "             ", B_4[30] = "             ";
char C_1[30] = "             ", C_2[30] = "             ", C_3[30] = "             ", C_4[30] = "             ";

//(사용가능/사용중)을 담음
char *A_A = "사용가능", *A_B = "사용가능", *A_C = "사용가능", *A_D = "사용가능";
char *B_A = "사용가능", *B_B = "사용가능", *B_C = "사용가능", *B_D = "사용가능";
char *C_A = "사용가능", *C_B = "사용가능", *C_C = "사용가능", *C_D = "사용가능";

//프로그램 실행도중 커서가 표시되지 않도록 함
void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int esc_to_end() {

}

int main(void) {
	int num; // 메뉴선택을 위한 변수
	CursorView(0);
	while (1) {
		system("cls");
		printf("■■■■■■■■■■■■■■■■■\n");
		printf("■                              ■\n");
		printf("■     이용시설 현황 시스템     ■\n");
		printf("■   (1)세탁기 이용현황 조회    ■\n");
		printf("■   (2)세탁기 이용현황 등록    ■\n");
		printf("■                              ■\n");
		printf("■     번호입력을 통해 선택     ■\n");
		printf("■                              ■\n");
		printf("■■■■■■■■■■■■■■■■■\n");
	
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

int inquiry() { //조회
	CursorView(0);
	system("cls");
	printf("이용시설 현황 조회을 선택하셨습니다.\n");
	
	Sleep(1000);
	system("cls");
	
	printf("현황을 조회하실 층수를 입력하세요.(1~3층)\n");
	floor = _getch();

	system("cls");

	while (1) {
		switch (floor) {
		case '1':
			printf("┌────────────────────┐     ┌────────────────────┐    ┌────────────────────┐     ┌────────────────────┐\n");
			printf("│□ □ □ 세탁기1 □ │     │□ □ □ 세탁기2 ■ │    │□ □ □ 세탁기3 □ │     │□ □ □ 건조기4 ■ │\n");
			printf("├────────────────────┤     ├────────────────────┤    ├────────────────────┤     ├────────────────────┤\n");
			printf("│                    │     │                    │    │                    │     │                    │\n");
			printf("│                    │     │                    │    │                    │     │                    │\n");
			printf("│                    │     │                    │    │                    │     │                    │\n");
			printf("     %s              %s             %s              %s\n", A_1, A_2, A_3, A_4);
			printf("│                    │     │                    │    │                    │     │                    │\n");
			printf("│                    │     │                    │    │                    │     │                    │\n");
			printf("│                    │     │                    │    │                    │     │                    │\n");
			printf("└────────────────────┘     └────────────────────┘    └────────────────────┘     └────────────────────┘\n");
			Sleep(1500);
			break;

		case '2':
			printf("%c층", floor);
			Sleep(500);
			break;

		case '3':
			printf("%c층", floor);
			Sleep(500);
			break;

		default:
			break;
		}
		break;
	}
	return 0; 
}

int registeration() { //등록
		CursorView(0);
		time_t timer;
		struct tm* t;
		timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
		t = localtime(&timer); // 포맷팅을 위해 구조체에 넣기

		system("cls");
		printf("이용시설 현황 등록을 선택하셨습니다.\n");

		Sleep(1000);
		system("cls");

		printf("이용하실 층을 선택해주세요(1~3).\n");
		floor = _getch();

		while (1) {
			switch (floor) {
			case '1': //1층
				system("cls");
				printf("%c층 사용 현황입니다.\n", floor);
				printf("┌────────────────────┐     ┌────────────────────┐    ┌────────────────────┐     ┌────────────────────┐\n");
				printf("│□ □ □ 세탁기1 □ │     │□ □ □ 세탁기2 ■ │    │□ □ □ 세탁기3 □ │     │□ □ □ 건조기4 ■ │\n");
				printf("├────────────────────┤     ├────────────────────┤    ├────────────────────┤     ├────────────────────┤\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("       %s                   %s                   %s                   %s\n",A_A, A_B, A_C, A_D);
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("└────────────────────┘     └────────────────────┘    └────────────────────┘     └────────────────────┘\n");
				printf("사용하실 시설의 번호를 입력해주세요(1~4).\n");
				Userselect = _getch();
				
				switch (Userselect) {
				case '1':
					A_A = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					int h = t->tm_hour;
					int m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}					
					sprintf(A_1, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '2':
					A_B = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(A_2, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '3':
					A_C = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(A_3, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;
				break;

				case '4':
					A_D = "사용중";
					system("cls");
					printf("%c번 건조기를 선택하셨습니다. 50분뒤에 건조가 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(A_4, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;
				default:
					break;
				}
				break;

			case '2': //2층
				system("cls");
				printf("%c층 사용 현황입니다.\n", floor);
				printf("┌────────────────────┐     ┌────────────────────┐    ┌────────────────────┐     ┌────────────────────┐\n");
				printf("│□ □ □ 세탁기1 □ │     │□ □ □ 세탁기2 ■ │    │□ □ □ 세탁기3 □ │     │□ □ □ 건조기4 ■ │\n");
				printf("├────────────────────┤     ├────────────────────┤    ├────────────────────┤     ├────────────────────┤\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("       %s                   %s                   %s                   %s\n", B_A, B_B, B_C, B_D);
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("└────────────────────┘     └────────────────────┘    └────────────────────┘     └────────────────────┘\n");
				printf("사용하실 시설의 번호를 입력해주세요(1~4).\n");
				Userselect = _getch();
				
				switch (Userselect) {
				case '1':
					B_A = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					int h = t->tm_hour;
					int m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(B_1, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '2':
					B_B = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(B_2, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '3':
					B_C = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(B_3, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '4':
					B_D = "사용중";
					system("cls");
					printf("%c번 건조기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(B_4, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				default:
					break;
				}
				break;
			
			case '3': //3층
				system("cls");
				printf("%c층 사용 현황입니다.\n", floor);
				printf("┌────────────────────┐     ┌────────────────────┐    ┌────────────────────┐     ┌────────────────────┐\n");
				printf("│□ □ □ 세탁기1 □ │     │□ □ □ 세탁기2 ■ │    │□ □ □ 세탁기3 □ │     │□ □ □ 건조기4 ■ │\n");
				printf("├────────────────────┤     ├────────────────────┤    ├────────────────────┤     ├────────────────────┤\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("       %s                   %s                   %s                   %s\n", C_A, C_B, C_C, C_D);
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("└────────────────────┘     └────────────────────┘    └────────────────────┘     └────────────────────┘\n");
				printf("사용하실 시설의 번호를 입력해주세요(1~4).\n");
				Userselect = _getch();
				
				switch (Userselect) {
				case '1':
					C_A = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					int h = t->tm_hour;
					int m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(C_1, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '2':
					C_B = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(C_2, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '3':
					C_C = "사용중";
					system("cls");
					printf("%c번 세탁기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(C_3, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				case '4':
					C_D = "사용중";
					system("cls");
					printf("%c번 건조기를 선택하셨습니다. 50분뒤에 세탁이 완료됩니다.", Userselect);
					h = t->tm_hour;
					m = t->tm_min + 50;
					if (m >= 60) {
						m -= 60;
						h += 1;
					}
					sprintf(C_4, "%d시 %d분 종료", h, m);
					Sleep(1500);
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}
			break;
		}
}

	/* 세탁기 모형
				printf("┌────────────────────┐     ┌────────────────────┐    ┌────────────────────┐     ┌────────────────────┐\n");
				printf("│□ □ □         □ │     │□ □ □         ■ │    │□ □ □         □ │     │□ □ □         ■ │\n");
				printf("├────────────────────┤     ├────────────────────┤    ├────────────────────┤     ├────────────────────┤\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("       %s                   %s                   %s                   %s\n", A_A, A_B, A_C, A_D);
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("│                    │     │                    │    │                    │     │                    │\n");
				printf("└────────────────────┘     └────────────────────┘    └────────────────────┘     └────────────────────┘\n");
	*/

	/*    int h = t->tm_hour;
	int m = t->tm_min + 50;
	if (m >= 60) {
		m -= 60;
		h += 1;
	}
	printf("%d시 %d분 종료", h, m);*/