#include <stdio.h>
#include <stdlib.h>

int subseq1[1048576];
int subseq2[1048576];

int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int main() {
	int n, m, s, a[40];
	
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	m = (n + 1) / 2;
	n = n / 2;
	
	for(int i = 0; i < 1 << n; i++) {
		subseq1[i] = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) subseq1[i] += a[j];
		}
	}
	
	for(int i = 0; i < 1 << m; i++) {
		subseq2[i] = 0;
		for(int j = 0; j < m; j++) {
			if(i & (1 << j)) subseq2[i] += a[j + n];
		}
	}
	
	qsort(subseq1, (1 << n), sizeof(int), cmp);
	qsort(subseq2, (1 << m), sizeof(int), cmp);
	
	int i = 0, j = (1 << m) - 1;
	long long cnt = 0;
	while(i < 1 << n && j >= 0) {
		if(subseq1[i] + subseq2[j] < s) i++;
		else if(subseq1[i] + subseq2[j] > s) j--;
		else {
			int t1 = subseq1[i];
			int t2 = subseq2[j];
			int c1 = 0, c2 = 0;
			while(subseq1[i] == t1 && i < 1 << n) {
				i++; c1++;
			}
			while(subseq2[j] == t2 && j >= 0) {
				j--; c2++;
			}
			cnt += (long long) c1 * c2;
		}
	}	
	if(s == 0) cnt--;
	
	printf("%lld", cnt);
	
	return 0;
}
