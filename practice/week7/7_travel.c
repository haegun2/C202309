#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

//������ ����� ���� ����, ��� ���� �����Ѱ��� �ݿ��� ���� name��, cities�� 2*10�� 2�����迭�� ����
char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

//�Լ����� ����
void calculateTravelDays();

int main() {

	//����ڷκ��� �����Է��� �޾� cities������ ����
	printf("%d���� ���ø��� ���ʴ�� �Է����ּ���.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));
	}

	//����ڷκ��� ������ �̸��� �Է¹޾� names ������ ����
	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));
	}

	//�Լ� ȣ��
	calculateTravelDays(names);

	return 0;
}

//�����ϰ� ��� �ϼ��� ����ϴ� �Լ�
void calculateTravelDays() {
	int travelDays[NUMCITY][NUMPEOPLE];

	//�Էµ� ���ú���, ������ ������� ���� �ϼ��� �Է��Ͽ� travelDays �迭�� ����
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {
			printf("���� %s���� ��� %s�� ���� �� ���� �Է��ϼ���: ", cities[i], names[j]);
			scanf_s("%d", &travelDays[i][j]);
		}
	}

	// �� ���ú� �� �ϼ� �ջ�
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			totalDays += travelDays[i][j];
		}
		//�� ���ú� ����ϼ� ��� �� ���
		float averageDays = (float)totalDays / NUMPEOPLE;
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f\n", cities[i], totalDays, averageDays);
	}
}
