#include <stdio.h>

int main() {
	int choice;

	printf("1. ��������\n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����\n");
	scanf_s("%d", &choice); //�޴� ��� �� ����� �� �Է�

	if (choice == 1) //1 �Է½� ���
		printf("������ �����մϴ�.");
	else if (choice == 2)//2 �Է½� ���
		printf("���� ���� �ݽ��ϴ�.");
	else if (choice == 3)//3 �Է½� ���
		printf("�����մϴ�.");
	else //�̿��� �� �Է½� ���
		printf("�߸� �Է��ϼ̽��ϴ�.");
	

	return 0;
}