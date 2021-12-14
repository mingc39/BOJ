#include <stdio.h>

int main() {
	int T, k, n;
	scanf("%d", &T);
	long long c;
	for(int j = 0; j < T; j++) {
		scanf("%d %d", &k, &n);
		c = 1;
		for(int i = k + n; i > k + 1; i--) c *= i;
		for(int i = n - 1; i > 0; i--) c /= i;
		printf("%ld\n", c);
	}
	return 0;
}
