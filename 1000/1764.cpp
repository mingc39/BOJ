#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
	return strcmp(*(char**)a, *(char**)b);
}


int main() {
	int n, m, c = 0;
	char *np, t[24];
	char **N, **M, **T;
	void* ptr;
	scanf("%d %d", &n, &m);
	N = (char**)malloc(sizeof(char*) * n);
	M = (char**)malloc(sizeof(char*) * n);
	N[0] = (char*)malloc(sizeof(char) * n * 24);
	for(int i = 1; i < n; i++) N[i] = N[i - 1] + 24;
	for(int i = 0; i < n; i++) scanf("%s", N[i]);
	qsort(N, n, sizeof(char*), compare);
	for(int i = 0; i < m; i++) {
		scanf("%s", t);
		T = (char**)t;
		ptr = bsearch(&T, N, n, sizeof(char*), compare);
		if(ptr != NULL) {
			M[c++] = *(char**)ptr;
		}
	}
	qsort(M, c, sizeof(char*), compare);
	printf("%d\n", c);
	for(int i = 0; i < c; i++) printf("%s\n", M[i]);
	return 0;
}
