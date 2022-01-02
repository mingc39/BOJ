#include <stdio.h>

int main() {
	int n;
	int a, b, t;
	
	scanf("%d", &n);
	if(n == 0) { putchar('0'); return 0; }
	
	a = 1; b = 1;
	for(int i = 2; i < n; i++) {
		t = (a + b) % 1000000007;
		a = b;
		b = t;
	}
	
	printf("%d", b);
	
	return 0;
}
