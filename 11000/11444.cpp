#include <stdio.h>
// 이상한 계산법 사용  

long long key[128];
int value[128];
int length = 0;

int fibo(long long n) {
	// 2이하인 경우  
	if(n <= 2) return 1;
	
	// 이미 계산된 경우  
	for(int i = 0; i < length; i++) {
		if(key[i] == n) {
			return value[i];
		}
	}
	
	// 새로 계산해야하는 경우 
	long long a, b, t;
	if(n % 2 == 1) {
		a = fibo(n / 2); b = fibo(n / 2 + 1);
		t = (a * a + b * b) % 1000000007;
	} else {
		a = fibo(n / 2); b = fibo(n / 2 - 1);
		t = (a + 2 * b) * a % 1000000007;
	}
	key[length] = n;
	value[length] = t;
	length++;
	return t;
}

int main() {
	long long n;
	int a, b, t;
	
	scanf("%lld", &n);
	
	b = fibo(n);
	
	printf("%d", b);
	
	return 0;
}
