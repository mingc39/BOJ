#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int s, t;
	for(int i = 0; i < n; i++) {
		for(s = t = i; t > 0; s += t % 10, t /= 10);
		if(s == n) { printf("%d", i); return 0; }
	}
	printf("0");
	return 0;
}
