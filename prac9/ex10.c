#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

int palindrome(char *string) {
    if (*string == '\0')
	return 1;
    
    char* tail = string;

    while (*tail) tail++;
    tail -= 1;
    char* head = string;
    while (head < tail) {
	if (tolower(*head) != tolower(*tail))
	    return 0;
	tail--, head++;
    }

    return 1;
}

int main() {
    char* s = "12321";
    assert(palindrome(s) == 1);

    char* s2 = "12345";
    assert(palindrome(s2) == 0);

    return 0;
}
