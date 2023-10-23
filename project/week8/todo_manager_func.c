#include <stdio.h>
//10���� ���ϰ� 100ĭ�� ���ڸ� �����ϱ� ���Ͽ� ����� ����
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

void addTask(char task[]);
void delTask(int delIndex, int taskCount);
void printTask(int taskCount);

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭
int taskCount = 0; // ������� ����� ������ ��

int main() {
	printf("TODO ����Ʈ ����! \n");
	while (1) {
		int choice = -1; // ����� �Է��� ������� ������ �ʱ�ȭ��

		// to do menu�� ����ϰ� �Է¹���
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");;
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5. �� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // ���ᰪ�� ���� ����
		int delIndex = -1;  // �� �� ������ ���� index ���� ����
		int changeIndex = -1; // �� �� ������ ���� index ���� ����
		char ch; // �� �� ������ ���۸� �ޱ� ���� ���� ����

		// ����� �Է¿� ���� ����� ����
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]);
			taskCount++;
			break;
		case 2:
			// �� �� �����ϴ� �ڵ� ��� 
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex);
			if (delIndex > taskCount || delIndex <= 0) {
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				delTask(delIndex, taskCount);
				taskCount -= 1;
			}
			break;
		case 3:
			// �� �� ����� ����ϴ� �ڵ� ���
			printf("�� �� ���\n");
			printTask(taskCount);
			printf("\n");
			break;
		case 4:
			// �����ϴ� �ڵ�
			terminate = 1;
			break;

		case 5:
			//������ ���� �ڵ�
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &changeIndex);
			//����ڿ��� �ε��� ��ȣ�� �ް�
			ch = getchar();
			//���� ��ȣ��, �׽�ũ ī��Ʈ���� ���ų� ����, 0���� Ŭ���� ����
			if (changeIndex > 0 && changeIndex <= taskCount) {
				printf("������ ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
				//����� �������� �Է¹ް� �ش� ��ġ�� ���� ������ ����� ��
				scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
				//strcpy_s(tasks[changeIndex - 1], sizeof(tasks[changeIndex - 1]), tasks[changeIndex - 1]);
				printf("�� �� ""%s""�� ���� �Ǿ����ϴ�\n\n", tasks[taskCount]);
				break;
			}
			//�ƴ϶�� �߸��� �����̶�鼭 �ٽ� ���ͽ�Ŵ
			else {
				printf("������ �� ���� �����ϴ�. �߸��� �����Դϴ�.\n");
				break;
			}

		default:
			//�̻��� ���� ������ ������� ���
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {
			//���� ���� ���� 1�� ��ġ�ϸ� ���α׷��� ����
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}
		if (taskCount == 10) {
			//taskcount�� 10 �� �� ��� ����Ǿ��ٴ� ������ �Բ� ���α׷��� ����
			printf("�� ���� ��� á���ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}
	}
}

void addTask(char task[]) {
	//����ڿ��� �� ���� �Է¹޾Ƽ� �ش� ������ �迭�� �����ϴ� �Լ�
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[taskCount]);
}

void delTask(int delIndex, int taskCount) {
	printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);

	// �迭�� ���� (=�迭�� ���� �迭�� ���ڿ��� ����) �� �Ұ����ϱ� ������
	// ���ڿ� ���� �Լ��� ����
	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

	// Ư�� �ε����� �� �� ���� �� �ڿ� �ִ� �� �� ������ �ű��
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

void printTask(int taskCount) {
	//���� ����� �ݺ������� ���
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
}