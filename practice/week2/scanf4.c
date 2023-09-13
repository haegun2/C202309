#include <stdio.h>

int main(void) {
	int str[256];
	scanf_s("%s", str, sizeof(str));
	printf("%s\n", str);
	return 0;
}