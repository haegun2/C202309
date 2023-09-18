#include <stdio.h>

int main()
{
	int i = 0;
	while (i < 10)
	{ 
		i += 1;

		if (i % 2 == 0) {
			continue;
		}
		printf("%d Hello World!\n", i);
	}
	return 0;
}