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
	int N, *n, *m, p = 1, *s;
	scanf("%d", &N);
	n = (int*)malloc(sizeof(int) * N);
	m = (int*)malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &n[i]);
		m[i] = n[i];
	}
    qsort(m, N, sizeof(int), compare);
    for(int i = 1; i < N; i++) {
    	if(m[i] != m[i - 1]) m[p++] = m[i];
	}
	for(int i = 0; i < N; i++) {
    	s = (int*)bsearch((void *) &n[i], m, p, sizeof(int), compare);
    	if(s == NULL) {
    		printf("-1 ");
    		continue;
		}
		printf("%d ", (s - m));
	}
	return 0;
}
