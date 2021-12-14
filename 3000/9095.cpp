#include <stdio.h>

int main() {
	int t, n, r[10];
	r[0] = 1;
	r[1] = 1 + r[0];
	r[2] = 1 + r[1] + r[0];
	for(t = 3; t < 10; t++) r[t] = r[t - 1] + r[t - 2] + r[t - 3];
	for(scanf("%d", &t); t > 0; t--) {
		scanf("%d", &n);
		printf("%d\n", r[n - 1]);
	}
	return 0;
}