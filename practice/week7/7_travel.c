#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

//위에서 상수로 도시 수와, 사람 수를 지정한것을 반영한 변수 name과, cities를 2*10의 2차원배열로 생성
char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

//함수원형 선언
void calculateTravelDays();

int main() {

	//사용자로부터 도시입력을 받아 cities변수에 저장
	printf("%d개의 도시명을 차례대로 입력해주세요.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}

	//사용자로부터 여행자 이름을 입력받아 names 변수에 저장
	printf("%d개의 여행자 이름을 차례대로 입력해주세요.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	//함수 호출
	calculateTravelDays(names);

	return 0;
}

//여행일과 평균 일수를 계산하는 함수
void calculateTravelDays() {
	int travelDays[NUMCITY][NUMPEOPLE];

	//입력된 도시별로, 각자의 사람들이 보낸 일수를 입력하여 travelDays 배열에 저장
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", cities[i], names[j]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	// 각 도시별 총 일수 합산
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			totalDays += travelDays[i][j];
		}
		//각 도시별 평균일수 계산 후 출력
		float averageDays = (float)totalDays / NUMPEOPLE;
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f\n", cities[i], totalDays, averageDays);
	}
}
