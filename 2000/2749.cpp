#include <stdio.h>
// 피사노 주기 사용  

int main() {
	long long n;
	int a, b, t;
	
	scanf("%lld", &n);
	n %= 1500000;
	
	a = 1; b = 1;
	for(int i = 2; i < n; i++) {
		t = (a + b) % 1000000;
		a = b;
		b = t;
	}
	
	printf("%d", b);
	
	return 0;
}
