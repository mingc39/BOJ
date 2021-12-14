#include <stdio.h>

int main() {
	int n, m, s[100000], i, j;
	scanf("%d %d", &n, &m);
	scanf("%d", &s[0]);
	for(i = 1; i < n; i++) {
		scanf("%d", &j);
		s[i] = j + s[i - 1];
	}
	for(n = 0; n < m; n++) {
		scanf("%d %d", &i, &j);
		printf("%d\n", s[j - 1] - (i == 1 ? 0 : s[i - 2]));
	}
	return 0;
}
