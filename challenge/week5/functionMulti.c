#include <stdio.h>

long multiF(long value); //�Լ����� ����

int main()
{
	printf("1���� 2������ ���� %ld\n", multiF(2));
	printf("1���� 3������ ���� %ld\n", multiF(3));
	printf("1���� 5������ ���� %ld\n", multiF(5));

	return 0;
}

long multiF(long value)//�Լ��� ����
{
	int i = 1;
	int multi = 1; //���ϱ�ϱ� 0���� �����ʱ�ȭ ��..

	while (i <= value) { //while������ ���ͼ� value������ ������ multi������ ��� ���ϴ� �ݺ���

		multi *= i;
		i++; //������ i�� 1 ���ؼ� �ݺ� value���� �ʰ��ϸ� Ż��!
	}
	return multi; //���� multi�� ��������!!
}