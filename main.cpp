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
	int numContact = 0;//����ε���
	int menu;
	while (1) {
		printMainMenu(); //�޴� �⿪
		scanf("%d", &menu); //�޴�����
		switch (menu) {
		case 1: insertContact(head, &numContact); //���
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
	//_______________;//�ε��� ����
	//sortContact(contactData, *numContact);
	//// ��� �Էµ� �����͸� ������ ��ġ�� �̵�
	//printf("<<%d>>\n", _______________);
	//return;
}

void sortContact(Contact* contactData, int numContact){
	// contactData�� �����͸� ���ĺ� �� ����
	// strcmp ���
	// swapContact �Լ� ���
}

void swapContact(Contact* contactData, int index1, int index2) {
	//Swap Two-Element ---- ����ü �����ʹ� �������� ����� �� ����!
	//�����Ͱ� �Էµ� �� ������ �����ʹ� ������ �ʿ� ����
		//�ι�° �����ͺ��� ����{
		//�ι�° �Է��� �����Ͱ� ù��° �����Ϳ� ��ȯ�� �ʿ��� �� �ڿ��� ���� ����!
		//��ȯ�� �ʿ��ϸ� swapContact(contactData, i, i - 1) ȣ��
		// ����° �����Ͱ� �Էµ� �� 2���� �����ʹ� ��ȯ�� �����̰�,
		// ����° �����Ϳ� �ι�° �����͸� ���ϰ� ��ȯ�� �ʿ��ϸ� �Լ� ȣ��
	
}

void deleteContact(Contact* contactData, int* numContact){
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


void findContactByBirth(Contact* contactData, int numContact) {
	int birth;
	printf("Birth:");
	scanf("%d", &birth);//��
	// �ݺ������� birth�� contactData�� ���ؼ� ��ġ�ϴ� data�� �����!
}