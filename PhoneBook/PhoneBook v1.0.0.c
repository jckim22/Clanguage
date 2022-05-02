/*�ؽ����̺��̶� ��Ȱ�� �ؽ��� �ȿ� �� �渶�� ��ũ�帮��Ʈ�� �̿��ؼ�
1���� 4�� 2���� 3�� '''�̷��� �ִٸ� �ؽ� Ű�� �̿� ex) key%size �� �ε��� ���� �޾Ƽ�
����濡 �ִ��� ã���ش�.

�渶�� ���� ��ũ�� ����Ʈ�� �����Ѵ�
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
			printf("ã���ô� �����Ͱ� �����ϴ�.\n");
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
			printf("ã���ô� �����Ͱ� �����ϴ�.\n");
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
		printf("��ɾ �Է��Ͻÿ�:");
		scanf("%c", &command);
		getchar();
		if (command == 'a') {

			char name[20];
			long number;

			printf("�̸��� �Է��Ͻÿ�:");
			scanf("%s", name);
			getchar();
			printf("��ȭ��ȣ�� �Է��Ͻÿ�:");
			scanf("%ld", &number);
			getchar();
			addNode(head, name, number);
			printf("�߰� �Ǿ����ϴ�\n");
			cnt++;
			if (cnt >= 20) {
				printf("�ڸ��� �����ϴ�");
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
			printf("�����Ͻ� ������� �̸��� �Է����ּ���:");
			scanf("%s", name);
			getchar();
			node* removeBefore = findBeforeNode(head, name);

			removeNode(removeBefore);
			printf("�����Ǿ����ϴ�\n");
		}

	}
}
