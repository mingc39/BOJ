#include <stdio.h>

int n, k;
long long a[1 << 15][100];
int s[15], d[15];

long long gcd(long long a, long long b) {
	long long l, s, t;
	if(a > b) { l = a; s = b; }
	else if(a < b)  { l = b; s = a; }
	else { l = a; s = 0; }
	while(s != 0) {
		t = s;
		s = l % s;
		l = t;
	}
	return l;
}

int main() {
	long long p, q;
	char in[15][51];
	
	// 입력  
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%s", in[i]);
	scanf("%d", &k);
	
	// 숫자별 나머지 구하기  
	for(int i = 0; i < n; i++) {
		int r = 0, t = 0;
		
		for(int j = 0; j < 50; j += 5) {
			
			for(int l = j; l < j + 5; l++) {
				if(in[i][l] == '\0') { t = 1; break; }
				r = r * 10 + in[i][l] - '0';
			}
			
			r %= k;
			if(t != 0) break;
		}
		
		s[i] = r;
	}
	
	// 숫자별 길이 구하기
	for(int i = 0; i < n; i++) {
		int j = 0;
		long long t = 1;
		while(in[i][j] != '\0') {
			j++;
			t = t * 10 % k;
		}
		d[i] = t;
	} 
	
	// 초기화  
	for(int i = 0; i < n; i++) {
		a[1 << i][s[i]] = 1;
	}
	
	// p값 구하기  
	for(int i = 1; i < (1 << n); i++) {
		for(int j = 0; j < k; j++) {
			
			if(a[i][j] == 0) continue;
			
			for(int l = 0; l < n; l++) {
				if(i & (1 << l)) continue;
				a[i | (1 << l)][(j * d[l] + s[l]) % k] += a[i][j];
			}
		}
	}
	p = a[(1 << n) - 1][0];
	
	// q값 구하기  
	q = 1;
	for(int i = 2; i <= n; i++) q *= i;
	
	// 약분  
	if(p == 0) q = 1;
	else if(p == q) p = q = 1;
	else {
		long long t = gcd(p, q);
		p /= t;
		q /= t;
	}
	
	// 출력
	printf("%lld/%lld", p, q); 
	
	return 0;
}
