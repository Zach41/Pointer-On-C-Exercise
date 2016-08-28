#include <stdio.h>

#include "alloc.h"

typedef struct node_tag {
    int val;
    struct node_tag *next;
} Node;

Node* sll_reverse(Node* first) {
    Node* head = NULL;
    Node* cur  = first;

    while (cur) {
	Node* node = cur -> next;
	cur -> next = NULL;

	if (head == NULL) {
	    head = cur;
	} else {
	    cur -> next = head;
	    head = cur;
	}
	cur = node;
    }

    return head;
}

int main() {
    Node* head = MALLOC(1, Node);
    head -> val = 1;

    Node* node1 = MALLOC(1, Node);
    node1 -> val = 2;

    Node* node2 = MALLOC(1, Node);
    node2 -> val = 3;

    head -> next = node1;
    node1 -> next = node2;
    node2 -> next = NULL;

    head = sll_reverse(head);

    while (head) {
	printf("%d ", head -> val);
	head = head -> next;
    }
    putchar('\n');

    return 0;
}
