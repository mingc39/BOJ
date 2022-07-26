#include <stdio.h>

// 수열에서 a까지의 합 
int sum(int a) {
	int n = 0;
	while(n * (n + 1) / 2 < a) ++n;
	return ((n - 1) * n * (2 * n - 1) / 6) + ((a - n * (n - 1) / 2) * n);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", sum(b) - sum(a - 1));
	
	return 0;
}
