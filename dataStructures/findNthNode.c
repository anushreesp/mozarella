#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node**, int);
void findnthnode(struct node*, int);

int main() {
	int n;
	struct node *head = NULL;
	
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	
	printf("What is your n?\n");
	scanf("%d", &n);

	findnthnode(head,n);

	return 0;
}

void push(struct node **head, int n) {
	struct node *nde = (struct node*)malloc(sizeof(struct node));

	if(nde == NULL) {
		printf("Malloc failure!!\n");
		exit(0);
	}
	
	nde->data = n;
	nde->next = *head;

	*head = nde;
	return;
}

void findnthnode(struct node *head, int n) {
	int count = 0;
	struct node *temp = head;

	if(head == NULL)
		return;

	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	if (n > count || n <= 0) {
		printf("Index out of range!\n");
		return;
	}

	temp = head;

	for(int i = 1; i < count-n+1; i++)
		temp = temp->next;
	
	printf("Value at (%d)th node is %d\n",n, temp->data);
	return;
}

	
