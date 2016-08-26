#include <stdio.h>
#include <string.h>

int cnt_the(const char* string) {
    int cnt = 0;

    char *current = strstr(string, "the");

    while (current != NULL) {
	cnt += 1;
	current = strstr(current+1, "the");
    }	

    return cnt;
}

int main() {
    char buf[256];
    gets(buf);

    printf("Number: %d\n", cnt_the(buf));

    return 0;
}
