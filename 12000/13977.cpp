#include <stdio.h>

#define MOD 1000000007

int fact[4000000];

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

int main() {
	
	// 팩토리얼 미리 계산  
	fact[0] = 1;
	for(int i = 0; i < 4000000; i++) fact[i + 1] = (long long) fact[i] * (i + 2) % MOD;
	
	// m 입력  
	int m, n, k;
	scanf("%d", &m);
	
	while(m--) {
		// n, k 입력 밑 답이 1인경우 처리  
		scanf("%d %d", &n, &k);
		if(k == 0 || k == n) {
			printf("%d\n", 1);
			continue;
		}
		
		// 조합 계산  
		k = (long long) fact[k - 1] * fact[n - k - 1] % MOD;
		k = pow(k, MOD - 2);
		k = (long long) k * fact[n - 1] % MOD;
		
		// 출력  
		printf("%d\n", k);
	}
	
	return 0;
}
