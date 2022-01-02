#include <stdio.h>
// �̻��� ���� ���  

long long key[256];
int value[256];
int length = 0;

int fibo(long long n) {
	// 2������ ���  
	if(n <= 2) return 1;
	
	// �̹� ���� ���  
	for(int i = 0; i < length; i++) {
		if(key[i] == n) {
			return value[i];
		}
	}
	
	// ���� ����ؾ��ϴ� ��� 
	long long a, b, t;
	if(n % 2 == 1) {
		a = fibo(n / 2); b = fibo(n / 2 + 1);
		t = (a * a + b * b) % 1000000000;
	} else {
		a = fibo(n / 2); b = fibo(n / 2 - 1);
		t = (a + 2 * b) * a % 1000000000;
	}
	key[length] = n;
	value[length] = t;
	length++;
	return t;
}

int main() {
	long long n, k;
	int a, b, t;
	
	scanf("%lld %lld", &n, &k);
	
	b = (fibo(k + 2) - fibo(n + 1) + 1000000000) % 1000000000;
	
	printf("%d", b);
	
	return 0;
}
