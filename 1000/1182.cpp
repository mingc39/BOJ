#include <stdio.h>

int subseq1[1048576];

int main() {
	int n, s, a[20];
	
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	for(int i = 1; i < 1 << n; i++) {
		subseq1[i] = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) subseq1[i] += a[j];
		}
	}
	
	int cnt = 0;
	for(int i = 1; i < 1 << n; i++) {
		if(subseq1[i] == s) cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}
