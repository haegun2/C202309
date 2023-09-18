#include <stdio.h>

int main()
{
	int i = 0; //변수 i를 정의
	while (i < 10)
	{
		i += 1; //i는 돌때마다 +1

		if (i % 2 == 0) { //i가 짝수면 다시 처음으로
			continue; //아니면 진행
		}
		printf("%d Hello World!\n", i);
	}
	return 0;
}