#include <stdio.h>

int main() {
    int age[10], i = 0;
    int sum = 0;
    int ch;
    while ((ch = fgetc(stdin)) != EOF) {
	if (ch == '\n') {
	    printf("%5.2f : ", (double)sum / i);
	    for (int k=0; k<i; k++)
		printf("%d ", age[k]);
	    putchar('\n');
	    sum = 0, i = 0;
	}
	ungetc(ch, stdin);
	scanf("%d", &age[i]);
	sum += age[i++];
    }

    return 0;
}
