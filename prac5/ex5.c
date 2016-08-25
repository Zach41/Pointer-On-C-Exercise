#include <stdio.h>

int store_bit_field(int original_value,
		    int value_to_store,
		    unsigned starting_bit,
		    unsigned ending_bit) {
    unsigned tot = sizeof(int) * 8 - 1;
    unsigned mask = (unsigned)~0;
    unsigned mask1 = mask >> (tot - starting_bit);
    unsigned mask2 = mask << (ending_bit);
    mask = mask1 & mask2;

    unsigned set_mask = original_value & (~mask);
    value_to_store <<= ending_bit;
    value_to_store &= mask;
    return value_to_store | set_mask;
}

int main() {
    printf("%x\n", store_bit_field(0x0, 0x1, 4, 4));
    printf("%x\n", store_bit_field(0xffff, 0x123, 15, 4));
    printf("%x\n", store_bit_field(0xffff, 0x123, 13, 9));
    return 0;
}
