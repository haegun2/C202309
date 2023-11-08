#include <stdio.h>

double summation(double* v1, double* v2, double* r1);
double suvtraction(double* v1, double* v2, double* r1);
double multification(double* v1, double* v2, double* r1);
double division(double* v1, double* v2, double* r1);

int main() {

	double a, b, result;
	printf("실수 2개를 입력하세요 : ");
	scanf_s("%lf %lf", &a, &b);

	summation(&a, &b, &result);
	printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

	suvtraction(&a, &b, &result);
	printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

	multification(&a, &b, &result);
	printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

	division(&a, &b, &result);
	printf("%.0lf / %.0lf = %.2lf \n", a, b, result);
	return 0;
}


double summation(double* v1, double* v2, double* r1) {
	*r1 = *v1 + *v2;
}

double suvtraction(double* v1, double* v2, double* r1) {
	*r1 = *v1 - *v2;
}

double multification(double* v1, double* v2, double* r1) {
	*r1 = *v1 * *v2;
}

double division(double* v1, double* v2, double* r1) {
	*r1 = *v1 / *v2;
}