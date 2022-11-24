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
	int numContact = 0;//����ε���
	int menu;
	while (1) {
		printMainMenu(); //�޴� ���
		scanf("%d", &menu); //�޴�����
		switch (menu) {
		case 1: insertContact(head, tail, &numContact); //���
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
	// ��� �Էµ� �����͸� ������ ��ġ�� �̵�
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
		// head�� �����͸� ���ĺ� �� ����
		// strcmp ���
		// swapContact �Լ� ���
}

void swapContact(Contact* head, int index1, int index2) {
	//Swap Two-Element ---- ����ü �����ʹ� �������� ����� �� ����!
	//�����Ͱ� �Էµ� �� ������ �����ʹ� ������ �ʿ� ����
		//�ι�° �����ͺ��� ����{
		//�ι�° �Է��� �����Ͱ� ù��° �����Ϳ� ��ȯ�� �ʿ��� �� �ڿ��� ���� ����!
		//��ȯ�� �ʿ��ϸ� swapContact(head, i, i - 1) ȣ��
		// ����° �����Ͱ� �Էµ� �� 2���� �����ʹ� ��ȯ�� �����̰�,
		// ����° �����Ϳ� �ι�° �����͸� ���ϰ� ��ȯ�� �ʿ��ϸ� �Լ� ȣ��

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