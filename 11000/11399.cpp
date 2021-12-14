#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int i = *(int *)a;
    int j = *(int *)b;
    
    if(i < j) return -1;
    if(i > j) return 1;
    return 0;
}

int main() {
	int n, t = 0, p[1000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &p[i]);
	qsort(p, n, sizeof(int), compare);
	for(int i = 0; i < n; i++) t += p[i] * (n - i);
	printf("%d", t);
	return 0;
}
