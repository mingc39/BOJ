#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int i = 1, j = 0, t;
	for(; n > 0; n--) {
		t = i + 2 * j;
		j = i;
		i = t % 10007;
	}
	printf("%d", i);
	return 0;
}
