#include <stdio.h>

int main() {
	int t, n, f[42];
	f[0] = 1;
	f[1] = 0;
	for(t = 2; t < 42; t++) f[t] = f[t - 2] + f[t - 1];
	scanf("%d", &t);
	for(; t > 0; t--) {
		scanf("%d", &n);
		printf("%d %d\n", f[n], f[n + 1]);
	}
	return 0;
}
