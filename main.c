#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100

typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
	struct ContactInfo* nxt; //���� ����
	struct ContactInfo* prv; //�� ����
} Contact;

void printMainMenu();
void sortContact(Contact** head, Contact* cur);
void insertContact(Contact** head, int* numContact);
void deleteContact(Contact** head, int* numContact);
void printAll(Contact* head, int numContact);
void findContactByBirth(Contact* head, int numContact);
int main() {
	Contact* head = NULL;
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
		case 3: deleteContact(&head, &numContact); //����
			break;
		case 4: findContactByBirth(head, numContact); //������ �˻�
			break;
		case 5:
			for (Contact* q = head; q != NULL; q = q->nxt)//����
				free(q);
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
	if (*numContact == MAXCONTACT) { //����ó��
		printf("OVERFLOW\n");
		return;
	}
	Contact* tmp = (Contact*)malloc(sizeof(Contact)); //�Ҵ�
	printf("Name:");
	scanf("%s", tmp->name);
	printf("Phone_number:");
	scanf("%s", tmp->phone);
	printf("Birth:");
	scanf("%s", tmp->birth);
	*numContact += 1;
	sortContact(head, tmp); //�Լ� ȣ��
	printf("<<%d>>\n", *numContact);
	return;
}

void sortContact(Contact** head, Contact* cur) {
	if (*head == NULL) { //���Ұ� ���� ��
		cur->nxt = NULL;
		*head = cur;
		return;
	}
	Contact* t = *head;
	Contact* tt;
	for (; t != NULL && strcmp(cur->name, t->name) > 0; t = t->nxt) {
		tt = t; //�� ����
	}
	//t�� ���� ����
	if (t == NULL) {
		tt->nxt = cur;
		cur->prv = tt;
		cur->nxt = NULL;
	}
	else if (t == *head) {
		cur->prv = NULL;
		cur->nxt = t;
		t->prv = cur;
		*head = cur;
	}
	else {
		cur->prv = t->prv;
		cur->nxt = t;
		t->prv->nxt = cur;
		t->prv = cur;
	}
	return;
}


void deleteContact(Contact** head, int* numContact) {
	if (*head == NULL) { //���� ���� ��
		printf("NO MEMBER\n");
		return;
	}
	*numContact -= 1;
	char tmp[21];
	printf("Name:");
	scanf("%s", tmp);
	Contact* q = *head;
	for (; q != NULL; q = q->nxt) {
		if (!strcmp(q->name, tmp)) {
			if (q == *head) {
				if (q->nxt != NULL) //����ó��
					q->nxt->prv = NULL;
				*head = q->nxt;
			}
			else if (q->nxt == NULL) {
				q->prv->nxt = NULL;
			}
			else {
				q->prv->nxt = q->nxt;
				q->nxt->prv = q->prv;
			}
			break;
		}
	}
	if (q != NULL)//����
		free(q);
	return;
}


void findContactByBirth(Contact* head, int numContact) {
	int birth;
	printf("Birth:");
	scanf("%d", &birth);
	for (Contact* q = head; q != NULL; q = q->nxt) {
		if (((q->birth[4] - '0') * 10 + q->birth[5] - '0') == birth) { //Ž��
			printf("%s %s %s\n", q->name, q->phone, q->birth);//���
		}
	}
	return;
}

void printAll(Contact* head, int numContact) {
	for (Contact* q = head; q != NULL; q = q->nxt)//���
		printf("%s %s %s\n", q->name, q->phone, q->birth);
	return;
}