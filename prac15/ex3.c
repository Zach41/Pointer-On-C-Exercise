#include <stdio.h>

const int BUF_SIZE = 81;

int main() {
    char buf[BUF_SIZE];

    while (fgets(buf, BUF_SIZE, stdin)) {
	printf("\nDEBUG\n");
	fputs(buf, stdout);
    }

    return 0;
}
