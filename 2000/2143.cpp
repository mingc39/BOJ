#include <stdio.h>
#include <stdlib.h>

int sa[1000000], la = 0;
int sb[1000000], lb = 0;

int cmp(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int t, n, m;
	int a[1001], b[1001];
	
	scanf("%d", &t);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	
	a[0] = 0; b[0] = 0;
	
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	for(int i = 1; i <= m; i++) b[i] += b[i - 1];
	
	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++) sa[la++] = a[j] - a[i];
	for(int i = 0; i <= m; i++)
		for(int j = i + 1; j <= m; j++) sb[lb++] = b[j] - b[i];
	
	qsort(sa, la, sizeof(int), cmp);
	qsort(sb, lb, sizeof(int), cmp);
	
	int i = 0, j = lb - 1;
	long long c = 0;
	while(i < la && j >= 0) {
		if(sa[i] + sb[j] < t) i++;
		else if(sa[i] + sb[j] > t) j--;
		else {
			i++; j--;
			int ca = 1, cb = 1;
			while(sa[i] == sa[i - 1] && i < la) {
				i++; ca++;
			}
			while(sb[j] == sb[j + 1] && j >= 0) {
				j--; cb++;
			}
			c += (long long) ca * cb;
		}
	}
	
	printf("%lld", c);
	
	return 0;
}
