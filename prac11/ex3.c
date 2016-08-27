#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cpy_str() {
    int ini_size = 128, cur_size = 0;

    char* input = (char *)malloc(ini_size * sizeof(char));
    if (input == NULL) {
	printf("Out of Memory.\n");
	exit(1);
    }
    char ch;
    while ((ch = getchar()) != '\n') {
	*(input + cur_size) = ch;
	cur_size += 1;
	if (cur_size >= ini_size - 1) {
	    ini_size *= 2;
	    input = (char *)realloc(input, ini_size);
	    if (input == NULL) {
		printf("Out of Memory.\n");
		exit(1);
	    }
	}
    }
    *(input + cur_size) = '\0';

    return input;
}

int main() {
    char* ret = cpy_str();

    printf("%s\n", ret);

    return 0;
}
