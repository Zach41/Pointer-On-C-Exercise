#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

void print_integer(int n) {
    printf("%d", n);
}

void print_float(double f) {
    printf("%f", f);
}

void my_printf(const char* fmt, ...) {
    va_list v_arg;

    va_start(v_arg, fmt);
    
    while (*fmt) {
	if (*fmt == '%') {
	    fmt += 1;
	    
	    switch(*fmt) {
	    case 'd': {
		int value = va_arg(v_arg, int);
		print_integer(value);
		break;
	    }
	    case 'f': {
		double f = va_arg(v_arg, double);
		print_float(f);
		break;
	    }
	    case 's': {
		char* str = va_arg(v_arg, char*);
		while (*str) {
		    putchar(*str++);
		}
		break;
	    }
	    case 'c': {
		/* avoid undefined behavior */
		char ch = (char) va_arg(v_arg, int);
		putchar(ch);
		break;
	    }
	    default:
		break;
	    }
	} else {
	    putchar(*fmt);
	}
	fmt += 1;
    }
}

int main() {
    my_printf("hello, test. %d\n%f\n%c\n%s\n", 12, 12.3, 'c', "Hello World.");

    return 0;
}
