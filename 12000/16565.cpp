#include <stdio.h>

#define MOD 10007

// (num^exp) % MOD 빨리 구하기  
int pow(int num, int exp) {
	long long r = 1;
	long long t = num;
	int b = exp, c = MOD;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 일때 (ki는 0 또는 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(b > 0) { // kn -> k0 순서로 진행  
		if(b % 2 == 1)  // ki가 0인지 1인지 확인  
			r = (r * t) % c; // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하기  
		t = (t * t) % c; // 다음 t값 계산  
		b = b / 2; 
	}
	
	return r % c;
}

// 팩토리얼 계산 (0! ~ 52!) 
int fact(int n) {
	static int facts[53] = {1, 0,};
	
	// 범위 확인  
	if(n < 0 || n > 52) return -1;
	
	// 팩토리얼 계산  
	if(facts[n] != 0) return facts[n];
	else return facts[n] = fact(n - 1) * n % MOD;
}

// 조합 계산  
int comb(int n, int r) {

	// 범위 확인  
	if(n <  0 || n >  52) return 0;
	if(r <  0 || r >   n) return 0;
	if(r == 0 || r ==  n) return 1;
		
	// 조합 계산  
	r = (long long) fact(r) * fact(n - r) % MOD;
	r = pow(r, MOD - 2);
	r = (long long) r * fact(n) % MOD; 
	
	return r;
}

int main() {
	
	int n, r = 0;
	
	// 입력  
	scanf("%d", &n);
	
	// 경우의 수 계산  
	for(int i = 1; i <= 13; i++) {
		if(i % 2 == 1) r = (r + comb(13, i) * comb(52 - 4 * i, n - 4 * i)      ) % MOD;
		else 		   r = (r - comb(13, i) * comb(52 - 4 * i, n - 4 * i) + MOD) % MOD;
	}
	
	// 출력  
	printf("%d", r);
	
	return 0;
}
