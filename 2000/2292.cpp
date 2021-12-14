#include <stdio.h>

int main() {
	int n, i = 1;
	scanf("%d", &n);
	while(3 * i * (i - 1) + 1 < n) i++;
	printf("%d", i);
	return 0;
}
