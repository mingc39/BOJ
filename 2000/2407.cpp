#include <stdio.h>

// 카리스마 대빵 큰 숫자에 적절한 수를 곱하기 
int* mul(int* n, int k, int l) {
	if(n == NULL) return NULL;
	long long a, u = 0;
	for(int i = 0; i < l; i++) {
		if(u > 100000000) return NULL;
		a = n[i];
		a = a * k + u;
		u = a / 100000000;
		n[i] = a % 100000000;
	}
	if(u != 0) return NULL;
	return n;
}

// 카리스마 대빵 큰 숫자를 적절한 수로 나누기  
int* div(int* n, int k, int l) {
	if(n == NULL) return NULL;
	long long a, d = 0;
	for(int i = l - 1; i >= 0; i--) {
		a = n[i] + d * 100000000;
		d = a % k;
		n[i] = a / k;		
	}
	return n;
}

// 카리스마 대빵 큰 숫자를 적절하게 출력하기 
int print(int *n, int l) {
	if(n == NULL) return -1;
	int p = 0;
	for(int i = l - 1; i >= 0; i--) {
		if(p != 0) {
			printf("%08d", n[i]);
		} else if(n[i] != 0) {
			printf("%d", n[i]);
			p = 1;
		}
	}
	if(p == 0) printf("0");
	return 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int c[20] = {0,}; // 카리스마 대빵 큰 숫자! 
	c[0] = 1; // 곱하기, 나누기를 할 것이므로 초기값 1 
	
	// n * (n - 1) * ... * (n - m + 1)
	for(int i = n; i > n - m; i--) {
		mul(c, i, 20);
	}
	
	// m * (m - 1) * ... * 1
	for(int i = 1; i <= m; i++) {
		div(c, i, 20);
	}
	
	print(c, 20);
	
	return 0;
}
