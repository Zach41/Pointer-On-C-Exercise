#include <stdio.h>

const int BUF_SIZE = 128;

int main() {
    char buf[BUF_SIZE];

    while (fgets(buf, BUF_SIZE, stdin) != NULL) {
	fputs(buf, stdout);
    }

    return 0;
}
