#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void addNode(struct node**, int, int);
void delNode(struct node**, int);
void printNode(struct node*);

int main() {

	int i, n, element;
	struct node *head;
        
	printf("Enter the number of elements\n");
	scanf("%d", &n);

	printf("Enter the elements one by one\n");

	for(i=1; i<=n; i++)
	{	
		scanf("%d", &element);
		addNode(&head, element,i);
	}	
	printNode(head);
	printf("Insert the node to be deleted\n");
	scanf("%d", &i);
	delNode(&head,i);
	printf("Elements after deletion:\n"); 
        printNode(head); 
	return 0;
}

/*
 * This function creates a new node and inserts it at the specified position.
 * A pointer to head is passed because head needs to be modified in the called
 * function in the case of inserting at the beginning. 
 */
void addNode(struct node **head, int data, int position) {
        struct node *p, *q; // q is last but one node
	int k = 1;
        struct node *nodeptr = (struct node*) malloc(sizeof(struct node));

	if(nodeptr != NULL) {
		nodeptr->data = data;
		nodeptr->next = nodeptr;
	}
	
        /* Insert at the beginning */
	if (position == 1) {
		nodeptr->next = *head;
		nodeptr->prev = NULL;

		if(*head)
		   (*head)->prev = nodeptr;
		(*head) = nodeptr;
		return;
	}
	p = *head;
 	// Traverse until the position where you want to insert
	while((p->next != NULL) && (k < position-1)) {
		p = p->next;
		k++;
	}
	if (k > position) {
		printf("Desired position does not exist!\n");
		return;
	}
	nodeptr->prev = p;
	nodeptr->next = p->next;
	
	if (p->next)
	p->next->prev = nodeptr;

	p->next = nodeptr;
	return;
}

/*
 * This function deletes the element at a given position.
 */
void delNode(struct node **head, int pos) {
	struct node *p, *q;
        int k = 1;
	
	p = *head;
	if (pos == 1) {
		q = *head;
	    	*head = (*head)->next;
	    	free(q);
	    	return;
	}
        /* Deleting at a specified position */
	while((k < pos) && (p != NULL)) {
		q = p;
		printf("p->data = %d\n", p->data);		
		p = p->next;
		k++;
	}
        if (p == NULL) {
		/*We have reached the end of list */
		printf("Position does not exist!\n");
	} else {	
        	q->next = p->next;
		p->prev = q;
		free(p);
	}
}
/*
 * This function prints the elements of the list.
 */
void printNode(struct node *head) {
	struct node *p = head;
        
        printf("List elements:\n");
        while(p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}
