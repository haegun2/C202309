#include <stdio.h>

int main()
{
	int i = 0; //���� i�� ����
	while (i < 10)
	{
		i += 1; //i�� �������� +1

		if (i % 2 == 0) { //i�� ¦���� �ٽ� ó������
			continue; //�ƴϸ� ����
		}
		printf("%d Hello World!\n", i);
	}
	return 0;
}