#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
	if(head == NULL)
		return 0;

	node* temp = head;

	if(temp->next == NULL)
		return 1;

	int count = 0; 

	while(temp != NULL) {
		count++;
		temp = temp->next;
	}

	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) {
	char* string = malloc(sizeof(char) * (1+length(head)));
	node* temp = head;

	for(int i = 0; i < length(head); i++) {
		string[i] = temp->letter;
		temp = temp->next;
	}

	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
	node* temp = *pHead;

	if(temp == NULL) { 
		node* newNode = malloc(sizeof(node));
		newNode->next = NULL;
		newNode->letter = c;
		*pHead = newNode;
		return;
	}

	while(temp->next != NULL) {
		temp = temp->next;
	
	}

	node* newNode = malloc(sizeof(node));
	newNode->next = NULL;
	newNode->letter = c;
	temp->next = newNode;

	return;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead) {
	node* temp = *pHead;
	if(temp == NULL)
		return;

	while(temp != NULL) {
		 temp = temp->next;
		 free(*pHead);
		 *pHead = temp;
	}
	
	return;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}