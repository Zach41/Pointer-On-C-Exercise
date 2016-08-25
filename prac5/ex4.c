#include <stdio.h>

void set_bit(char bit_array[], unsigned bit_number) {
    int idx, off;
    idx = bit_number / 8;
    off = 7 - bit_number % 8;

    bit_array[idx] |= (1 << off);
}

void clear_bit(char bit_array[], unsigned bit_number) {
    int idx, off;
    idx = bit_number / 8;
    off = 7 - bit_number % 8;

    bit_array[idx] &= ~(1 << off);
}

void assign_bit(char bit_array[], unsigned bit_number, int value) {
    if (value) {
	set_bit(bit_array, bit_number);
    } else {
	clear_bit(bit_array, bit_number);
    }
}

int test_bit(char bit_array[], unsigned bit_number) {
    int idx, off;
    idx = bit_number / 8;
    off = 7 - bit_number % 8;

    if (bit_array[idx] & (1 << off)) {
	return 1;
    } else {
	return 0;
    }
}

static void printBits(char bit_array[], int len) {
    for (int i=0; i<len; i++) {
	printf("%x ", bit_array[i]);
    }
    printf("\n");
}

int main() {
    char bit_array[] = {0, 4, 7};
    printBits(bit_array, 3);
    set_bit(bit_array, 0);
    printBits(bit_array, 3);

    clear_bit(bit_array, 21);
    printBits(bit_array, 3);

    assign_bit(bit_array, 19, 1);
    printBits(bit_array, 3);

    assign_bit(bit_array, 21, 0);
    printBits(bit_array, 3);

    if (test_bit(bit_array, 21)) {
	printf("True\n");
    } else {
	printf("False\n");
    }
    return 0;
}
