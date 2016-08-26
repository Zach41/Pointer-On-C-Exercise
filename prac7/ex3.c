#include <stdio.h>

int ascii_to_integer(char *string) {
    int ret = 0;

    while (*string) {
	if (!(*string <= '9' && *string >= '0'))
	    return 0;
	ret = ret*10 + (*string - '0');
	string++;
    }
    return ret;
}

int main() {
    printf("%d\n", ascii_to_integer("12234"));
    printf("%d\n", ascii_to_integer("12a3"));
    printf("%d\n", ascii_to_integer(""));

    return 0;
}
