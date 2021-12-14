#include <stdio.h>

int main() {
	int n, k, i, p, c;
	int t[1000] = { 0, };
	scanf("%d %d", &n, &k);
	
	for(i = 0; i < n; i++) t[i] = i + 1;
	
	printf("<");
	p = -1;
	for(i = 0; i < n; i++) {
		
		c = 0;
		while(c < k) {
			p++;
			if(p >= n) p %= n;
			if(t[p] != 0) c++;
		}
		
		if(i < n - 1) printf("%d, ", t[p]);
		else printf("%d>", t[p]);
		t[p] = 0;
		
	}
	
	
	return 0;
}