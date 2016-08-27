#include <stdio.h>

#include "alloc.h"

int* read_arr() {
    int cnt;

    scanf("%d", &cnt);

    int* arr = MALLOC(cnt, int);
    int i = 0;
    while (i < cnt) {
	scanf("%d", arr + i);
	i += 1;
    }

    for (i=0; i<cnt; i++)
	printf("%d ", arr[i]);
    putchar('\n');
    return arr;
}

int main() {
    read_arr();

    return 0;
}

