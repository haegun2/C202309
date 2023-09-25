#include <stdio.h>

int main() {
	int floor, i, j, k ;
	printf("몇 층을 쌓겠습니까?(5~100)");
	scanf_s("%d", &floor);

	for (i = 1; i <= floor; i++) { //1부터시작이라서 floor 층을 쌓으려면 i<=floor
		for (j = 0; j < floor - i; j++) { //S의 갯수는 현재층 - i
			printf("S");
		}
		for (k = 0; k < i * 2 - 1; k++) { //*가 1,3,5,7 이렇게 나가니 홀수로. i가 1부터이니 k = i*2-1
			printf("*");
		}
		printf("\n");
	}
	return 0;
}