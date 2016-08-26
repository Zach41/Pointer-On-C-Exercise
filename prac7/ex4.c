#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <assert.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)

int max_list(int n_values, ...) {
    va_list v_arg;
    int ans = INT_MIN;
    int value;
    va_start(v_arg, n_values);

    while (1) {
	value = va_arg(v_arg, int);
	if (value == -1)
	    break;
	ans = MAX(ans, value);
    }
    va_end(v_arg);
    
    return ans;
}

int main() {
    assert(max_list(5, 9, 4, 12, 32, -1) == 32);

    return 0;
}

