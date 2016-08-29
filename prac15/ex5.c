#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[FILENAME_MAX], output[FILENAME_MAX];

    printf("Please input two file name:\n");

    scanf("%s %s", input, output);

    FILE* in_file = fopen(input, "r");
    if (in_file == NULL) {
	perror(input);
	exit(EXIT_FAILURE);
    }

    FILE* out_file = fopen(output, "w");
    if (out_file == NULL) {
	perror(output);
	exit(EXIT_FAILURE);
    }

    char buf[1024];
    int sum = 0, x;
    while (fgets(buf, 1024, in_file)) {
	if (sscanf(buf, "%d", &x) == 1) {
	    sum += x;
	}
	fputs(buf, out_file);
    }

    fprintf(out_file, "%d", sum);

    /* not neccessary */
    fclose(in_file);
    fclose(out_file);

    return 0;
}
