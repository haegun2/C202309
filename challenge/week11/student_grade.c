#include<stdio.h>
#define STUDENTS 5

void ClassifyStudents(int *scores, char targetGrade);
int SumScores(int *scores);
double AverageScores(int *scores);
void PrintRanks(int *scores);

int main() {
	int scores[STUDENTS];

	//1. 학생의 점수를 입력받기
	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i + 1);
		scanf_s("%d", (scores + i));
	}

	char ch = getchar(); //버퍼 임시 저장 변수, 입력 중에 엔터를 지우는 역할

	char target;
	printf("특정 점수(A, B, C, D, F)를 입력하시오: ");
	scanf_s("%c", &target, 1);//입력받은 값을 변수 target에 저장/ 뒤의 숫자 1은 문자 값 char 의 크기를 적음

	//2.점수 영어를 입력하면 누가 그걸 받았는지 알려주는 함수로 이동
	ClassifyStudents(scores, target);

	//3.성적 합과 평균을 함수를 통해 리턴 받고 그것을 출력하는 내용
	int sum = SumScores(scores);
	double average = AverageScores(scores);
	printf("학생들의 점수의 총 합은 %d 이고, 평균 값은 %lf입니다.\n", sum, average);

	//4. 학생별 성적 순위를 출력하는 함수
	PrintRanks(scores);

	return 0;
}

void ClassifyStudents(int* scores, char targetGrade) {
	printf("학생 성적 분류: \n");
	char grade = ' ';
	//학생의 성적을 조건문으로 기입
	for (int i = 0; i < STUDENTS; i++) {
		if (*(scores+i) >= 90) {
			grade = 'A';
		}
		else if (*(scores + i) >= 80) {
			grade = 'B';
		}
		else if (*(scores + i) >= 70) {
			grade = 'C';
		}
		else if (*(scores + i) >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
		//학생의 성적이 입력받은 타겟값과 같으면 아래 문구를 출력
		if (targetGrade == grade) {
			printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1, targetGrade);
		}
	}
}

int SumScores(int* scores) {
	int sum = 0;
	//for문을 통해 배열의 각 값을 합 변수에 지정하고 썸 변수는 모든 합을 더하여 리턴
	for (int i = 0; i < STUDENTS; i++) {
		int hap = *(scores + i);
		sum += hap;
	}
	return sum;
}

double AverageScores(int* scores) {
	//합 함수에서 값을 가져와 평균을 구하고 평균값을 리턴
	double average = (double)SumScores(scores) / (double)STUDENTS;
	return average;
}

void PrintRanks(int* scores) {
	//각 학생의 순위를 출력하는 함수
	for (int i = 0; i < STUDENTS; i++) {
		int gradeList = STUDENTS;
		//학생들을 for문을 통해 순차적으로 출력하는데, 순차적으로 학생의 값을 scorelist 값에 넣고
		int scorelist = *(scores + i);
		//5위부터 시작하면서 각각의 값을 모두 비교했을때 자기가 더 크면 gradeList 변수값을 하나씩 줄이게 설정 
		for (int j = 0; j < STUDENTS; j++) {
			if (scorelist > *(scores + j)) {
				gradeList--;
			}
		}
		// 이후 학생의순서와 순위를 출력!!
		printf("%d 학생의 순위는 %d 입니다.\n", i + 1, gradeList);
	}
}
