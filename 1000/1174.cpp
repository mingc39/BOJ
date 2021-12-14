#include <stdio.h>

int comb(int n, int r);

int main() {
	
	int N;
	int c10[11];
	int ans[10] = {0, };
	
	scanf("%d", &N);
	
	for(int i = 0; i <= 10; i++) c10[i] = comb(10, 0);
	
	if(N > (1 << 10) - 1) {
		printf("-1");
		return 0;
	}
	
	int c = 0;
	int l = 0;
	
	for(int i = 1; i <= 10; i++) {
		if(c + comb(10, i) >= N) {
			l = i;
			break;
		}
		c += comb(10,i);
	}
	
	c = N - c;
	
	int ci = 0, li = l;
	
	while(li > 0) {
		
		ci = 0;
		for(int i = li - 1; i < 10; i++) {
			if(ci + comb(i, li - 1) >= c) {
				ans[10 - li] = i;
				li--;
				c = c - ci;
				break;
			}
			ci += comb(i, li - 1);
		}
		
		
	}
	
	for(int i = 10 - l; i < 10; i++) printf("%d", ans[i]);
	
	return 0;
}

int comb(int n, int r) {
	
	if(r < 0 || r > n) return 0;
	
	if(r > n / 2) r = n - r;
	
	int a = 1;
	for(int i = n; i > n - r; i--) a *= i;
	
	int b = 1;
	for(int i = r; i > 0; i--) b *= i;
	
	return a / b;
}