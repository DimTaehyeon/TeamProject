#include <stdio.h>
#include <time.h>
#include <windows.h>

int main(void) {
	int num;

	printf("■■■■■■■■■■■■■■■■■\n");
	printf("■                              ■\n");
	printf("■     이용시설 현황 시스템     ■\n");
	printf("■   (1)세탁기 이용현황 조회    ■\n");
	printf("■   (2)세탁기 이용현황 등록    ■\n");
	printf("■                              ■\n");
	printf("■■■■■■■■■■■■■■■■■\n");

	printf("선택 : ");
	scanf_s("%d", &num);

	switch (num) {
	case 1:
		inquiry();
		break;
	case 2:
		registeration();
		break;
	}

	return 0;
}

int inquiry() { //조회
	system("cls");
	printf("이용시설 현황 조회을 선택하셨습니다.\n");
	return 0; 
}

int registeration() { //등록
	system("cls");
	printf("이용시설 현황 등록을 선택하셨습니다.\n");

	return 0;
}
