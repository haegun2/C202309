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
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.", i + 1, targetGrade);
		}
	}
}

int main() {
	int scores[STUDENTS];

	//1. �л��� ������ �Է¹ޱ�
	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i+1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar(); //���� �ӽ� ���� ����, �Է� �߿� ���͸� ����� ����

	char target;
	printf("Ư�� ����(A, B, C, D, F)�� �Է��Ͻÿ�: ");
	scanf_s("%c", &target, 1); // �Է¹��� ���� ���� target�� ����/ ���� ���� 1�� ���� �� char �� ũ�⸦ ����
	
	//2.���� ��� �Է��ϸ� ���� �װ� �޾Ҵ��� �˷��ִ� �Լ��� �̵�
	classifyStudents(scores, target);

	return 0;
}