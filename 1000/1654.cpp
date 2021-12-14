#include <stdio.h>

int main() {
	int k, n, c[10000];
	long long sum = 0;
	scanf("%d %d", &k, &n);
	for(int i = 0; i < k; i++) {
		scanf("%d", &c[i]);	
		sum += c[i];
	}
	
	long long s, m, l;
	l = (int) (sum / n); // k = 10, 랜선길이 전부 2^31 - 1, n = 2 인 경우 l이 int 범위초과 
	m = l / 2;
	s = 1;
	
	long long count = 0;
	int p = 0;
	while(m != l || m != s) {
		count = 0;
		m = (s + l + 1) / 2;
		for(int i = 0; i < k; i++) count += c[i] / m;
		if(count >= n) { s = m; p = 1; }
		else { l = m - 1; p = 0; }
	}
	
	printf("%d", m);
	
	return 0;
}
