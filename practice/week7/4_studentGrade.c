#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

void printStu_ever();
void printSub_ever();

char subjectNames[SUBJECTS][CHARNUM] = { "����", "�߰����", "�⸻���" };
char studentNames[STUDENTS][CHARNUM] = { "" }; // �л� �̸��� ����� �迭
double studentScores[STUDENTS][SUBJECTS] = { 0.0 }; // �л��� ���� �� ������ ������ ����� �迭

int main() {

	printf("�л� %d���� �̸��� �Է��� �����մϴ�. \n", STUDENTS);
	// TODO 1.1: �л� �̸��� �Է¹޴� �ڵ� ��� �ۼ�

	for (int i = 0; i < STUDENTS; i++) {
		printf("\t%d��° �л��� �̸��� �Է��ϼ���: ", i + 1);
		scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
	}

	// �Էµ� �л� �̸��� �� ����Ǿ����� Ȯ���ϴ� �ڵ� ���
	printf("�л� �̸��� ��� �ԷµǾ����ϴ�. \n");
	printf("�Էµ� �л� �̸��� ������ �����ϴ�. \n");
	for (int i = 0; i < STUDENTS; i++) {
		printf("%s", studentNames[i]);
		if (i != STUDENTS - 1) {
			printf(", ");
		}
	}
	printf("\n");
	printf("--------------------\n");
	printf("�� �л��� %s, %s, %s ������ ���ʴ�� �Է����ּ���. (���� ����)\n ", subjectNames[0], subjectNames[1], subjectNames[2]);


	// TODO 1.2: �л����� ���� �� ������ �Է¹޴� �ڵ� ��� �ۼ�

	for (int i = 0; i < STUDENTS; i++) {
		printf("    %s�� ����: ", studentNames[i]);

		scanf_s("%lf %lf %lf", &studentScores[i][0], &studentScores[i][1], &studentScores[i][2]);
	}

	printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
	printf("--------------------\n");
	printf("�л� �� ������ ������ �����ϴ� \n");
	// TODO 1.3: �л� �� ��� ������ ����ϴ� �ڵ� ��� �ۼ� >> ���� �Լ�ȭ
	// HINT1: 2�� for��: (1) �л��� (2) ������� ���� �հ� ����� ���ϰ� ���
	// HINT2: ��¹� �ڵ� = printf("\t%s�� ��� ����: %.2lf\n", studentNames[i], finalScore);
	printStu_ever();

	printf("���� �� ��� ������ �Ʒ��� �����ϴ�. \n");
		// TODO 1.4: ���� �� ��� ������ ����ϴ� �ڵ� ��� �ۼ� >> ���� �Լ�ȭ
		// HINT1: 2�� for������ (1) ���� (2) �л����� ���� �հ� ����� ���ϰ� ���	
		// HINT2: ��¹� �ڵ� = printf("\t%s�� ��� ������ %.2lf �Դϴ�.\n", subjectNames[i], subjectScore);
	printSub_ever();

	printf("���α׷��� �����մϴ�. ");
	return 0;
	
}

void printStu_ever() {
	for (int i = 0; i < STUDENTS; i++) {
		double sum = 0;
		for (int j = 0; j < SUBJECTS; j++) {
			sum += studentScores[i][j];
		}
		double ever = sum / SUBJECTS;
		printf("\t%s�� �������: %.2lf\n", studentNames[i], ever);
	}
	printf("--------------------\n");
}

void printSub_ever() {
	for (int i = 0; i < SUBJECTS; i++) {
		double sum = 0;
		for (int j = 0; j < STUDENTS; j++) {
			sum += studentScores[j][i];
		}
		double subjectScore = sum / STUDENTS;
		printf("\t%s�� ��������� %.2lf �Դϴ�.\n", subjectNames[i], subjectScore);
	}
}