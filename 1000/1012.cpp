#include <stdio.h>

void s(int a[50][50], int x, int y, int m, int n, int v) {
	if(a[x][y] != 1) return;
	a[x][y] = v;
	if(x < m - 1) s(a, x + 1, y, m, n, v);
	if(y < n - 1) s(a, x, y + 1, m, n, v);
	if(x > 0)     s(a, x - 1, y, m, n, v);
	if(y > 0)     s(a, x, y - 1, m, n, v);
}

int main() {
	int x, y, w;
	int t, m, n, k;
	int a[50][50];
	int b[2500];
	int c[2500];
	
	for(scanf("%d", &t); t > 0; t--) {
		
		scanf("%d %d %d", &m, &n, &k);
		
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				a[i][j] = 0;
		
		for(int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			a[x][y] = 1;
			b[i] = x;
			c[i] = y;
		}
		
		w = 0;
		for(int i = 0; i < k; i++) {
			x = b[i]; y = c[i];
			if(a[x][y] != 1) continue;
			w = w + 1;
			s(a, x, y, m, n, 0);
		}
		
		printf("%d\n", w);
	}
	
	return 0;
}
