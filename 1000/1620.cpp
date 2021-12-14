#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _PK{
	char name[24];
	int id;
} PK;

int compare(const void *a, const void *b) {
	return strcmp(((PK*)a)->name, ((PK*)b)->name);
}

int main() {
	int n, m;
	char (*name)[24];
	PK *dogam;
	scanf("%d %d", &n, &m);
	dogam = (PK*)malloc(sizeof(PK) * n);
	name = (char (*)[24])malloc(sizeof(char) * 24 * n);
	for(int i = 0; i < n; i++) {
		scanf("%s", dogam[i].name);
		dogam[i].id = i + 1;
		strcpy(name[i], dogam[i].name);
	}
	
	qsort(dogam, n, sizeof(PK), compare);
	
	PK input;
	PK *t;
	int num, i;
	while(m-- > 0) {
		scanf("%s", input.name);
		if(input.name[0] <= '9' && input.name[0] >= '0') {
			num = input.name[0] - '0'; i = 0;
			while(input.name[++i] != '\0') num = num * 10 + input.name[i] - '0';
			printf("%s\n", name[num - 1]);
		} else {
			t = (PK*)bsearch(&input, dogam, n, sizeof(PK), compare);
			printf("%d\n", t->id);
		}
	}
	
	return 0;
}
