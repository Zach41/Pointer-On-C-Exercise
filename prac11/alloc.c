#include <stdio.h>

#include "alloc.h"
#undef malloc

void* alloc(size_t size) {
    void* new_mem;

    new_mem = malloc(size);

    if (new_mem == NULL) {
	printf("Out of Memory.\n");
	exit(1);
    }

    return new_mem;
}
