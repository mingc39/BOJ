#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _PW {
	char add[24];
	char pw[24];
} PW;

int compare(const void *a, const void *b) {
	PW *i, *j;
	i = (PW*)a;
	j = (PW*)b;
	return strcmp(i->add, j->add);
	//return strcmp(((PW*)a)->add, ((PW*)a)->add);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	PW* p = (PW*)malloc(sizeof(PW) * n);
	for(int i = 0; i < n; i++) {
		scanf("%s %s", p[i].add, p[i].pw);
	}
	qsort(p, n, sizeof(PW), compare);
	PW t;
	t.pw[0] = '\0';
	for(int i = 0; i < m; i++) {
		scanf("%s", t.add);
		t = *(PW*)bsearch((void *) &t, p, n, sizeof(PW), compare);
		printf("%s\n", t.pw);
	}
	return 0;
}