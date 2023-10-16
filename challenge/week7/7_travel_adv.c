#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

//위에서 상수로 도시 수와, 사람 수를 지정한것을 반영한 변수 name과, cities를 2*10의 2차원배열로 생성
char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

//함수원형 선언
void calculateTravelDays();
int getSum(int numArray[]);
double getAverage(int numArray[]);
void getFamousCity();

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
	//평균 며칠 있었는지 확인할 배열을 생성
	double averageDays[NUMCITY];

	//i가 증가하는 반복문
	for (int i = 0; i < NUMCITY; i++) {
		//토탈데이즈는 함수 getSum인데 들어가는 값은 travelDays의 i와 총 사람이 몇명인지
		int totalDay = getSum(travelDays[i]);
		double averageDay = getAverage(travelDays[i]);
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2d\n", cities[i], totalDay, averageDays);
		averageDays[i] = averageDay;
	}
	getFamousCity(averageDays);
}

//getSum 함수에 들어간 값의 종류는 배열과, 범위를 알려줄 int값 총 사람이 들어간 이유는 for문때문
int getSum(int numArray[]) {
	int totalDays = 0;
	for (int i = 0; i < NUMPEOPLE; i++) {
		totalDays += numArray[i];
	}
	return totalDays;
}

double getAverage(int numArray[]){
	int totalDays = 0;
	for (int i = 0; i < NUMPEOPLE; i++) {
		totalDays += numArray[i];
	}
	double averageDays = (double)totalDays / NUMPEOPLE;

	return averageDays;
}///평균에서인지 이상한 값이 출력되어 수정할 예정

void getFamousCity(double dayArray[]) {
	double maxDay = 0;
	int maxDayIndex = 0;
	for (int i = 0; i < NUMPEOPLE; i++) {
		if (dayArray[i] > maxDay) {
			maxDay = dayArray[i];
			maxDayIndex = i;
		}
	}
	printf("평균일 기준으로 가장 인기있었던 도시는 %s 입니다. (평균머문일: %.2f)\n", cities[maxDayIndex], maxDay);
}