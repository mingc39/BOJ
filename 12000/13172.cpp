#include <stdio.h>
#define MODULAR 1000000007

// �ִ����� 
int gcd(int a, int b) {
	int l, s, t;
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

// ������ �Ҽ� p�� ���ؼ� n�� ����(n^(p - 2) mod p) ���ϱ� 
int reci(int n, int p) {
	long long r = 1, t = n;
	int m = p - 2;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 �϶� (ki�� 0 �Ǵ� 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(m > 0) { // kn -> k0 ������ ����
		if(m % 2 == 1) { // ki�� 0���� 1���� Ȯ��  
			r = (r * t) % p; // ki�� 1�ΰ�� r�� t = a^(2^(n - i)) ���ϱ�
		}
		t = (t * t) % p; // ���� t�� ���  
		m /= 2;
	}
	return r % p;
}

int main() {
	int m, n, s, t, sum = 0;
	
	// �ֻ��� �� �Է�   
	scanf("%d", &m);
	
	while(m-- > 0) {
		// �ֻ��� ���� �Է�  
		scanf("%d %d", &n, &s);
		
		// ����� �ƴϸ� ���  
		t = gcd(n, s);
		n /= t;
		s /= t;
		
		// s * n^-1 mod p ���ؼ� sum�� ���ϱ� 
		sum = (sum + ((long long)s * reci(n, MODULAR)) % MODULAR) % MODULAR;
	}
	
	// �ֻ������� ���� ���ڵ��� ���� ��� ��� 
	printf("%d", sum);
	
	return 0;
}
