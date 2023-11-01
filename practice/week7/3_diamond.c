#include <stdio.h>

void drawDia();

int floor = -1;


int main() {
	
	printf("몇 층을 쌓겠습니까? (5 ~ 15): ");
	scanf_s("%d", &floor);

	if (floor < 5 || floor > 15) {
		printf("층 수가 범위를 벗어났습니다. 종료합니다.");
	}
	else {
		// TODO1: 피라미드 출력 코드 블록 작성
		// TODO2: 코드 블록 함수화
		drawDia();
		return 0;
	}
}

void drawDia() {
	for (int i = 0; i < floor; i++) {
		for (int j = 0; j < floor - 1 - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("%d", i % 10);
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
		// TODO1: 역피라미드 출력 코드 블록 작성
		// TODO2: 코드 블록 함수화
	}
	for (int i = floor; i > 0; i--) {
		for (int j = 0; j < floor - i; j++) {
			printf(" ");
		}
		for (int k = 0; k < i - 1; k++) {
			printf("*");
		}
		printf("%d", i % 10);
		for (int k = 0; k < i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}