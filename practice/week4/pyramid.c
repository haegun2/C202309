#include <stdio.h>

int main() {
	int floor, i, j, k ;
	printf("�� ���� �װڽ��ϱ�?(5~100)");
	scanf_s("%d", &floor);

	for (i = 1; i <= floor; i++) { //1���ͽ����̶� floor ���� �������� i<=floor
		for (j = 0; j < floor - i; j++) { //S�� ������ ������ - i
			printf("S");
		}
		for (k = 0; k < i * 2 - 1; k++) { //*�� 1,3,5,7 �̷��� ������ Ȧ����. i�� 1�����̴� k = i*2-1
			printf("*");
		}
		printf("\n");
	}
	return 0;
}