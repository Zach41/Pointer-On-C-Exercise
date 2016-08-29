#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[FILENAME_MAX];

    printf("Please input file name: ");
    scanf("%s", input);
    
    FILE* in_file = fopen(input, "r");
    if (in_file == NULL) {
	perror(input);
	exit(EXIT_FAILURE);
    }

    char buf[17];

    int off = 0;
    int cnt = 0;
    while (fgets(buf, 17, in_file)) {
	printf("%06x  ", off);
	while (*(buf+cnt)) {
	    printf("%x", *(buf + cnt));
	    cnt += 1;
	    if (cnt % 4 == 0)
		putchar(' ');
	}
	printf(" *");
	cnt = 0;
	while (*(buf + cnt)) {
	    char ch = *(buf + cnt);
	    if (isprint(ch) && !isspace(ch)) {
		putchar(ch);
	    } else
		putchar('.');
	    cnt += 1;
	}
	printf("*\n");
	off += 16;
	cnt = 0;
    }
    return 0;
}
