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

struct node *BuildList(void) {
	struct node *head = NULL;
	struct node **lastRef = &head;

	int i;
	for(i = 9; i > 0; i--) {
		Push(lastRef, i);
		lastRef = &((*lastRef)->next);
	}
	return head;
}

/* int Length(struct node *node) {
	int len = 0;
	while(node) {
		len++;
		node = node->next;
	}
	return len;
}*/

void Print(struct node *node) {
	while(node) {
		printf("%d%s",node->data,(node->next) ? " ": "");
		node = node->next;
	}
	printf("\n");
}


void FrontBackSplit(struct node *source, struct node **frontRef, struct node **backRef) {
	*frontRef = source;
	if(source == NULL || source->next == NULL) {// Length < 2 cases
		*backRef = NULL;
		return;
	}
	*backRef = source->next;
	while((*backRef)->next) {
		*frontRef = (*frontRef)->next;
		*backRef = (*backRef)->next;
		if((*backRef)->next)
			*backRef = (*backRef)->next;
	}
	*backRef = (*frontRef)->next;
	(*frontRef)->next = NULL;
	*frontRef = source;
	return;
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

void MergeSort(struct node **headRef) {
	struct node *head = *headRef;
	struct node *a;
	struct node *b;
	if(head == NULL || (head->next == NULL)) {
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a,b);
}

int main(void) {
	struct node *root;
	root = BuildList();
	Print(root);
	MergeSort(&root);
	Print(root);
	
	return 0;
}

/*
void FrontBackSplit2(struct node* source,
                     struct node** frontRef, struct node** backRef) {
    struct node* fast;
    struct node* slow;
    if (source==NULL || source->next==NULL) { // length < 2 cases
        *frontRef = source;
        *backRef = NULL;
    }
    else {
        slow = source;
        fast = source->next;
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // 'slow' is before the midpoint in the list, so split it in two
        // at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}
*/
