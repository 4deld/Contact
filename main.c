#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100

typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
	struct ContactInfo* nxt; //다음 원소
	struct ContactInfo* prv; //전 원소
} Contact;

void printMainMenu();
void sortContact(Contact** head, Contact* cur);
void insertContact(Contact** head, int* numContact);
void deleteContact(Contact** head, int* numContact);
void printAll(Contact* head, int numContact);
void findContactByBirth(Contact* head, int numContact);
int main() {
	Contact* head = NULL;
	int numContact = 0;//연락처 개수
	int menu;
	while (1) {
		printMainMenu(); //메뉴 출력
		scanf("%d", &menu); //메뉴선택
		switch (menu) {
		case 1:
			insertContact(&head, &numContact); //등록
			break;
		case 2: printAll(head, numContact); // 보기
			break;
		case 3: deleteContact(&head, &numContact); //삭제
			break;
		case 4: findContactByBirth(head, numContact); //생일자 검색
			break;
		case 5:
			for (Contact* q = head; q != NULL; q = q->nxt)//해제
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
	if (*numContact == MAXCONTACT) { //예외처리
		printf("OVERFLOW\n");
		return;
	}
	Contact* tmp = (Contact*)malloc(sizeof(Contact)); //할당
	printf("Name:");
	scanf("%s", tmp->name);
	printf("Phone_number:");
	scanf("%s", tmp->phone);
	printf("Birth:");
	scanf("%s", tmp->birth);
	*numContact += 1;
	sortContact(head, tmp); //함수 호출
	printf("<<%d>>\n", *numContact);
	return;
}

void sortContact(Contact** head, Contact* cur) {
	if (*head == NULL) { //원소가 없을 때
		cur->nxt = NULL;
		*head = cur;
		return;
	}
	Contact* t = *head;
	Contact* tt;
	for (; t != NULL && strcmp(cur->name, t->name) > 0; t = t->nxt) {
		tt = t; //전 원소
	}
	//t의 전에 삽입
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
	if (*head == NULL) { //원소 없을 때
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
				if (q->nxt != NULL) //예외처리
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
	if (q != NULL)//해제
		free(q);
	return;
}


void findContactByBirth(Contact* head, int numContact) {
	int birth;
	printf("Birth:");
	scanf("%d", &birth);
	for (Contact* q = head; q != NULL; q = q->nxt) {
		if (((q->birth[4] - '0') * 10 + q->birth[5] - '0') == birth) { //탐색
			printf("%s %s %s\n", q->name, q->phone, q->birth);//출력
		}
	}
	return;
}

void printAll(Contact* head, int numContact) {
	for (Contact* q = head; q != NULL; q = q->nxt)//출력
		printf("%s %s %s\n", q->name, q->phone, q->birth);
	return;
}