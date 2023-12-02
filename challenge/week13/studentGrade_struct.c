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

	printf("�л� ���� ����ΰ���?: ");
	scanf_s("%d", &num_student);

	struct StuInfo* how_many = (struct StuInfo*)malloc(num_student * sizeof(struct StuInfo));
	if (num_student == NULL) { return 1; }

	for (int i = 0; i < num_student; i++) {InitializeStuInfo(&how_many[i]);}
	getchar();


	char target;
	printf("Ư�� ����(A, B, C, D, F)�� �Է��Ͻÿ�: ");
	scanf_s("%c", &target, 1);//�Է¹��� ���� ���� target�� ����/ ���� ���� 1�� ���� �� char �� ũ�⸦ ����
	//���� ��� �Է��ϸ� ���� �װ� �޾Ҵ��� �˷��ִ� �Լ��� �̵�
	ClassifyStudents(how_many, target, num_student);


	//���� �հ� ����� �Լ��� ���� ���� �ް� �װ��� ����ϴ� ����
	int sum = SumScores(how_many, num_student);
	double average = AverageScores(how_many, num_student);
	printf("�л����� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);


	//�л��� ���� ������ ����ϴ� �Լ�
	PrintRanks(how_many, num_student);


	//�Ҵ� �޸� ����
	for (int i = 0; i < num_student; i++) {free(how_many[i].name);}
	free(how_many);
	return 0;
}

//�л� ������ �з��ϴ� �Լ�
void ClassifyStudents(struct StuInfo* student, char targetGrade, int student_number) {
	printf("�л� ���� �з�: \n");
	char grade = ' ';
	//�л��� ������ ���ǹ����� ����
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
		//�л��� ������ �Է¹��� Ÿ�ٰ��� ������ �Ʒ� ������ ���
		if (targetGrade == grade) {
			printf("%s �л��� %c ������ �޾ҽ��ϴ�.\n", student[i].name, targetGrade);
		}
	}
}

//�л� ������ ������ ���ϴ� �Լ�
int SumScores(struct StuInfo* student, int student_number) {
	int sum = 0;
	for (int i = 0; i < student_number; i++) {
		sum += student[i].score;
	}
	return sum;
}

//�л� ������ ����� ���ϴ� �Լ�
double AverageScores(struct StuInfo* student, int student_number) {
	//�� �Լ����� ���� ������ ����� ���ϰ� ��հ��� ����
	double average = (double)SumScores(student, student_number) / (double)student_number;
	return average;
}

//�� �л��� ������ ����ϴ� �Լ�
void PrintRanks(struct StuInfo* student, int student_number) {
	for (int i = 0; i < student_number; i++) {
		int gradeList = student_number;
		//�л����� for���� ���� ���������� ����ϴµ�, ���������� �л��� ���� scorelist ���� �ְ�
		int scorelist = student[i].score;
		//5������ �����ϸ鼭 ������ ���� ��� �������� �ڱⰡ �� ũ�� gradeList �������� �ϳ��� ���̰� ���� 
		for (int j = 0; j < student_number; j++) {
			if (scorelist > student[j].score) {
				gradeList--;
			}
		}
		// ���� �л��Ǽ����� ������ ���!!
		printf("%s �л��� ������ %d �Դϴ�.\n", student[i].name, gradeList);
	}
}

//����ü�� �Է¹޴� �Լ�
void InitializeStuInfo(struct StuInfo* info) {
	printf("�л� �̸��� �Է��ϼ���: ");
	char temp[100];
	scanf_s("%s", temp, (int)(sizeof(temp)));
	info->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(info->name, strlen(temp) + 1, temp);

	printf("�л��� ������ �Է��ϼ���: ");
	scanf_s("%d", &info->score);
}