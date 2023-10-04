#include <stdio.h>

int hapf(int value); //함수원형 지정

void main()
{
	printf("1부터 10까지의 합은 %d\n", hapf(10));
	printf("1부터 100까지의 합은 %d\n", hapf(100));
	printf("1부터 1000까지의 합은 %d\n", hapf(1000)); //각각 합할 값을 지정후 출력
}

int hapf(int value)//함수로 들어옴
{
	int i=1;
	int hap = 0; //합과 i 를 초기화

	while (i <= value) { //while문으로 들어와서 value값보다 적으면 hap변수에 계속 더하는 반복문

		hap += i;
		i++; //끝나면 i를 1 더함
	}
	return hap; //변수 hap을 돌려보냄!!
}