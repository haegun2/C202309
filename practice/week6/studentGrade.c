#include<stdio.h>
#define STUDENTS 5

void classifyStudents(int scores[], char targetGrade) {
	printf("학생 성적 분류: \n");
	char grade = ' ';
	//학생의 성적을 조건문으로 기입
	for (int i = 0; i < STUDENTS; i++) {
		if (scores[i] >= 90) {
			grade = 'A';
		}
		else if (scores[i] >= 80) {
			grade = 'B';
		}
		else if (scores[i] >= 70) {
			grade = 'C';
		}
		else if (scores[i] >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
		//학생의 성적이 입력받은 타겟값과 같으면 아래 문구를 출력
		if (targetGrade == grade) {
			printf("%d 학생은 %c 점수를 받았습니다.", i + 1, targetGrade);
		}
	}
}

int main() {
	int scores[STUDENTS];

	//1. 학생의 점수를 입력받기
	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i+1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar(); //버퍼 임시 저장 변수, 입력 중에 엔터를 지우는 역할

	char target;
	printf("특정 점수(A, B, C, D, F)를 입력하시오: ");
	scanf_s("%c", &target, 1); // 입력받은 값을 변수 target에 저장/ 뒤의 숫자 1은 문자 값 char 의 크기를 적음
	
	//2.점수 영어를 입력하면 누가 그걸 받았는지 알려주는 함수로 이동
	classifyStudents(scores, target);

	return 0;
}