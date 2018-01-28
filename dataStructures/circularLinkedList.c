#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

void addNode_beg(struct node**, int);
void addNode_end(struct node**, int);
void addNode(struct node**, int,int);
void delNode_beg(struct node**);
void delNode_end(struct node**);
void delNode(struct node**, int);
void printNode(struct node*);

int main() {
	char c;
	int i, element, position;
	struct node *head = NULL;
        
	do { 
		printf("Enter your choice of operation:\n");
		printf("1. Add at the beginning\n");
		printf("2. Add at the end\n");
		printf("3. Add at a specified position\n");
		printf("4. Delete at the beginning\n");
		printf("5. Delete at the end\n");
		printf("6. Delete at a specified position\n");
		printf("7. Display the list\n");
		printf("8. Exit\n");
		scanf("%d", &i);
		switch(i) {
		case 1: printf("Enter the element to insert\n");
			scanf("%d", &element);
			addNode_beg(&head, element);
			break;
		case 2: printf("Enter the element to insert\n");
			scanf("%d", &element);
			addNode_end(&head, element);
			break;
		case 3: printf("Enter the element and position to insert\n");
                	scanf("%d %d", &element, &position);
                	addNode(&head, element, position);
                	break;
		case 4: delNode_beg(&head);
                	break;
		case 5: delNode_end(&head);
                	break;
		case 6: printf("Enter the position to delete\n");
                	scanf("%d", &position);
                	delNode(&head, position);
                	break;
		case 7: printNode(head);
			break;
		case 8: exit(1);
			break;
		}
		}while(1);
		return 0;
}

/*
 * This function creates a new node and inserts it at the specified position.
 * A pointer to head is passed because head needs to be modified in the called
 * function in the case of inserting at the beginning. 
 */
void addNode_beg(struct node **head, int data) {
        struct node *p = *head;
        struct node *nodeptr = (struct node*) malloc(sizeof(struct node));
	if (nodeptr != NULL) {
		nodeptr->data = data;
		nodeptr->next = nodeptr; //This can be first and last node
	}
	/* Empty list */
	if (*head == NULL){
		*head = nodeptr;
		 return;
	}
        /* Insert at the beginning */
	while (p->next != *head) {
		printf("Traversal\n");
		p = p->next; //Traverse to the end of list
	}
	p->next = nodeptr;
	nodeptr->next = *head;
	(*head) = nodeptr;
	return;
}

/*
 * This function creates a new node and insterts it at the end of the circular linked list.
 */
void
addNode_end(struct node **head, int data) {
	struct node *p = *head;
	struct node *nodeptr = (struct node*) malloc(sizeof(struct node));

	if (nodeptr != NULL) {
		nodeptr->data = data;
		nodeptr->next = nodeptr;
	}
        if (*head == NULL) {
		*head = nodeptr;
		return;
	}
 	// Traverse till the end of the list
	while(p->next != *head)
		p = p->next;
	p->next = nodeptr;
	nodeptr->next = *head;
	return;
}
/*
 * This function creates a new node and inserts it at the specified position.
 * A pointer to head is passed because head needs to be modified in the called
 * function in the case of inserting at the beginning. 
 */
void addNode(struct node **head, int data, int position) {
        struct node *p, *q; // q is the previous node
	int k = 1;
        struct node *nodeptr = (struct node*) malloc(sizeof(struct node));

	if(nodeptr != NULL) {
		nodeptr->data = data;
		nodeptr->next = nodeptr;
	}
        p = *head;
	if (*head == NULL) {
		*head = nodeptr;
		return;
	}
 	// Traverse until the position where you want to insert
		while((p != NULL) && (k < position)) {
			q = p;
			p = p->next;
			k++;
		}
		nodeptr->next = p;
		q->next = nodeptr;
	return;
}
/*
 * This function deletes the element at a given position.
 */
void delNode(struct node **head, int pos) {
	struct node *p, *q;
        int k = 1;
        
	/* If list is empty */
	if (*head == NULL) {
		printf("List is empty!\n");
		return;
	}
	p = *head;
	if (pos < 1) {
		printf("Please enter a position greater than 1\n");
		return;
	}
	if (pos == 1) {
	    	*head = (*head)->next;
	    	free(p);
	    	return;
	}
        /* Deleting at a specified position */
	while((k < pos) && (p != NULL)) {
		q = p; //last but one node
		p = p->next;
		k++;
	}
        if (p == NULL) {
		/*We have reached the end of list */
		printf("Position does not exist!\n");
	} else {	
        	q->next = p->next;
		free(p);
	}
}
void delNode_beg(struct node **head) {
	struct node *temp = *head;
	struct node *current = *head;

	/* If list is empty */
	if (*head == NULL) {
		printf("List is empty!\n");
		return;
	}
	while(current->next != *head)
		current = current->next;
        current->next = (*head)->next;	
	*head = (*head)->next;
	
	free(temp);
	return;	
}
void delNode_end(struct node **head) {
	struct node *temp;
	struct node *current = *head;

	/* If list is empty */
	if (*head == NULL) {
		printf("List is empty!\n");
		return;
	}
	while(current->next != *head) {
		temp = current;
		current = current->next;
	}	
	temp->next = current->next;
	free(current);
	return;
}
/*
 * This function prints the elements of the list.
 */
void printNode(struct node *head) {
	struct node *p = head;
        
	if (head == NULL)
		return;
 
        printf("List elements:\n");
        do {
		printf("%d\n", p->data);
		p = p->next;
	}while(p != head);
}
