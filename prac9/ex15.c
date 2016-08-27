#include <stdio.h>
#include <string.h>

void dollars(char *dest, char const *src) {
    *dest++ = '$';
    int len = strlen(src);
    if (len <= 2)
	*dest++ = '0';
    len -= 2;
    while (len > 0) {
	if (len % 3 == 0) {
	    strncpy(dest, src, 3);
	    src += 3, dest += 3;	 
	    len -= 3;
	} else {
	    strncpy(dest, src, len % 3);
	    src += len % 3, dest += len % 3;
	    len -= len % 3;
	}
	if (len != 0)
	    *dest++ = ',';
    }
    *dest++ = '.';
    for (int i=0; i<(2 - (int)strlen(src)); i++)
	*dest++ = '0';
    while (*src)
	*dest++ = *src++;
    *dest = 0;
}

int main() {
    char input[] = "";
    char dest[256];

    dollars(dest, input);
    printf("%s\n", dest);

    dollars(dest, "1");
    printf("%s\n", dest);

    dollars(dest, "12");
    printf("%s\n", dest);

    dollars(dest, "123");
    printf("%s\n", dest);

    dollars(dest, "1234");
    printf("%s\n", dest);

    dollars(dest, "123456788");
    printf("%s\n", dest);

    return 0;
}
