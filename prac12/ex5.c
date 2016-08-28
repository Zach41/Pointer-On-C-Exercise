#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "alloc.h"

#define True  1
#define False 0

typedef struct node_tag {
    int val;
    struct node_tag *next;
} Node;

int sll_remove(Node **rootp, Node *delete) {
    register Node* currentp;

    assert(delete != NULL);

    while ((currentp = *rootp) != NULL && (currentp != delete)) {
	rootp = &currentp -> next;
    }

    if (currentp == delete) {
	*rootp = currentp -> next;
	free(currentp);

	return True;
    }

    return False;
}

int main() {
    Node* head = MALLOC(1, Node);
    head -> val = 0;

    Node* node1 = MALLOC(1, Node);
    node1 -> val = 1;

    Node* node2 = MALLOC(1, Node);
    node2 -> val = 2;

    Node* node3 = MALLOC(1, Node);
    node3 -> val = 3;

    head -> next = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;

    Node* root = head;
    int ret = sll_remove(&root, node2);
    assert(ret == True);

    while (head) {
	printf("%d ", head -> val);
	head = head -> next;
    }
    putchar('\n');

    return 0;
}
