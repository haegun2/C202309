#include <stdio.h>

int main() {
	int floor;
	printf("몇 층을 쌓겠습니까? (5~100)");
	scanf_s("%d", &floor); //사용자의 입력을 받아서 변수 floor 로 저장

	for (int i = floor; i > 0; i--) { //현재 층은 ex 5면 5 4 3 2 1 으로 반복
		for (int j = 1; j <= floor-i; j++) { //층-i가 같거나 작은 j 값만큼 S를 출력
			printf("S");
		}
		for (int k = 1; k <= i*2-1; k++) {//i=현재층의 2배 -1 만큼 *을 출력 다음층이 될수록 i가 1씩 감소하여 거꾸로 피라미드가 된다
			printf("*");
		}
		printf("\n");//다음줄로 이송
	}
	return 0;
}