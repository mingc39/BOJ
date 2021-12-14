#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int i = *(int *)a;
    int j = *(int *)b;
    
    if(i < j) return -1;
    if(i > j) return 1;
    return 0;
}

int main() {
	int n, f, c, s = 0;
	int a[500000];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	qsort(a, n, sizeof(int), compare);
	f = 0; c = 0;
	int mc = 0, mp = 0, m2 = 0;  
	for(int i = 0; i < n; i++) {
		if(a[f] == a[i]) c++;
		else {
			if(mc == c && m2 == 0) {
				mp = f;
				m2 = 1;
			} else if(mc < c) {
				mp = f;
				mc = c;
				m2 = 0;
			}
			f = i;
			c = 1;
		}
	}
	if(mc == c && m2 == 0) {
		mp = f;
		m2 = 1;
	} else if(mc < c) {
		mp = f;
		mc = c;
		m2 = 0;
	}
	printf("%.0lf\n", (double) s / n);
	printf("%d\n", a[(n - 1) / 2]);
	printf("%d\n", a[mp]);
	printf("%d", a[n - 1] - a[0]);
	return 0;
}
