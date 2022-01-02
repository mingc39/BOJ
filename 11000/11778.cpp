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

// �ִ����� ���ϱ�(2609���� ������) 
long long gcd(long long n, long long m) {
	long long l, s, t;
	if(n > m) { l = n; s = m; }
	else if(n < m)  { l = n; s = m; }
	else { l = n; s = 0; }
	while(s != 0) {
		t = s;
		s = l % s;
		l = t;
	}
	return l;
}

int main() {
	long long n, m;
	int a, b, t;
	
	scanf("%lld %lld", &n, &m);
	
	b = fibo(gcd(n, m));
	
	printf("%d", b);
	
	return 0;
}
