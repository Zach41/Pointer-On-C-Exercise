#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

int array_offset(int arrayinfo[], ...) {
    if (!(arrayinfo[0] >= 1 && arrayinfo[0] <= 10))
	return -1;
    
    va_list v_arg;
    
    int idx[10], low[10], high[10];
    int dim = arrayinfo[0];

    va_start(v_arg, arrayinfo);
    for (int i=0; i<dim; i++) {
	idx[i] = va_arg(v_arg, int);
	low[i] = arrayinfo[i*2 + 1];
	high[i] = arrayinfo[2*i+2];
    }
    va_end(v_arg);

    for (int i=0; i<dim; i++)
	if (low[i] > high[i] || idx[i] > high[i] || idx[i] < low[i])
	    return -1;

    int off = idx[0] - low[0];
    for (int i=1; i<dim; i++) {
	off = off * (high[i] - low[i] + 1) + idx[i] - low[i];
    }

    return off;
}

int main() {
    int arrayinfo[] = {3, 4, 6, 1, 5, -3, 3};
    assert(array_offset(arrayinfo, 4, 1, -3) == 0);
    assert(array_offset(arrayinfo, 4, 1, 3) == 6);
    assert(array_offset(arrayinfo, 5, 1, -3) == 35);
    assert(array_offset(arrayinfo, 4, 1, -2) == 1);
    assert(array_offset(arrayinfo, 4, 2, -3) == 7);
    assert(array_offset(arrayinfo, 6, 3, 1) == 88);

    return 0;
}
