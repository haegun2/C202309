#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct StuInfo {
	char* name;
	int score;
};
void ClassifyStudents(struct StuInfo* student, char targetGrade, int student_number);
int SumScores(struct StuInfo* student, int student_number);
double AverageScores(struct StuInfo* student, int student_number);
void PrintRanks(struct StuInfo* student, int student_number);
void InitializeStuInfo(struct StuInfo* info);

int main() {
	int num_student;

	printf("학생 수가 몇명인가요?: ");
	scanf_s("%d", &num_student);

	struct StuInfo* how_many = (struct StuInfo*)malloc(num_student * sizeof(struct StuInfo));
	if (num_student == NULL) { return 1; }

	for (int i = 0; i < num_student; i++) {InitializeStuInfo(&how_many[i]);}
	getchar();


	char target;
	printf("특정 점수(A, B, C, D, F)를 입력하시오: ");
	scanf_s("%c", &target, 1);//입력받은 값을 변수 target에 저장/ 뒤의 숫자 1은 문자 값 char 의 크기를 적음
	//점수 영어를 입력하면 누가 그걸 받았는지 알려주는 함수로 이동
	ClassifyStudents(how_many, target, num_student);


	//성적 합과 평균을 함수를 통해 리턴 받고 그것을 출력하는 내용
	int sum = SumScores(how_many, num_student);
	double average = AverageScores(how_many, num_student);
	printf("학생들의 점수의 총 합은 %d 이고, 평균 값은 %lf입니다.\n", sum, average);


	//학생별 성적 순위를 출력하는 함수
	PrintRanks(how_many, num_student);


	//할당 메모리 해제
	for (int i = 0; i < num_student; i++) {free(how_many[i].name);}
	free(how_many);
	return 0;
}

//학생 성적을 분류하는 함수
void ClassifyStudents(struct StuInfo* student, char targetGrade, int student_number) {
	printf("학생 성적 분류: \n");
	char grade = ' ';
	//학생의 성적을 조건문으로 기입
	for (int i = 0; i < student_number; i++) {
		if (student[i].score >= 90) {
			grade = 'A';
		}
		else if (student[i].score >= 80) {
			grade = 'B';
		}
		else if (student[i].score >= 70) {
			grade = 'C';
		}
		else if (student[i].score >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
		//학생의 성적이 입력받은 타겟값과 같으면 아래 문구를 출력
		if (targetGrade == grade) {
			printf("%s 학생은 %c 점수를 받았습니다.\n", student[i].name, targetGrade);
		}
	}
}

//학생 성적의 총합을 구하는 함수
int SumScores(struct StuInfo* student, int student_number) {
	int sum = 0;
	for (int i = 0; i < student_number; i++) {
		sum += student[i].score;
	}
	return sum;
}

//학생 성적의 평균을 구하는 함수
double AverageScores(struct StuInfo* student, int student_number) {
	//합 함수에서 값을 가져와 평균을 구하고 평균값을 리턴
	double average = (double)SumScores(student, student_number) / (double)student_number;
	return average;
}

//각 학생의 순위를 출력하는 함수
void PrintRanks(struct StuInfo* student, int student_number) {
	for (int i = 0; i < student_number; i++) {
		int gradeList = student_number;
		//학생들을 for문을 통해 순차적으로 출력하는데, 순차적으로 학생의 값을 scorelist 값에 넣고
		int scorelist = student[i].score;
		//5위부터 시작하면서 각각의 값을 모두 비교했을때 자기가 더 크면 gradeList 변수값을 하나씩 줄이게 설정 
		for (int j = 0; j < student_number; j++) {
			if (scorelist > student[j].score) {
				gradeList--;
			}
		}
		// 이후 학생의순서와 순위를 출력!!
		printf("%s 학생의 순위는 %d 입니다.\n", student[i].name, gradeList);
	}
}

//구조체로 입력받는 함수
void InitializeStuInfo(struct StuInfo* info) {
	printf("학생 이름을 입력하세요: ");
	char temp[100];
	scanf_s("%s", temp, (int)(sizeof(temp)));
	info->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(info->name, strlen(temp) + 1, temp);

	printf("학생의 성적을 입력하세요: ");
	scanf_s("%d", &info->score);
}