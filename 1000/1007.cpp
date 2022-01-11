#include <stdio.h>
#include <math.h>
#include <memory.h>

long long func(int* x, int* y, int n, int* u, int k, int l) {
	
	if(k == 0) {
		int sx = 0, sy = 0;
		
		for(int i = 0; i < n; i++) {
			if(u[i] == 1) {
				sx += x[i];
				sy += y[i];
			} else if(u[i] == 0) {
				sx -= x[i];
				sy -= y[i];
			}
		}
		
		return (long long)sx * sx + (long long)sy * sy;
	}
	
	long long m = 9000000000000000000, t;
	for(int i = l + 1; i <= n - k; i++) {
		u[i] = 1;
		t = func(x, y, n, u, k - 1, i);
		if(t < m) m = t;
		u[i] = 0;
	}
	return m;
}

int main() {
	int t, n, k, x[20], y[20], u[20];
	
	for(scanf("%d", &t); t > 0; t--) {
		// ют╥б  
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
		
		memset(u, 0, sizeof(int) * n);
		
		printf("%lf\n", sqrt(func(x, y, n, u, n / 2, -1)));
	}
	
	return 0;
}
