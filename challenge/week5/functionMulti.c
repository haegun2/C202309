#include <stdio.h>

long multiF(long value); //�Լ����� ����

void main()
{
	printf("1���� 2������ ���� %d\n", multiF(2));
	printf("1���� 3������ ���� %d\n", multiF(3));
	printf("1���� 5������ ���� %d\n", multiF(5));
}

long multiF(int value)//�Լ��� ����
{
	int i = 1;
	int multi = 1; //���ϱ�ϱ� 0���� �����ʱ�ȭ ��..

	while (i <= value) { //while������ ���ͼ� value������ ������ multi������ ��� ���ϴ� �ݺ���

		multi *= i;
		i++; //������ i�� 1 ���ؼ� �ݺ� value���� �ʰ��ϸ� Ż��!
	}
	return multi; //���� multi�� ��������!!
}