#include <stdio.h>

int main() {
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
	case 2:
		registeration();
	}

	return 0;
}

int inquiry() {
	printf("Test message\n");

	return 0; 
}

int registeration() {
	printf("Test message\n");

	return 0;
}
