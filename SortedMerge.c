#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int data;
	struct node *next;
};

void Push(struct node **headRef, int data) {
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

struct node *BuildList(int start, int end) {
	struct node *head = NULL;
	struct node **lastRef = &head;

	int i;
	for(i = start; i <= end ; i++) {		
		Push(lastRef, i);
		lastRef = &((*lastRef)->next);
	}
	return head;
}


void Print(struct node *node) {
	while(node) {
		printf("%d%s",node->data,(node->next) ? " ": "");
		node = node->next;
	}
	printf("\n");
}

void MoveNode(struct node ** destRef, struct node ** sourceRef) {
	struct node *newNode  = *sourceRef;

	assert(newNode != NULL);

	*sourceRef = newNode->next;

	newNode->next = *destRef;
	*destRef = newNode; 
}

struct node * SortedMerge(struct node *a, struct node *b) {
	struct node *result = NULL;
	struct node **lastPtrRef = &result;
	while( 1 ) {
		if( a == NULL) {
			*lastPtrRef = b;
			break;
		}
		else if( b == NULL) {
			*lastPtrRef = a;
			break;
		}

		if(a->data <= b->data) { 
			MoveNode(lastPtrRef, &a);
		}
		else 
			MoveNode(lastPtrRef, &b);

		lastPtrRef = &((*lastPtrRef)->next);
	}
	return result;
}




int main(void) {
	struct node *root;
	struct node *a = BuildList(1,3);
	struct node *b = BuildList(2,5);
	Print(a);
	Print(b);
	root = SortedMerge( a, b );
	Print(root);
	return 0;
}
