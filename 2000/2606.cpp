#include <stdio.h>

int main() {
	int n, m;
	int c[101][101] = {0,};
	
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= 101; i++) c[i][i] = 1;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		c[a][b] = 1;
		c[b][a] = 1;
	}
	
	for(int k = 0; k < n; k++) {
		for(int i = 1; i <= n; i++) {
			if(c[i][1] == 0) continue;
			for(int j = 1; j <= n; j++) {
				if(c[i][j] != 0) {
					c[j][1] = 1;
					c[1][j] = 1;
				}
			}
		}
	}

	int s = 0;
	for(int i = 2; i <= n; i++) s += c[1][i];
	printf("%d", s);
	
	return 0;
}
