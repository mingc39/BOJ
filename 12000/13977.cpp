#include <stdio.h>

#define MOD 1000000007

int fact[4000000];

// (num^exp) % MOD ���� ���ϱ�  
int pow(int num, int exp) {
	long long r = 1;
	long long t = num;
	int b = exp, c = MOD;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 �϶� (ki�� 0 �Ǵ� 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(b > 0) { // kn -> k0 ������ ����  
		if(b % 2 == 1)  // ki�� 0���� 1���� Ȯ��  
			r = (r * t) % c; // ki�� 1�ΰ�� r�� t = a^(2^(n - i)) ���ϱ�  
		t = (t * t) % c; // ���� t�� ���  
		b = b / 2; 
	}
	
	return r % c;
}

int main() {
	
	// ���丮�� �̸� ���  
	fact[0] = 1;
	for(int i = 0; i < 4000000; i++) fact[i + 1] = (long long) fact[i] * (i + 2) % MOD;
	
	// m �Է�  
	int m, n, k;
	scanf("%d", &m);
	
	while(m--) {
		// n, k �Է� �� ���� 1�ΰ�� ó��  
		scanf("%d %d", &n, &k);
		if(k == 0 || k == n) {
			printf("%d\n", 1);
			continue;
		}
		
		// ���� ���  
		k = (long long) fact[k - 1] * fact[n - k - 1] % MOD;
		k = pow(k, MOD - 2);
		k = (long long) k * fact[n - 1] % MOD;
		
		// ���  
		printf("%d\n", k);
	}
	
	return 0;
}
