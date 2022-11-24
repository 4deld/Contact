#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100

typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
	ContactInfo* nxt;
	ContactInfo* prv;
} Contact;

void printMainMenu();
void swapContact(Contact* head, int index1, int index2);
void sortContact(Contact* head, Contact* tail,Contact*n, int numContact);
void insertContact(Contact* head, Contact* tail, int* numContact);
void deleteContact(Contact* head, int* numContact);
void printAll(Contact* head, int numContact);
void findContactByBirth(Contact* head, int numContact);
int main() {
	Contact* head = NULL;
	Contact* tail = NULL;
	int numContact = 0;//요소인덱스
	int menu;
	while (1) {
		printMainMenu(); //메뉴 출력
		scanf("%d", &menu); //메뉴선택
		switch (menu) {
		case 1: insertContact(head, tail, &numContact); //등록
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

void insertContact(Contact* head, Contact* tail, int* numContact) {
	if (*numContact == 100) {
		printf("OVERFLOW\n");
		return;
	}

	Contact* n;
	printf("Name:");
	scanf("%s", n->name);//No blank
	printf("Phone_number:");
	scanf("%s", n->phone);
	printf("Birth:");
	scanf("%s", n->birth);

	*numContact++;
	sortContact(head, tail, n, *numContact);
	// 방금 입력된 데이터를 적절한 위치로 이동
	//printf("<<%d>>\n", _______________);
	//return;
}

void sortContact(Contact* head, Contact* tail, Contact* n, int numContact) {
	if (head == NULL) {
		head = n;
		tail = n;
		return;
	}
	Contact* t = head;
	while (1)
		if (t->nxt != NULL && strcmp(t->name, t->nxt->name) > 0)
			t = t->nxt;
	//if t==tail?
	//?
	printf("%s %s %s\n", t->prv->name, t->name, t->nxt->name);
	t->nxt = n;
	n->prv = tail;
	tail = n;
		// head의 데이터를 알파벳 순 정렬
		// strcmp 사용
		// swapContact 함수 사용
}

void swapContact(Contact* head, int index1, int index2) {
	//Swap Two-Element ---- 구조체 데이터는 배정문을 사용할 수 있음!
	//데이터가 입력될 때 최초의 데이터는 정렬이 필요 없음
		//두번째 데이터부터 정렬{
		//두번째 입력한 데이터가 첫번째 데이터와 교환이 필요한 지 뒤에서 부터 비교함!
		//교환이 필요하면 swapContact(head, i, i - 1) 호출
		// 세번째 데이터가 입력될 때 2개의 데이터는 교환된 상태이고,
		// 세번째 데이터와 두번째 데이터를 비교하고 교환이 필요하면 함수 호출

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