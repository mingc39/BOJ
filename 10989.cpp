#include <stdio.h>

int main() {
	int n, t, c[10000] = { 0, };
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		c[t - 1]++;
	}
	for(int i = 0; i < 10000; i++)
		for(int j = 0; j < c[i]; j++)
			printf("%d\n", i + 1);
	return 0;
}