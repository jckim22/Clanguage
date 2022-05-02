#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct user {
	char* name;
	char* number;
	struct user* next;
} user;
user* load_data(user* head, FILE* p,int* cnt) {

	user* load_last_node=head;

	while (1) {
		char* load_name = malloc(sizeof(char) * 30);
		char* load_number = malloc(sizeof(char) * 30);

		user* last = head;
		user* curr = malloc(sizeof(user));

		if (EOF != fscanf(p, "%s %s", load_name, load_number)) {

			curr->name = load_name;
			curr->number = load_number;
			curr->next = NULL;

			while (last->next != NULL) {
				last = last->next;
			}
			last->next = curr;
			load_last_node = curr;
			(*cnt)++;
			
		}
		else {
			printf("저장된 파일을 불러왔습니다\n");

			return load_last_node;
			
		}

	}
	
}
void save_data(user* load_last_node, FILE* p) {
	user* curr = load_last_node->next;

	while (curr != NULL) {
		fprintf(p, "%s %s\n", curr->name, curr->number);
		curr = curr->next;
	}

	printf("저장 후 종료합니다\n");
}
void add_node(user* head) {
	user* last = head;
	user* curr = malloc(sizeof(user));

	curr->name = malloc(sizeof(char) * 30);
	curr->number = malloc(sizeof(char) * 30);

	printf("이름을 입력하시오:");
	scanf("%s", curr->name);
	printf("번호를 입력하시오:");
	scanf("%s", curr->number);
	curr->next = NULL;

	while (last->next != NULL) {
		last = last->next;
	}
	last->next = curr;
	printf("%s %s\n", last->next->name, last->next->number);

}

void delete_node(user* head) {
	user* delete_node;
	user* before_node = head;
	char* name = malloc(sizeof(char) * 30);

	printf("삭제할 이름:");
	scanf("%s", name);

		while (strcmp(before_node->next->name, name) != 0) {
			before_node = before_node->next;

		}
		delete_node = before_node->next;
		before_node->next = delete_node->next;

		free(delete_node);
		free(name);

		printf("삭제되었습니다\n");
}
void list_node(user* head) {
	user* curr = head->next;
	while (curr->next != NULL) {
		printf("%s %s\n", curr->name, curr->number);
		curr = curr->next;
	}
	printf("%s %s\n", curr->name, curr->number);
	
}

void find_node(user* head) {
	user* curr = head->next;
	char* name = malloc(sizeof(char) * 30);

	printf("찾으실 이름:");
	scanf("%s", name);

	while (strcmp(curr->name, name) != 0) {
		
		curr = curr->next;
		if (curr->next == NULL) {
			break;
		}
	}
	if (strcmp(curr->name, name) == 0) {
		printf("이름:%s 전화번호:%s\n\n", curr->name, curr->number);
	}
	else {
		printf("없는 이름입니다 \n\n");
	}

	free(name);
}
int main(int argc, char* argv[]) {

	FILE* p = fopen(argv[1], "a + ");

	char command[20];
	int cnt = 0;

	user* head = malloc(sizeof(user));
	head->next = NULL;

	user* load_last_node = load_data(head, p, &cnt);
	
	while (1) {
		printf("명령어를 입력하시오(명령어 목록 보기 : h):");
		scanf("%s", command);
		printf("\n");

		if (strcmp(command, "h") == 0) {
			printf("----명령어 목록----\n");
			printf("----add----\n");
			printf("----delete----\n");
			printf("----list----\n");
			printf("----find----\n");
			printf("----quit----\n\n");
		}
		else if (strcmp(command, "add") == 0) {
			if (cnt >= 20) {
				printf("데이터의 한도는 20개입니다\n");

				continue;
			}
			add_node(head);
			cnt++;
			printf("%d번째 데이터가 추가되었습니다 \n",cnt);
		
		}
		else if (strcmp(command, "delete") == 0) {
			delete_node(head);
			cnt--;
		}
		else if (strcmp(command, "list") == 0) {
			list_node(head);
		}
		else if (strcmp(command, "find") == 0) {
			find_node(head);
		}
		else if (strcmp(command, "quit") == 0) {
			save_data(load_last_node, p);

			fclose(p);

			return 0;
		}
	}
}