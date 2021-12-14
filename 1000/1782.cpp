#include <stdio.h>

// 1~n자리 거울 수 개수 
long long gn2(long long n) {
	if(n <= 0) return 0;
	long long r;
	if(n % 2 == 0) r = 8;
	else r = 4;
	for(n = (n - 1) / 2; n > 0; n--) r *= 5;
	return r - 1;
}

// n번째 거울 수 
long long gnn(long long k) {
	int l = 1;
	int m1[6] = {8, 0, 1, 2, 5, 8};
	int m2[6] = {8, 0, 1, 5, 2, 8};
	int m3[5] = {8, 1, 2, 5, 8};
	int m4[5] = {8, 1, 5, 2, 8};
	int a[24];
	int t;
	while(k > gn2(l)) l++;
	int n = k - gn2(l - 1);
	if(l == 1) {
		if     (n == 1) a[1] = 0;
		else if(n == 2) a[1] = 1;
		else if(n == 3) a[1] = 8;
	} else if(l % 2 == 0) {
		// 짝수자릿수 
		for(int i = l / 2 + 1; i < l; i++) {
			t = n % 5;
			a[        i] = m1[t];
			a[l - i + 1] = m2[t];
			n = (n + 4) / 5;
		}
		t = n % 4;
		a[l] = m3[t];
		a[1] = m4[t];
	} else {
		// 홀수자릿수 
		a[l / 2 + 1] = m1[n % 3];
		n = (n + 2) / 3;
		for(int i = l / 2 + 2; i < l; i++) {
			t = n % 5;
			a[        i] = m1[t];
			a[l - i + 1] = m2[t];
			n = (n + 4) / 5;
		}
		t = n % 4;
		a[l] = m3[t];
		a[1] = m4[t];
	}
	long long m = 0;
	for(int i = l; i >= 1; i--) {
		m = m * 10 + a[i];
	}
	return m;
}

// n 이하의 거울 수 개수
long long gn3(long long n) {
	if(n < 0) return 0;
    
	int s = 0, e = 3125000;
	int m1, m2;
	long long g1, g2;
	
	m1 = (s + e) / 2;
	m2 = (s + e + 1) / 2;
	g1 = gnn(m1);
	g2 = gnn(m2);
	while(g1 > n || n >= g2) {
		if(g1 > n) {
			e = m1;
		} else if(n >= g2) {
			s = m2;
		}
		m1 = (s + e) / 2;
		m2 = (s + e + 1) / 2;
		g1 = gnn(m1);
		g2 = gnn(m2);
	}
	return m1;
}

int main() {
	long long a, b;
	long long l;
	
	scanf("%lld %lld", &a, &b);
	l = gn3(b) - gn3(a - 1);
	printf("%lld", l);
	
	return 0;
}