#include <stdio.h>
#include <string.h>

char *specs[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
		 "eighteen", "nineteen"};
char *units[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

char *decades[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"};

 void written_amount(unsigned int amount, char* buffer) {
     
     if (amount < 100) {
	 char buf[256];
	 if (amount < 20 && amount >= 10) {
	     sprintf(buf, "%s ", specs[amount - 10]);
	 }
	 else if (amount < 10 && amount > 0) {
	     sprintf(buf, "%s ", units[amount-1]);
	 }
	 else if (amount >= 20) {
	     if (amount % 10 != 0)
		 sprintf(buf, "%s %s ", decades[amount / 10 - 2], units[amount % 10 - 1]);
	     else
		 sprintf(buf, "%s ", decades[amount / 10 - 2]);
	 }
	 strcat(buffer, buf);
	 return;
     }

     if (amount >= 100 && amount < 1000) {
	 char buf[256];
	 sprintf(buf, "%s hundred ", units[amount / 100 - 1]);
	 strcat(buffer, buf);
	 written_amount(amount % 100, buffer);
     } else if (amount < 1000000) {
	 char buf[256];
	 written_amount(amount / 1000, buffer);
	 sprintf(buf, "thousand ");
	 strcat(buffer, buf);
	 written_amount(amount % 1000, buffer);
     } else if (amount < 1000000000) {
	 char buf[256];
	 written_amount(amount / 1000000, buffer);
	 sprintf(buf, "million ");
	 strcat(buffer, buf);
	 written_amount(amount % 1000000, buffer);
     } else {
	 char buf[256];
	 written_amount(amount / 1000000000, buffer);
	 sprintf(buf, "billion ");
	 strcat(buffer, buf);
	 written_amount(amount % 1000000000, buffer);
     }
 }

int main() {
    char buffer[256];

    written_amount(16312, buffer);
    printf("%s\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    written_amount(1663120, buffer);
    printf("%s\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    written_amount(4294967295, buffer);
    printf("%s\n", buffer);
    return 0;
}
