#include <stdio.h>

int hermite(int n, int x) {
    if (n <= 0)
	return 1;
    if (n == 1)
	return 2 * x;
    return 2 * x * hermite(n-1, x) - 2 * (n-1) * hermite(n-2, x);	    
}

int main() {
    printf("H1(2) = %d\n", hermite(1, 2));

    printf("H5(6) = %d\n", hermite(5, 6));

    return 0;
}
