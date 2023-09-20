#include <stdio.h>

int main() {
	int choice;

	printf("1. 파일저장\n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료\n");
	scanf_s("%d", &choice); //메뉴 출력 후 사용자 값 입력

	if (choice == 1) //1 입력시 출력
		printf("파일을 저장합니다.");
	else if (choice == 2)//2 입력시 출력
		printf("저장 없이 닫습니다.");
	else if (choice == 3)//3 입력시 출력
		printf("종료합니다.");
	else //이외의 값 입력시 출력
		printf("잘못 입력하셨습니다.");
	

	return 0;
}