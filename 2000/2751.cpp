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
	int N, *n;
	n = (int*)malloc(sizeof(int) * 1000000);
	scanf("%d", &N);
	for(int i = 0 ; i < N; i++) scanf("%d", &n[i]);
    qsort(n, N, sizeof(int), compare);
	for(int i = 0 ; i < N; i++) printf("%d\n", n[i]);
	return 0;
}