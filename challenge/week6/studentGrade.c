#include<stdio.h>
#define STUDENTS 5

void classifyStudents(int scores[], char targetGrade) {
	printf("�л� ���� �з�: \n");
	char grade = ' ';
	//�л��� ������ ���ǹ����� ����
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
		//�л��� ������ �Է¹��� Ÿ�ٰ��� ������ �Ʒ� ������ ���
		if (targetGrade == grade) {
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);
		}
	}
}

int sumScores(int scores[]) {
	int sum = 0;
	//for���� ���� �迭�� �� ���� �� ������ �����ϰ� �� ������ ��� ���� ���Ͽ� ����
	for (int i = 0; i < STUDENTS; i++) {
		int hap = scores[i];
		sum += hap;
	}
	return sum;
}

double averageScores(int scores[]) {
	//�� �Լ����� ���� ������ ����� ���ϰ� ��հ��� ����
	double average = (double)sumScores(scores) / (double)STUDENTS;
	return average;
}

void printRanks(int scores[]) {
	//�� �л��� ������ ����ϴ� �Լ�
	for (int i = 0; i < STUDENTS; i++) {
		int gradeList = 5;
		//�л����� for���� ���� ���������� ����ϴµ�, ���������� �л��� ���� scorelist ���� �ְ�
		int scorelist = scores[i];
		//5������ �����ϸ鼭 ������ ���� ��� �������� �ڱⰡ �� ũ�� gradeList �������� �ϳ��� ���̰� ���� 
		for (int j = 0; j < STUDENTS; j++) {
			if (scorelist > scores[j]) {
				gradeList--;
			}
		}
		// ���� �л��Ǽ����� ������ ���!!
		printf("%d �л��� ������ %d �Դϴ�.\n", i+1, gradeList);
	}
}

int main() {
	int scores[STUDENTS];

	//1. �л��� ������ �Է¹ޱ�
	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar(); //���� �ӽ� ���� ����, �Է� �߿� ���͸� ����� ����

	char target;
	printf("Ư�� ����(A, B, C, D, F)�� �Է��Ͻÿ�: ");
	scanf_s("%c", &target, 1);//�Է¹��� ���� ���� target�� ����/ ���� ���� 1�� ���� �� char �� ũ�⸦ ����

	//2.���� ��� �Է��ϸ� ���� �װ� �޾Ҵ��� �˷��ִ� �Լ��� �̵�
	classifyStudents(scores, target);
	
	//3.���� �հ� ����� �Լ��� ���� ���� �ް� �װ��� ����ϴ� ����
	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("�л����� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

	//4. �л��� ���� ������ ����ϴ� �Լ�
	printRanks(scores);

	return 0;
}