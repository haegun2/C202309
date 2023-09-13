#include <stdio.h>

int main()
{
	int x = +4;
	int y = -2;
	//변수에 부호 달고도 저장 가능

	printf("x + (-y) = %d\n", x + (-y));
	printf("-x + (+y) = %d\n", -x + (+y));
	//부호를 달고 싶으면 괄호 넣고 -도 가능
}