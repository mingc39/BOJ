#include <stdio.h>

int main() {
	int k[100000], n, t, pos = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &t);
		if(t == 0) {
			pos--;
		} else {
			k[pos] = t;
			pos++;
		}
	}
	long long sum = 0;
	for(int i = 0; i < pos; i++) sum += k[i];
	printf("%lld", sum);
	return 0;
}
