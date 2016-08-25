#include <stdio.h>

char *find_char(char const *source, char const *chars) {
    if (source == NULL || chars == NULL || *source == '\0' || *chars == '\0')
	return NULL;
    while (*chars != 0) {
	char* head = source;

	while (*head != 0) {
	    if (*head == *chars) {
		return head;
	    }
	    head += 1;
	}
	chars += 1;
    }
    return NULL;
}

int main() {
    char* source = "ABCDEF";

    printf("%s\n", find_char(source, "XYZ") == NULL ? "Not Found" : "Found");

    printf("%s\n", find_char(source, "JURY") == NULL ? "Not Found" : "Found");

    printf("%s\n", find_char(source, "XRCQEF") == NULL ? "Not Found" : "Found");

    printf("%s\n", find_char(source, "") == NULL ? "Not Found" : "Found");

    printf("%s\n", find_char("", "XRCQEF") == NULL ? "Not Found" : "Found");

    printf("%s\n", find_char(NULL, "XXX") == NULL ? "Not Found" : "Found");

    return 0;
}
