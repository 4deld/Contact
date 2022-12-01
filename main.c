#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ContactInfo {
	char* name;
	char* phone;
	char* birth;
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
	int mx;
	//연결리스트로 연락처를 구현하면 이론상으로 구조체 포인터 배열을 사용하는 것 보다
	//메모리 관리가 효율적이기에 구조체 포인터 배열을 사용하지 않고 1단계 때
	//연결리스트로 구현했던 것을 유지했습니다 
	//구조체 내부의 멤버 변수들은 동적할당했습니다
	int menu;
	printf("Max_num:");
	scanf("%d", &mx);
	while (1) {
		printMainMenu(); //메뉴 출력
		scanf("%d", &menu); //메뉴선택
		switch (menu) {
		case 1:
			if (numContact == mx) { //예외처리
				printf("OVERFLOW\n");
			}
			else
				insertContact(&head, &numContact); //등록
			break;
		case 2: printAll(head, numContact); // 보기
			break;
		case 3: deleteContact(&head, &numContact); //삭제
			break;
		case 4: findContactByBirth(head, numContact); //생일자 검색
			break;
		case 5:
			for (Contact* q = head; q != NULL; q = q->nxt) {//해제
				free(q->name);
				free(q->birth);
				free(q->phone);
				free(q);
			}
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
	Contact* tmp = (Contact*)malloc(sizeof(Contact)); //할당
	char t[100];
	printf("Name:");
	scanf("%s", t);
	tmp->name = (char*)malloc(sizeof(char) * (strlen(t) + 1));
	strcpy(tmp->name, t);
	printf("Phone_number:");
	scanf("%s", t);
	tmp->phone = (char*)malloc(sizeof(char) * (strlen(t) + 1));
	strcpy(tmp->phone, t);
	printf("Birth:");
	scanf("%s", t);
	tmp->birth = (char*)malloc(sizeof(char) * (strlen(t) + 1));
	strcpy(tmp->birth, t);
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
	char tmp[100];
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
	if (q != NULL) {//해제
		free(q->name);
		free(q->birth);
		free(q->phone);
		free(q);
	}
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