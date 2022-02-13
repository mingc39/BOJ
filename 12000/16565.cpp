#include <stdio.h>

#define MOD 10007

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

// ���丮�� ��� (0! ~ 52!) 
int fact(int n) {
	static int facts[53] = {1, 0,};
	
	// ���� Ȯ��  
	if(n < 0 || n > 52) return -1;
	
	// ���丮�� ���  
	if(facts[n] != 0) return facts[n];
	else return facts[n] = fact(n - 1) * n % MOD;
}

// ���� ���  
int comb(int n, int r) {

	// ���� Ȯ��  
	if(n <  0 || n >  52) return 0;
	if(r <  0 || r >   n) return 0;
	if(r == 0 || r ==  n) return 1;
		
	// ���� ���  
	r = (long long) fact(r) * fact(n - r) % MOD;
	r = pow(r, MOD - 2);
	r = (long long) r * fact(n) % MOD; 
	
	return r;
}

int main() {
	
	int n, r = 0;
	
	// �Է�  
	scanf("%d", &n);
	
	// ����� �� ���  
	for(int i = 1; i <= 13; i++) {
		if(i % 2 == 1) r = (r + comb(13, i) * comb(52 - 4 * i, n - 4 * i)      ) % MOD;
		else 		   r = (r - comb(13, i) * comb(52 - 4 * i, n - 4 * i) + MOD) % MOD;
	}
	
	// ���  
	printf("%d", r);
	
	return 0;
}
