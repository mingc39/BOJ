#include <stdio.h>

int main() {
	int a, b;
	scanf("%d", &a);
	for(b = 1; a > 0; a--) b *= a;
	printf("%d", b);
	
	return 0;
}
