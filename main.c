#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100

typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
	struct ContactInfo* nxt;
	struct ContactInfo* prv;
} Contact;

void printMainMenu();
void sortContact(Contact** head, Contact* cur);
void insertContact(Contact** head, int* numContact);
void deleteContact(Contact* head, int* numContact);
void printAll(Contact* head, int numContact);
void findContactByBirth(Contact* head, int numContact);
int main() {
	Contact* head=NULL;
	int numContact = 0;//����ó ����
	int menu;
	while (1) {
		printMainMenu(); //�޴� ���
		scanf("%d", &menu); //�޴�����
		switch (menu) {
		case 1:
			insertContact(&head, &numContact); //���
			break;
		case 2: printAll(head, numContact); // ����
			break;
		case 3: deleteContact(head, &numContact); //����
			break;
		case 4: findContactByBirth(head, numContact); //������ �˻�
			break;
		case 5:
			return 0;
		}
	}
}
void printMainMenu() {
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

void insertContact(Contact** head, int* numContact) {
	if (*numContact == 100) {
		printf("OVERFLOW\n");
		return;
	}
	Contact* tmp = (Contact*)malloc(sizeof(Contact));
	printf("Name:");
	scanf("%s", tmp->name);//No blank
	printf("Phone_number:");
	scanf("%s", tmp->phone);
	printf("Birth:");
	scanf("%s", tmp->birth);
	*numContact++;
	sortContact(head, tmp);
	// ��� �Էµ� �����͸� ������ ��ġ�� �̵�
	//printf("<<%d>>\n", _______________);
	return;
}

void sortContact(Contact** head, Contact* cur) {
	if (*head == NULL) {
		cur->nxt = NULL;
		*head = cur;
		return;
	}
	Contact* t = *head;
	Contact* tt;
	for (; t != NULL && strcmp(cur->name, t->name) > 0; t = t->nxt) {
		tt = t;
	}
	//t�� ���� ����
	if (t == NULL) {
		tt->nxt = cur;
		cur->prv = tt;
		cur->nxt = NULL;
	}
	else if(t==*head) {
		cur->prv = NULL;
		cur->nxt = t;
		t->prv = cur;
		t->nxt = NULL;
		*head = cur;
	}
	else {
		cur->prv = t->prv;
		cur->nxt = t;
		t->prv->nxt = cur;
		t->prv = cur;
	}
	//for (Contact* q = *head; q != NULL; q = q->nxt)
	//	printf("%s\n", q->name);
	return;
}


void deleteContact(Contact* head, int* numContact) {
	//if (������ �����Ͱ� ������) {
	//	printf(��NO MEMBER\n��); return;
	//}
	//printf(��Name:��);//�̸��Է� & �̸��� ��ġ�ϴ� ������ ����
	// �ݺ����� �̿��ؼ� �ش� �����Ͱ� �ִ� �ε����� ã�´�.
	// �����Ͱ� ���ĵǾ� �����Ƿ�, ������ �������� �ε���+1�� �����͸�
	// �ε����� �̵���Ų��.
	// �������� ������ ���ҽ�Ŵ (--)
	return;
}


void findContactByBirth(Contact* head, int numContact) {
	int birth;
	printf("Birth:");
	scanf("%d", &birth);//��
	// �ݺ������� birth�� head�� ���ؼ� ��ġ�ϴ� data�� �����!
}

void printAll(Contact* head, int numContact) {
	return;
}