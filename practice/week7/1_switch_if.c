#include <stdio.h>

int main() {
	int carType = -1; // ���� ���� �Է¹޴� ����
	int parkingTime = -1; // ������ �ð��� �Է¹޴� ����
	int parkingPrice = -1; // ���� ��� ������ ���� ����

	printf("<���� ��� ��� �ý���>\n");
	printf("������: 500��/�ð�\n");
	printf("�������: 1000��/�ð�\n");
	printf("�ڵ���: 2000��/�ð�\n");
	printf("-------------------------\n");
	printf("���� ������ �Է��ϼ��� (1. ������, 2.�������, 3. �ڵ���): ");
	scanf_s("%d", &carType);

	printf("���� �ð��� �Է��ϼ��� (����: �ð�): ");
	scanf_s("%d", &parkingTime);

	if (carType == 1) {
		parkingPrice = 500 * parkingTime;
	}
	else if (carType == 2){
		parkingPrice = 1000 * parkingTime;
	}
	else if (carType == 3) {
		parkingPrice = 2000 * parkingTime;
	}
	else if (carType != 1) {
		carType = -1;
	}
	else if (carType != 2) {
		carType = -1;
	}
	else if (carType != 3) {
		carType = -1;
	}

	if (parkingPrice == -1) {
		printf("�߸��� ���� �����̱� ������, ��������� ����� �� �����ϴ�. \n");
	}
	else {
		printf("���� ���� ���: %d", parkingPrice);
	}

	return 0;
}