#include <stdio.h>
#include <assert.h>

int identiy_matrix(int *matrix, int n) {
    for (int i=0; i < n; i++) {
	for (int j=0; j<n; j++) {
	    if (i==j && (*(matrix + i*n + j) != 1))
		return 0;
	    if (i != j && (*(matrix + i*n + j) != 0))
		return 0;
	}
    }
    return 1;
}

int main() {
    int matrix[][3] = {{1, 0, 0},
		       {0, 1, 0},
		       {0, 0, 1}};
    assert(identiy_matrix(&matrix[0][0], 3) == 1);

    int matrix2[][2] = {{1, 1},
			{1, 1}};
    assert(identiy_matrix(&matrix2[0][0], 2) == 0);
    
}
