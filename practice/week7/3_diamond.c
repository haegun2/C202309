#include <stdio.h>

void drawDia();

int floor = -1;


int main() {
	
	printf("�� ���� �װڽ��ϱ�? (5 ~ 15): ");
	scanf_s("%d", &floor);

	if (floor < 5 || floor > 15) {
		printf("�� ���� ������ ������ϴ�. �����մϴ�.");
	}
	else {
		// TODO1: �Ƕ�̵� ��� �ڵ� ��� �ۼ�
		// TODO2: �ڵ� ��� �Լ�ȭ
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
		// TODO1: ���Ƕ�̵� ��� �ڵ� ��� �ۼ�
		// TODO2: �ڵ� ��� �Լ�ȭ
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