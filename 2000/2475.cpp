#include <stdio.h>

int main() {
	int n, s = 0;
	
	for(int i = 0; i < 5; i++) {
		scanf("%d", &n);
		s += n * n;
	}
	
	putchar(s % 10 + '0');
	
	return 0;
}
