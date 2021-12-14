#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, k, *a, s = 0;;
	scanf("%d %d", &n, &k);
	a = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = n - 1; i >= 0; i--) {
		if(k == 0) break;
		s += k / a[i];
		k  = k % a[i];
	}
	printf("%d", s);
	return 0;
}
