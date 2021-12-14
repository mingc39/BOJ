#include <stdio.h>
#include <stdlib.h> 

int main() {
	int *n;
	n = (int*)calloc(20000001, sizeof(int));
	int num, tmp;
	scanf("%d", &num);
	for(int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		n[tmp + 10000000]++;
	}
	scanf("%d", &num);
	for(int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		printf("%d ", n[tmp + 10000000]);
	}
	return 0;
}
