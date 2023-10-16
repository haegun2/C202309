#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

//������ ����� ���� ����, ��� ���� �����Ѱ��� �ݿ��� ���� name��, cities�� 2*10�� 2�����迭�� ����
char names[NUMPEOPLE][10];
char cities[NUMCITY][10];

//�Լ����� ����
void calculateTravelDays();
int getSum(int numArray[]);
double getAverage(int numArray[]);
void getFamousCity();

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
	//��� ��ĥ �־����� Ȯ���� �迭�� ����
	double averageDays[NUMCITY];

	//i�� �����ϴ� �ݺ���
	for (int i = 0; i < NUMCITY; i++) {
		//��Ż������� �Լ� getSum�ε� ���� ���� travelDays�� i�� �� ����� �������
		int totalDay = getSum(travelDays[i]);
		double averageDay = getAverage(travelDays[i]);
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2d\n", cities[i], totalDay, averageDays);
		averageDays[i] = averageDay;
	}
	getFamousCity(averageDays);
}

//getSum �Լ��� �� ���� ������ �迭��, ������ �˷��� int�� �� ����� �� ������ for������
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
}///��տ������� �̻��� ���� ��µǾ� ������ ����

void getFamousCity(double dayArray[]) {
	double maxDay = 0;
	int maxDayIndex = 0;
	for (int i = 0; i < NUMPEOPLE; i++) {
		if (dayArray[i] > maxDay) {
			maxDay = dayArray[i];
			maxDayIndex = i;
		}
	}
	printf("����� �������� ���� �α��־��� ���ô� %s �Դϴ�. (��ոӹ���: %.2f)\n", cities[maxDayIndex], maxDay);
}