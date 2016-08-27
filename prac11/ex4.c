#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int         val;
    struct node *next;
} Node;

int main() {
    Node *head , *prev, *cur;
    head = prev = cur = NULL;
    
    for (int i=1; i<=3; i++) {
	Node *node = (Node *)malloc(sizeof(Node));

	/* 结构里的指针没有被隐式的初始化 */
	node -> val = i * 5;
	node -> next = NULL;
	
	if (node == NULL) {
	    printf("Out of Memory.\n");
	    return -1;
	}

	if (cur == NULL) {
	    prev = cur = head = node;
	} else {
	    cur -> next = node;
	    prev = cur;
	    cur = node;
	}
    }

    while (head) {
    	printf("%d ", head -> val);
    	head = head -> next;
    }

    putchar('\n');

    return 0;
}
