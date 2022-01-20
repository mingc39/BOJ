#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int n, a[5000], t, l, r, m;
	long long minv = 3100000000;
	int mina = -1, minb = -1, minc = -1;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	
	for(int j = 0; j < n; j++) {
		for(int i = j + 1; i < n; i++) {
			l = i + 1; r = n;
			m = (l + r) / 2;
			while(l != r) {
				t = m;
				if((long long)a[i] + a[j] + a[t] > 0) {
					r = m;
					m = (l + r) / 2;
				} else if((long long)a[i] + a[j] + a[t] < 0) {
					l = m + 1;
					m = (l + r) / 2;
				} else {
					minv = 0;
					mina = a[i];
					minb = a[t];
					minc = a[j];
					break;
				}
				
				if(minv > (long long)a[i] + a[j] + a[t] && (long long)a[i] + a[j] + a[t] >= 0) {
					minv = (long long)a[i] + a[j] + a[t];
					mina = a[i];
					minb = a[t];
					minc = a[j];
				} else if(minv > -((long long)a[i] + a[j] + a[t]) && (long long)a[i] + a[j] + a[t] < 0) {
					minv = -((long long)a[i] + a[j] + a[t]);
					mina = a[i];
					minb = a[t];
					minc = a[j];
				}
			}
		}
	}
	
	int mini[3];
	mini[0] = mina;
	mini[1] = minb;
	mini[2] = minc;
	qsort(mini, 3, sizeof(int), cmp);
	printf("%d %d %d", mini[0], mini[1], mini[2]);
	
	return 0;
}
