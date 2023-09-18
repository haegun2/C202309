#include <stdio.h>

int main()
{
	int i = 0; //변수 i를 정의
	do {//일단실행
		i += 1; //i는 돌때마다 +1
		if (i % 2 == 0) { //i가 짝수면 다시 처음으로
			continue; //아니면 계속 진행
		}
		printf("%d Hello World!\n", i);
	} while (i < 10);
	return 0;
}