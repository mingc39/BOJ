#include <stdio.h>

int main() {
	int n;
	int a, b, t;
	
	scanf("%d", &n);
	
	a = 1; b = 1;
	for(int i = 2; i < n; i++) {
		t = a + b;
		a = b;
		b = t;
	}
	
	printf("%d", b);
	
	return 0;
}
