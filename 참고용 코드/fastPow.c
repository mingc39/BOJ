#define MOD 1000000007

// MOD 값 정의시 num의 exp 제곱을 MOD로 나눈 나머지 반환
// MOD 값 미정의시 num의 exp 제곱을 반환 (int 범위 초과 주의)

// ==========< 빠른 제곱 >==========
int pow(int num, int exp) {
	long long r = 1;
	long long t = num;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 일때 (ki는 0 또는 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(exp > 0) { // kn -> k0 순서로 진행  
		#ifdef MOD
		if(exp % 2 == 1)  // ki가 0인지 1인지 확인  
			r = (r * t) % MOD; // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하고 MOD에 대한 나머지 저장   
		t = (t * t) % MOD; // 다음 t값의 MOD에 대한 나머지 저장 
		#else 
		if(exp % 2 == 1)  // ki가 0인지 1인지 확인  
			r = (r * t); // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하기  
		t = (t * t); // 다음 t값 계산  
		#endif
		exp = exp / 2; 
	}
	
	return r;
}
// ==============================