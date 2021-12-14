#include <stdio.h>

int main() {
	int a, b, c[10] = {0,};
	scanf("%d", &a);
	scanf("%d", &b);
	a *= b;
	scanf("%d", &b);
	a *= b;
	
	while(a > 0) {
		c[a % 10]++;
		a /= 10;
	}
	
	printf("%d\n", c[0]);
	printf("%d\n", c[1]);
	printf("%d\n", c[2]);
	printf("%d\n", c[3]);
	printf("%d\n", c[4]);
	printf("%d\n", c[5]);
	printf("%d\n", c[6]);
	printf("%d\n", c[7]);
	printf("%d\n", c[8]);
	printf(  "%d", c[9]);
	
	return 0;
}
