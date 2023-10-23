#include <stdio.h>
//10개의 할일과 100칸의 글자를 저장하기 위하여 상수를 설정
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

void addTask(char task[]);
void delTask(int delIndex, int taskCount);
void printTask(int taskCount);

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하기 위한 2차원 배열
int taskCount = 0; // 현재까지 저장된 할일의 수

int main() {
	printf("TODO 리스트 시작! \n");
	while (1) {
		int choice = -1; // 사용자 입력을 저장받을 변수를 초기화함

		// to do menu를 출력하고 입력받음
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");;
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5. 할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // 종료값을 받을 변수
		int delIndex = -1;  // 할 일 삭제를 위한 index 저장 변수
		int changeIndex = -1; // 할 일 수정을 위한 index 저장 변수
		char ch; // 할 일 수정시 버퍼를 받기 위한 문자 변수

		// 사용자 입력에 따라서 기능을 구현
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]);
			taskCount++;
			break;
		case 2:
			// 할 일 삭제하는 코드 블록 
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex);
			if (delIndex > taskCount || delIndex <= 0) {
				printf("삭제 범위가 벗어났습니다.\n");
			}
			else {
				delTask(delIndex, taskCount);
				taskCount -= 1;
			}
			break;
		case 3:
			// 할 일 목록을 출력하는 코드 블록
			printf("할 일 목록\n");
			printTask(taskCount);
			printf("\n");
			break;
		case 4:
			// 종료하는 코드
			terminate = 1;
			break;

		case 5:
			//수정을 위한 코드
			printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &changeIndex);
			//사용자에게 인덱스 번호를 받고
			ch = getchar();
			//받은 번호가, 테스크 카운트보다 같거나 적고, 0보다 클때만 동작
			if (changeIndex > 0 && changeIndex <= taskCount) {
				printf("수정할 일을 입력하세요 (공백 없이 입력하세요): ");
				//뭐라고 수정할지 입력받고 해당 위치의 기존 값으로 덮어쓰기 함
				scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
				//strcpy_s(tasks[changeIndex - 1], sizeof(tasks[changeIndex - 1]), tasks[changeIndex - 1]);
				printf("할 일 ""%s""로 수정 되었습니다\n\n", tasks[taskCount]);
				break;
			}
			//아니라면 잘못된 선택이라면서 다시 복귀시킴
			else {
				printf("수정할 할 일이 없습니다. 잘못된 선택입니다.\n");
				break;
			}

		default:
			//이상한 값을 넣으면 오류라고 출력
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		if (terminate == 1) {
			//종료 변수 값이 1로 일치하면 프로그램을 종료
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
			break;
		}
		if (taskCount == 10) {
			//taskcount가 10 일 때 모두 종료되었다는 문구와 함께 프로그램을 종료
			printf("할 일이 모두 찼습니다. 프로그램을 종료합니다.\n");
			break;
		}
	}
}

void addTask(char task[]) {
	//사용자에게 할 일을 입력받아서 해당 내용을 배열에 저장하는 함수
	printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));
	printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[taskCount]);
}

void delTask(int delIndex, int taskCount) {
	printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

	// 배열간 대입 (=배열에 문자 배열인 문자열의 대입) 이 불가능하기 때문에
	// 문자열 복사 함수로 삭제
	strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

	// 특정 인덱스의 할 일 삭제 후 뒤에 있는 할 일 앞으로 옮기기
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

void printTask(int taskCount) {
	//할일 목록을 반복문으로 출력
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s \n", i + 1, tasks[i]);
	}
}