#include <stdio.h>

int sum(int a, int b); //덧셈 할 함수 원형
int subtract(int a, int b); //뺄셈 할 함수원형
double multi(int a, int b); //곱셈 할 함수원형
double devide(int a, int b); //나눗셈 할 함수원형

int firstNumber = -1; // 첫 번째 정수 저장 변수 
int secondNumber = -1; // 두 번째 정수 저장 변수
char operatorChar = ' '; // 연산자 저장 변수

int main() {
	printf("첫 번째 숫자를 입력하세요: ");
	scanf_s("%d", &firstNumber);
	printf("두 번째 숫자를 입력하세요: ");
	scanf_s("%d", &secondNumber);

	char ch = getchar(); // 문자에 엔터를 받지 않도록 버퍼 초기화를 위한 코드

	printf("연산자를 입력하세요 (+, -, *, /) : ");
	scanf_s("%c", &operatorChar, (int)sizeof(operatorChar));

	double result = 0; // 계산하는 함수의 반환 값을 저장할 변수
	int checker = 1; // 연산자에 따른 계산이 수행 되었는지를 체크하기 위한 변수

	// TODO 1: 각 연산을 함수화 하고 함수를 호출하시오.
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
		
	// TODO 2: switch 문을 if문으로 변경하시오.

	if (checker == 0) {
		printf("잘못된 연산자를 입력하였기 때문에, 계산되지 않습니다.");
	}
	else if (checker == 1) {
		printf("\n");
	}
	else {
		printf("결과: %d %c %d = %.2lf\n", firstNumber, operatorChar, secondNumber, result);
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
		printf("0으로 나눌 수 없습니다. 계산되지 않습니다.\n");
		return 0;
	}
	double finish = (double)a / b;
	return finish;
}