#include <stdio.h>

int main() {
	int num = 0;//���� ���� �� �ʱ�ȭ
	printf("���ڸ� �Է��Ͻÿ�: "); 
	scanf_s("%d", &num);//��� �� �Է°��� ���� num�� ����

	if (num == 0) //����� �Է°��� 0,1,2�� ��� ������ ���� ���
		printf("zero");
	else if (num == 1)
		printf("one");
	else if (num == 2)
		printf("two");
	else// �̿��� ���� �ԷµǸ� not 0~2 ���
		printf("not 0~2");

	return 0;
}