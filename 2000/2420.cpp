#include <stdio.h>

int main() {
	long long a, b, c;
	scanf("%lld %lld", &a, &b);
	c = a - b;
	if(c < 0) c = -c;
	printf("%lld", c);
	
	return 0;
}
