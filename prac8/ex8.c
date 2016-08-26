#include <stdio.h>
#include <string.h>

int check(int x, int y, int *m) {
    for (int i=0; i<x; i++) {
	if (*(m + i*8 + y) == 1)
	    return 0;
    }

    for (int i=x-1, j=y-1; i>=0 && j>=0; i--, j--) {
	if (*(m + i*8 + j) == 1)
	    return 0;
    }

    for (int i=x-1, j=y+1; i>=0 && j<8; i--, j++)
	if (*(m + i*8 + j) == 1)
	    return 0;
    return 1;
}

void print_matrix(int *m) {
    for (int i=0; i<8; i++) {
	for (int j=0; j<8; j++)
	    printf("%d ", *(m + i*8 + j));
	putchar('\n');
    }

    putchar('\n');
}

void queens(int x, int *m) {
    if (x >= 8) {
	print_matrix(m);
	return;
    }

    for (int i=0; i<8; i++) {
	if (check(x, i, m)) {
	    *(m + x*8 + i) = 1;
	    queens(x+1, m);
	    *(m + x*8 + i) = 0;
	}
    }
}

int main() {
    int m[8][8];
    for (int i=0; i<8; i++)
	for (int j=0; j<8; j++)
	    m[i][j] = 0;

    queens(0, m[0]);

    return 0;
}
