#include <stdio.h>

int main() {
	int carType = -1; // 차량 종류 입력받는 변수
	int parkingTime = -1; // 주차한 시간을 입력받는 변수
	int parkingPrice = -1; // 주차 요금 저장을 위한 변수

	printf("<주차 요금 계산 시스템>\n");
	printf("자전거: 500원/시간\n");
	printf("오토바이: 1000원/시간\n");
	printf("자동차: 2000원/시간\n");
	printf("-------------------------\n");
	printf("차량 종류를 입력하세요 (1. 자전거, 2.오토바이, 3. 자동차): ");
	scanf_s("%d", &carType);

	printf("주차 시간을 입력하세요 (단위: 시간): ");
	scanf_s("%d", &parkingTime);

	if (carType == 1) {
		parkingPrice = 500 * parkingTime;
	}
	else if (carType == 2){
		parkingPrice = 1000 * parkingTime;
	}
	else if (carType == 3) {
		parkingPrice = 2000 * parkingTime;
	}
	else if (carType != 1) {
		carType = -1;
	}
	else if (carType != 2) {
		carType = -1;
	}
	else if (carType != 3) {
		carType = -1;
	}

	if (parkingPrice == -1) {
		printf("잘못된 차량 유형이기 때문에, 주차요금을 계산할 수 없습니다. \n");
	}
	else {
		printf("최종 주차 요금: %d", parkingPrice);
	}

	return 0;
}