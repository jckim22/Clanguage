/*해쉬테이블이란 광활한 해쉬맵 안에 각 방마다 링크드리스트를 이용해서
1번방 4명 2번방 3명 '''이렇게 있다면 해쉬 키를 이용 ex) key%size 로 인덱스 값을 받아서
몇번방에 있는지 찾아준다.

방마다 각각 링크드 리스트가 존재한다
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char* name;
	long number;
	struct node* next;
}node;
node* getnewNode(char* name, int number) {
	node* curr = malloc(sizeof(node));

	curr->name = name;
	curr->number = number;
	curr->next = NULL;

	return curr;

}
void addNode(node* head, char* name, int number) {

	node* curr = getnewNode(name, number);

	node* last = head;


	while (last->next != NULL) {
		last = last->next;
	}

	last->next = curr;

}
void removeNode(node* removeBefore) {
	

	node* removeNd = removeBefore->next;

	removeBefore->next = removeNd->next;
	free(removeNd);
}

long findNode(node* head, char* findName) {
	node* curr = head->next;

	while (curr->name != findName) {
		if (curr == NULL) {
			printf("찾으시는 데이터가 없습니다.\n");
			return 0;
		}
		curr = curr->next;

	}
	return curr->number;
}

node* findBeforeNode(node* head, char* findName) {
	node* curr = head->next;

	while (curr->next->name != findName) {
		if (curr == NULL) {
			printf("찾으시는 데이터가 없습니다.\n");
			return 0;
		}
		curr = curr->next;

	}
	return curr;
}

int main() {
	char command;
	int cnt = 0;
	node* curr = NULL;
	node* head = malloc(sizeof(node));
	head->next = NULL;

	while (1) {
		printf("명령어를 입력하시오:");
		scanf("%c", &command);
		getchar();
		if (command == 'a') {

			char name[20];
			long number;

			printf("이름을 입력하시오:");
			scanf("%s", name);
			getchar();
			printf("전화번호를 입력하시오:");
			scanf("%ld", &number);
			getchar();
			addNode(head, name, number);
			printf("추가 되었습니다\n");
			cnt++;
			if (cnt >= 20) {
				printf("자리가 없습니다");
				return 0;
			}
			node* curr=head->next;
			while (curr->next != NULL) {
				printf("%s %ld\n", curr->name,curr->number);
				curr = curr->next;
			}
		}
		else if (command == 'd') {
			char name[20];
			printf("삭제하실 사용자의 이름을 입력해주세요:");
			scanf("%s", name);
			getchar();
			node* removeBefore = findBeforeNode(head, name);

			removeNode(removeBefore);
			printf("삭제되었습니다\n");
		}

	}
}
