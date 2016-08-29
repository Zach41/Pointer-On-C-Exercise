#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int isstd = argc > 2 ? 0 : 1;

    char buf[1024];
    if (isstd) {
	int cur = 1;
	argv += 1;
	while (fgets(buf, 1024, stdin)) {
	    if (strstr(buf, *argv))
		printf("%d\n", cur);
	    cur ++;
	}
    } else {
	char *token = *++argv;
	while (*++argv) {
	    int cur = 1;
	    FILE* file = fopen(*argv, "r");
	    if (file == NULL) {
		perror(*argv);
		return -1;
	    }
	    while (fgets(buf, 1024, file)) {
		if (strstr(buf, token)) {
		    printf("%s:%d\n", *argv, cur);
		}
		cur += 1;
	    }
	}
    }

    return 0;
}
