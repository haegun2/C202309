#include<stdio.h>
#define STUDENTS 5

void ClassifyStudents(int *scores, char targetGrade);
int SumScores(int *scores);
double AverageScores(int *scores);
void PrintRanks(int *scores);

int main() {
	int scores[STUDENTS];

	//1. �л��� ������ �Է¹ޱ�
	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", (scores + i));
	}

	char ch = getchar(); //���� �ӽ� ���� ����, �Է� �߿� ���͸� ����� ����

	char target;
	printf("Ư�� ����(A, B, C, D, F)�� �Է��Ͻÿ�: ");
	scanf_s("%c", &target, 1);//�Է¹��� ���� ���� target�� ����/ ���� ���� 1�� ���� �� char �� ũ�⸦ ����

	//2.���� ��� �Է��ϸ� ���� �װ� �޾Ҵ��� �˷��ִ� �Լ��� �̵�
	ClassifyStudents(scores, target);

	//3.���� �հ� ����� �Լ��� ���� ���� �ް� �װ��� ����ϴ� ����
	int sum = SumScores(scores);
	double average = AverageScores(scores);
	printf("�л����� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

	//4. �л��� ���� ������ ����ϴ� �Լ�
	PrintRanks(scores);

	return 0;
}

void ClassifyStudents(int* scores, char targetGrade) {
	printf("�л� ���� �з�: \n");
	char grade = ' ';
	//�л��� ������ ���ǹ����� ����
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
		//�л��� ������ �Է¹��� Ÿ�ٰ��� ������ �Ʒ� ������ ���
		if (targetGrade == grade) {
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);
		}
	}
}

int SumScores(int* scores) {
	int sum = 0;
	//for���� ���� �迭�� �� ���� �� ������ �����ϰ� �� ������ ��� ���� ���Ͽ� ����
	for (int i = 0; i < STUDENTS; i++) {
		int hap = *(scores + i);
		sum += hap;
	}
	return sum;
}

double AverageScores(int* scores) {
	//�� �Լ����� ���� ������ ����� ���ϰ� ��հ��� ����
	double average = (double)SumScores(scores) / (double)STUDENTS;
	return average;
}

void PrintRanks(int* scores) {
	//�� �л��� ������ ����ϴ� �Լ�
	for (int i = 0; i < STUDENTS; i++) {
		int gradeList = STUDENTS;
		//�л����� for���� ���� ���������� ����ϴµ�, ���������� �л��� ���� scorelist ���� �ְ�
		int scorelist = *(scores + i);
		//5������ �����ϸ鼭 ������ ���� ��� �������� �ڱⰡ �� ũ�� gradeList �������� �ϳ��� ���̰� ���� 
		for (int j = 0; j < STUDENTS; j++) {
			if (scorelist > *(scores + j)) {
				gradeList--;
			}
		}
		// ���� �л��Ǽ����� ������ ���!!
		printf("%d �л��� ������ %d �Դϴ�.\n", i + 1, gradeList);
	}
}
