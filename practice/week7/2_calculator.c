#include <stdio.h>

int sum(int a, int b); //���� �� �Լ� ����
int subtract(int a, int b); //���� �� �Լ�����
double multi(int a, int b); //���� �� �Լ�����
double devide(int a, int b); //������ �� �Լ�����

int firstNumber = -1; // ù ��° ���� ���� ���� 
int secondNumber = -1; // �� ��° ���� ���� ����
char operatorChar = ' '; // ������ ���� ����

int main() {
	printf("ù ��° ���ڸ� �Է��ϼ���: ");
	scanf_s("%d", &firstNumber);
	printf("�� ��° ���ڸ� �Է��ϼ���: ");
	scanf_s("%d", &secondNumber);

	char ch = getchar(); // ���ڿ� ���͸� ���� �ʵ��� ���� �ʱ�ȭ�� ���� �ڵ�

	printf("�����ڸ� �Է��ϼ��� (+, -, *, /) : ");
	scanf_s("%c", &operatorChar, (int)sizeof(operatorChar));

	double result = 0; // ����ϴ� �Լ��� ��ȯ ���� ������ ����
	int checker = 1; // �����ڿ� ���� ����� ���� �Ǿ������� üũ�ϱ� ���� ����

	// TODO 1: �� ������ �Լ�ȭ �ϰ� �Լ��� ȣ���Ͻÿ�.
	if (operatorChar == '+') {
		result = sum(firstNumber, secondNumber);
	}
	else if (operatorChar == '-') {
		result = subtract(firstNumber, secondNumber);
	}
	else if (operatorChar == '*') {
		result = multi(firstNumber, secondNumber);
	}
	else if (operatorChar == '/') {
		result = devide(firstNumber, secondNumber);
		if (result == 0) {
			checker = 1;
		}
		else {
			checker = 2;
		}
	}
	else if (operatorChar != '+' && operatorChar != '-' && operatorChar != '*' && operatorChar != '/') {
		checker = 0;
	}
		
	// TODO 2: switch ���� if������ �����Ͻÿ�.

	if (checker == 0) {
		printf("�߸��� �����ڸ� �Է��Ͽ��� ������, ������ �ʽ��ϴ�.");
	}
	else if (checker == 1) {
		printf("\n");
	}
	else {
		printf("���: %d %c %d = %.2lf\n", firstNumber, operatorChar, secondNumber, result);
	}

	return 0;
}

int sum(int a, int b){
	int finish = a + b;
	return finish;
}

int subtract(int a, int b){
	int finish = a - b;
	return finish;
}

double multi(int a, int b){
	double finish = (double)a * b;
	return finish;
}

double devide(int a, int b) {
	if (b == 0) {
		printf("0���� ���� �� �����ϴ�. ������ �ʽ��ϴ�.\n");
		return 0;
	}
	double finish = (double)a / b;
	return finish;
}