#include <stdio.h>

int main() {
	int c[42] = {0,};
	int n;
	
	for(int i = 0; i < 10; i++) {
		scanf("%d", &n);
		c[n % 42] = 1;
	}
	
	n = 0;
	for(int i = 0; i < 42; i++) {
		n += c[i];
	}
	
	printf("%d", n);
	
	return 0;
}
