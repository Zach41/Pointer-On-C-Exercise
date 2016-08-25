#include <stdio.h>

unsigned int reverse_bits(unsigned int value) {
    unsigned int ans = 0;
    int off = sizeof(ans) * 8 - 1;
    
    while (value) {
	ans |= (value & 1) ? (1 << off) :  0;
	value >>= 1;
	off -= 1;
    }

    return ans;
}

int main() {
    unsigned int value = 0xD8;
    printf("Reversed: %x\n", reverse_bits(value));

    return 0;
}
    
