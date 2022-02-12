#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int a[300000], n;
	long long p = 1, s = 0;
	 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	qsort(a, n, sizeof(int), cmp);
	
	for(int i = 0; i < n; i++) {
		s = (s + a[i] * (p - 1) - a[n - i - 1] * (p - 1)) % 1000000007;
		p = (p * 2) % 1000000007;
	}
	
	printf("%d", (int)s);
	
	return 0;
}
