#include <stdio.h>

long multiF(long value); //함수원형 지정

void main()
{
	printf("1부터 2까지의 곱은 %d\n", multiF(2));
	printf("1부터 3까지의 곱은 %d\n", multiF(3));
	printf("1부터 5까지의 곱은 %d\n", multiF(5));
}

long multiF(int value)//함수값 들어옴
{
	int i = 1;
	int multi = 1; //곱하기니까 0으로 변수초기화 함..

	while (i <= value) { //while문으로 들어와서 value값보다 적으면 multi변수에 계속 곱하는 반복문

		multi *= i;
		i++; //끝나면 i를 1 더해서 반복 value값을 초과하면 탈출!
	}
	return multi; //변수 multi를 돌려보냄!!
}