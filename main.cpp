#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCONTACT 100
typedef struct ContactInfo {
	char name[21];
	char phone[16];
	char birth[9];
	Contact* nxt;
	Contact* prv;
} Contact;
void printMainMenu();
void swapContact(Contact* contactData, int index1, int index2);
void sortContact(Contact* contactData, int numContact);
void insertContact(Contact* contactData, int* numContact);
void deleteContact(Contact* contactData, int* numContact);
void printAll(Contact* contactData, int numContact);
void findContactByBirth(Contact* contactData, int numContact);
int main(){
	Contact* head=NULL;
	int numContact = 0;//요소인덱스
	int menu;
	while (1) {
		printMainMenu(); //메뉴 출역
		scanf("%d", &menu); //메뉴선택
		switch (menu) {
		case 1: insertContact(head, &numContact); //등록
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
	return 0;
}
void printMainMenu(){
	printf("*****Menu*****\n");
	printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
	printf("Enter_the_menu_number:");
}

void insertContact(Contact* contactData, int* numContact){
	//if (_________________________) {
	//	printf("OVERFLOW\n");
	//	return;
	//}
	//printf("Name:");
	//scanf("%s", ______________________________);//No blank
	//printf("Phone_number:");
	//scanf("%s", _____________________________);
	//printf("Birth:");
	//scanf("%s", ______________________________);
	//_______________;//인덱스 증가
	//sortContact(contactData, *numContact);
	//// 방금 입력된 데이터를 적절한 위치로 이동
	//printf("<<%d>>\n", _______________);
	//return;
}

void sortContact(Contact* contactData, int numContact){
	// contactData의 데이터를 알파벳 순 정렬
	// strcmp 사용
	// swapContact 함수 사용
}

void swapContact(Contact* contactData, int index1, int index2) {
	//Swap Two-Element ---- 구조체 데이터는 배정문을 사용할 수 있음!
	//데이터가 입력될 때 최초의 데이터는 정렬이 필요 없음
		//두번째 데이터부터 정렬{
		//두번째 입력한 데이터가 첫번째 데이터와 교환이 필요한 지 뒤에서 부터 비교함!
		//교환이 필요하면 swapContact(contactData, i, i - 1) 호출
		// 세번째 데이터가 입력될 때 2개의 데이터는 교환된 상태이고,
		// 세번째 데이터와 두번째 데이터를 비교하고 교환이 필요하면 함수 호출
	
}

void deleteContact(Contact* contactData, int* numContact){
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


void findContactByBirth(Contact* contactData, int numContact) {
	int birth;
	printf("Birth:");
	scanf("%d", &birth);//월
	// 반복문으로 birth와 contactData를 비교해서 일치하는 data를 출력함!
}