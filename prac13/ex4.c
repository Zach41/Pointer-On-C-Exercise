#include <stdio.h>

static void swap(void* p1, void* p2, int size) {
    char* cp1 = (char *)p1;
    char* cp2 = (char *)p2;

    for (int i=0; i<size; i++) {
	char ch = *(cp1 + i);
	*(cp1 + i) = *(cp2 + i);
	*(cp2 + i) = ch;
    }
}

void sort(void* list,
	  int num,
	  int size,
	  int (*cmp)(void const *value1, void const *value2)) {
    /* 冒泡排序 */
    for (int i=0; i<num; i++) {
	for (int j=i+1; j<num; j++) {
	    if (cmp(list + i*size, list + j*size) > 0) {
		swap(list + i*size, list + j*size, size);
	    }
	}
    }
}

typedef struct node {
    int val1;
    int val2;
} Node;

int cmp(void const *p1, void const *p2) {
    Node* node1 = (Node *)p1;
    Node* node2 = (Node *)p2;

    if (node1 -> val1 > node2 -> val1)
	return 1;
    else if (node1 -> val1 < node2 -> val1)
	return -1;
    else
	return 0;
}

int main() {
    Node list[] = {{1, 3}, {4, 2}, {3, 2}};

    sort(list, 3, sizeof(Node), cmp);

    for (int i=0; i<3; i++) {
	printf("%d %d\n", list[i].val1, list[i].val2);
    }

    return 0;
}
