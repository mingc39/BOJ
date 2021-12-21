#include <stdio.h>

int main() {
	int a, b, c;
	unsigned long long r; // 여기에 a를 계속 곱해나갈거에요 최종 결과도 여기에 저장돼요  
	unsigned long long t; // a^(2^n) % c의 값을 임시로 저장  
	
	scanf("%d %d %d", &a, &b, &c);
	
	// 초기값 지정  
	r = 1;
	t = a;
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 일때 (ki는 0 또는 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(b > 0) { // kn -> k0 순서로 진행  
		if(b % 2 == 1) { // ki가 0인지 1인지 확인  
			r = (r * t) % c; // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하기  
		}
		t = (t * t) % c; // 다음 t값 계산  
		b = b / 2; 
	}
	
	printf("%llu", r);
	
	return 0;
}
