#include <stdio.h>
#include <assert.h>

int gcd(int m, int n) {
    if (m <= 0 || n <= 0)
	return 0;

    if (m < n)
	return gcd(n, m);
    while (m % n) {
	int tmp = n;
	n = m % n;
	m = tmp;
    }
    return n;
}

int gcd_recur(int m, int n) {
    if (m <= 0 || n <= 0)
	return 0;
    if (m < n)
	return gcd_recur(n, m);
    if (m % n == 0)
	return n;
    return gcd_recur(n, m % n);
}

int main() {
    int ret = gcd(12, 9);
    assert(ret == 3);

    ret = gcd_recur(12, 9);
    assert(ret == 3);

    return 0;
}
