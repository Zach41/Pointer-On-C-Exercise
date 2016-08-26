#include <stdio.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
    for (int i=0; i<x; i++) {
	for (int j=0; j<z; j++) {
	    int tmp = 0;
	    for (int k=0; k<y; k++) {
		tmp += (*(m1 + i*y + k)) * (*(m2 + k*z + j));
	    }
	    *(r + z*i + j) = tmp;
	}
    }
}

void print_matrix(int *m, int x, int y) {
    for (int i=0; i<x; i++) {
	for (int j=0; j < y; j++) {
	    printf("%d ", *(m + i*y + j));
	}
	putchar('\n');
    }
}
int main() {
    int matrix1[][2] = {{2, -6},
		       {3, 5},
		       {1, -1}};
    int matrix2[][4] = {{4, -2, -4, -5},
			{-7, -3, 6, 7}};

    int res[3][4];

    matrix_multiply(matrix1[0], matrix2[0], res[0], 3, 2, 4);

    print_matrix(res[0], 3, 4);

    return 0;
}
