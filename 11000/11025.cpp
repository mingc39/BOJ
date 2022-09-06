#include <stdio.h>

int main() {
	int n, k, r = 1, i = 1;
	scanf("%d %d", &n, &k);
	++n; --k;
	while(++i != n) {
		r = (r + k) % i + 1;
	}
	printf("%d", r);
	return 0;
}
