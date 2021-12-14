#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long i = *(long long *)a;
    long long j = *(long long *)b;
    
    if(i < j) return -1;
    if(i > j) return 1;
    return 0;
}

int main() {
	int n;
	int x, y;
	long long c[100000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		c[i] = ((long long)x + 100000) * 1000000 + (y + 100000);
	}
	qsort(c, n, sizeof(long long), compare);
	for(int i = 0; i < n; i++) {
		printf("%d %d\n", c[i] / 1000000 - 100000, c[i] % 1000000 - 100000);
	}
	return 0;
}
