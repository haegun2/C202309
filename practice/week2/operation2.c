#include <stdio.h>

int main()
{
	int x = 4;
	int y = 2;
	int z;

	z = (x + y) * (x - y);
	printf("z = (x + y) * (x - y) = %d\n", z);
	z = (x * y) * (x / y);
	printf("z = (x * y) * (x / y) = %d\n", z);
	z = x + y + 2004;
	printf("z = x + y + 2004 = %d\n", z);
	//저장한 변수값들을 복잡한 연산자로 계산 가능
}