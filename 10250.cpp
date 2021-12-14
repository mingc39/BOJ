#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	int h, w, n;
	int x, y;
	for(int i = 0; i < T; i++) {
		scanf("%d %d %d", &h, &w, &n);
		x = n / h;
		if(n % h != 0) x = x + 1;
		y = n % h;
		if(y == 0) y = h;
		printf("%d%02d\n", y, x);
	}
	return 0;
}
