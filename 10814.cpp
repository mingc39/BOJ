#include <stdio.h>
#include <stdlib.h>

typedef struct _Member {
	char name[128];
	int age;
	int num;
} Member;

int compare(const void *a, const void *b) {
    Member i = *(Member *)a;
    Member j = *(Member *)b;
    
    if(i.age < j.age) return -1;
    if(i.age > j.age) return 1;
    if(i.num < j.num) return -1;
    if(i.num > j.num) return 1;
    return 0;
}

int main() {
	int n;
	Member *m;
	m = (Member*)malloc(100000 * sizeof(Member));
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %s", &m[i].age, m[i].name);
		m[i].num = i;
	}
	qsort(m, n, sizeof(Member), compare);
	int r = -1;
	for(int i = 0; i < n; i++) {
		printf("%d %s\n", m[i].age, m[i].name);
	}
	
	return 0;
}