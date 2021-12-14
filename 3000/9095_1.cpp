#include <stdio.h>

int main() {
	int t, n, r[10] = {1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
	for(scanf("%d", &t); t > 0; t--) {
		scanf("%d", &n);
		printf("%d\n", r[n - 1]);
	}
	return 0;
}