#include <stdio.h>

int main() {
	int num = 0;//변수 지정 및 초기화
	printf("숫자를 입력하시오: "); 
	scanf_s("%d", &num);//출력 후 입력값을 변수 num에 지정

	if (num == 0) //사용자 입력값이 0,1,2인 경우 지정한 영어 출력
		printf("zero");
	else if (num == 1)
		printf("one");
	else if (num == 2)
		printf("two");
	else// 이외의 값이 입력되면 not 0~2 출력
		printf("not 0~2");

	return 0;
}