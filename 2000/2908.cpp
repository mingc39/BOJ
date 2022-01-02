#include <stdio.h>

int main() {
	int a, b, t;
	
	scanf("%d %d", &a, &b);
	
	for(t = 0; a > 0; a /= 10) t = t * 10 + a % 10;
	a = t;
	for(t = 0; b > 0; b /= 10) t = t * 10 + b % 10;
	b = t;
	
	printf("%d", a > b ? a : b);
	
	return 0;
}
