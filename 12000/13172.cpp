#include <stdio.h>
#define MODULAR 1000000007

// 최대공약수 
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

// 적절한 소수 p에 대해서 n의 역원(n^(p - 2) mod p) 구하기 
int reci(int n, int p) {
	long long r = 1, t = n;
	int m = p - 2;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 일때 (ki는 0 또는 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(m > 0) { // kn -> k0 순서로 진행
		if(m % 2 == 1) { // ki가 0인지 1인지 확인  
			r = (r * t) % p; // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하기
		}
		t = (t * t) % p; // 다음 t값 계산  
		m /= 2;
	}
	return r % p;
}

int main() {
	int m, n, s, t, sum = 0;
	
	// 주사위 수 입력   
	scanf("%d", &m);
	
	while(m-- > 0) {
		// 주사위 정보 입력  
		scanf("%d %d", &n, &s);
		
		// 기약이 아니면 약분  
		t = gcd(n, s);
		n /= t;
		s /= t;
		
		// s * n^-1 mod p 구해서 sum에 더하기 
		sum = (sum + ((long long)s * reci(n, MODULAR)) % MODULAR) % MODULAR;
	}
	
	// 주사위에서 나온 숫자들의 합의 기댓값 출력 
	printf("%d", sum);
	
	return 0;
}
