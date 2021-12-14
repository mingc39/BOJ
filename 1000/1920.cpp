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
	int N, n[100000], M, m[100000], i, j;
	scanf("%d", &N);
	for(i = 0 ; i < N; i++)
		scanf("%d", &n[i]);
    
    qsort(n, N, sizeof(int), compare);
	
	scanf("%d", &M);
	for(i = 0 ; i < M; i++) {
		scanf("%d", &m[i]);
		if(bsearch((void *) &m[i], n, N, sizeof(int), compare) == NULL) printf("0\n");
        else printf("1\n");
	}
}
