#include <stdio.h>

int main() {
	int n;
	int a[384] = {0,}, b[384] = {0,};
	int *p1, *p2, *t;
	
	scanf("%d", &n);
	if(n == 0) { putchar('0'); return 0; }
	
	a[0] = 1; b[0] = 1;
	p1 = a; p2 = b;
	
	for(int i = 2; i < n; i++) {
		for(int j = 0; j < 384; j++) {
			p2[j] += p1[j];
			if(p2[j] > 99999999) {
				p2[j + 1] += p2[j] / 100000000;
				p2[j] %= 100000000;
			}
		}
		t = p1;
		p1 = p2;
		p2 = t;
	}
	
	/*for(int i = 126; i >= 0; i--) {
		if(p1[i] != 0) printf("%d: %d\n", i, p1[i]);
	}*/
	
	for(int i = 380; i >= 0; i--) {
		if(p1[i] != 0 && p1[i + 1] != 0) printf("%08d", p1[i]);
		else if(p1[i] != 0) printf("%d", p1[i]);
	}
	
	return 0;
}
