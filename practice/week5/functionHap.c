#include <stdio.h>

int hapf(int value); //�Լ����� ����

void main()
{
	printf("1���� 10������ ���� %d\n", hapf(10));
	printf("1���� 100������ ���� %d\n", hapf(100));
	printf("1���� 1000������ ���� %d\n", hapf(1000)); //���� ���� ���� ������ ���
}

int hapf(int value)//�Լ��� ����
{
	int i=1;
	int hap = 0; //�հ� i �� �ʱ�ȭ

	while (i <= value) { //while������ ���ͼ� value������ ������ hap������ ��� ���ϴ� �ݺ���

		hap += i;
		i++; //������ i�� 1 ����
	}
	return hap; //���� hap�� ��������!!
}