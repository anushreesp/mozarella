#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addNode(struct node*, int);
void printNode(struct node*);

int main() {

	int n, element;
	struct node *nodeptr;

	printf("Enter the number of elements\n");
	scanf("%d", &n);

     //	nodeptr = (struct node*) malloc(n * sizeof(struct node));

	printf("Enter the elements one by one with space separation\n");

	for(int i=0; i<n; i++)
	{	
		scanf("%d", &element);
		addNode(nodeptr, element);
	}	
	printNode(nodeptr);

	return 0;
}

void addNode(struct node *nodeptr, int ele) {
	if(nodeptr == NULL) {
		nodeptr->data = ele;
		nodeptr->next = NULL;
	}
	while
	nodeptr->data=ele;
	nodeptr->next = NULL;
}

void printNode(struct node *nodeptr) {
	printf("Element is %d\n", nodeptr->data);
}
