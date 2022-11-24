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
		case 3: deleteContact(head, &numContact); //삭제
			break;
		case 4: findContactByBirth(head, numContact); //생일자 검색
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
	// 방금 입력된 데이터를 적절한 위치로 이동
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
	//t의 전에 삽입
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
	//if (삭제할 데이터가 없으면) {
	//	printf(＂NO MEMBER\n＂); return;
	//}
	//printf(＂Name:＂);//이름입력 & 이름과 일치하는 데이터 삭제
	// 반복문을 이용해서 해당 데이터가 있는 인덱스를 찾는다.
	// 데이터가 정렬되어 있으므로, 삭제할 데이터의 인덱스+1의 데이터를
	// 인덱스로 이동시킨다.
	// 데이터의 개수를 감소시킴 (--)
	return;
}


void findContactByBirth(Contact* head, int numContact) {
	int birth;
	printf("Birth:");
	scanf("%d", &birth);//월
	// 반복문으로 birth와 head를 비교해서 일치하는 data를 출력함!
}

void printAll(Contact* head, int numContact) {
	return;
}