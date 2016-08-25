#include <stdio.h>

void reverse_string(char* string) {
    if (*string == '\0')
	return;

    char *head = string;
    char *tail = string;

    while (*tail!= 0) tail++;

    tail -= 1;

    while (head < tail) {
	char tmp = *head;
	*head = *tail;
	*tail = tmp;
	head++, tail--;
    }
}

int main() {
    char str[] = "ABSCD";

    reverse_string(str);
    printf("%s\n", str);

    char str2[] = "ABCD";
    reverse_string(str2);
    printf("%s\n",str2);

    char str3[] = "";
    reverse_string(str3);
    printf("%s\n", str3);

    return 0;
}
