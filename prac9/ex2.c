#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
 
 size_t my_strlen(char const *string, int size) {
     int length = 0;

     for (int i=0; i<size; i++) {
	 if (*(string + i) == '\0')
	     break;
	 length += 1;
     }

     return length;
 }

int main() {
    char str[6] = "abcd";

    assert(my_strlen(str, 6) == 4);
    str[4] = 'h';
    str[5] = 'e';
    assert(my_strlen(str, 6) == 6);

    return 0;
}
