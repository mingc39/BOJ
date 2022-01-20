#include <stdio.h>

int main() {
	int n, a[100000], t, l, r, m;
	int minv = 2100000000, mina = -1, minb = -1;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for(int i = 0; i < n; i++) {
		l = i + 1; r = n;
		m = (l + r) / 2;
		while(l != r) {
			t = m;
			if(a[i] + a[t] > 0) {
				r = m;
				m = (l + r) / 2;
			} else if(a[i] + a[t] < 0) {
				l = m + 1;
				m = (l + r) / 2;
			} else {
				minv = 0;
				mina = a[i];
				minb = a[t];
				break;
			}
			
			if(minv > a[i] + a[t] && a[i] + a[t] >= 0) {
				minv = a[i] + a[t];
				mina = a[i];
				minb = a[t];
			} else if(minv > -(a[i] + a[t]) && a[i] + a[t] < 0) {
				minv = -(a[i] + a[t]);
				mina = a[i];
				minb = a[t];
			}
		}
	}
	
	printf("%d %d", mina < minb ? mina : minb, mina > minb ? mina : minb);
	
	return 0;
}
