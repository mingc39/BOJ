#include <stdio.h>
#include <stdlib.h>

typedef struct _Mt{
	int s;
	int e;
} Mt;

int compare(const void *a, const void *b) {
    Mt i = *(Mt *)a;
    Mt j = *(Mt *)b;
    
    if(i.e < j.e) return -1;
    if(i.e > j.e) return 1;
    if(i.s < j.s) return -1;
    if(i.s > j.s) return 1;
    return 0;
}

int main() {
	
	int n;
	Mt* m;
	
	scanf("%d", &n);
	m = (Mt*)malloc(sizeof(Mt) * n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &m[i].s, &m[i].e);
	
	qsort(m, n, sizeof(Mt), compare);
	
	int e, c = 1;
	e = m[0].e;
	for(int i = 1; i < n; i++) {
		if(e > m[i].s) continue;
		e = m[i].e;
		c++;
	}
	
	printf("%d", c);
	
	return 0;
}
