#include <stdio.h>

int main() {
	int floor;
	printf("�� ���� �װڽ��ϱ�? (5~100)");
	scanf_s("%d", &floor); //������� �Է��� �޾Ƽ� ���� floor �� ����

	for (int i = floor; i > 0; i--) { //���� ���� ex 5�� 5 4 3 2 1 ���� �ݺ�
		for (int j = 1; j <= floor-i; j++) { //��-i�� ���ų� ���� j ����ŭ S�� ���
			printf("S");
		}
		for (int k = 1; k <= i*2-1; k++) {//i=�������� 2�� -1 ��ŭ *�� ��� �������� �ɼ��� i�� 1�� �����Ͽ� �Ųٷ� �Ƕ�̵尡 �ȴ�
			printf("*");
		}
		printf("\n");//�����ٷ� �̼�
	}
	return 0;
}