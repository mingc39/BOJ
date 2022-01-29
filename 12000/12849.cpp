#include <stdio.h> 

// 행렬 곱  
void mm(long long a[8][8], long long b[8][8], long long c[8][8]) {
	for(long long i = 0; i < 8; i++) {
		for(long long j = 0; j < 8; j++) {
			long long t = 0;
			for(long long k = 0; k < 8; k++) {
				t += a[i][k] * b[k][j];
			}
			c[i][j] = t % 1000000007;
		}
	}
}

// 행렬 복사  
void mc(long long src[8][8], long long dst[8][8]) {
	for(long long i = 0; i < 8; i++) {
		for(long long j = 0; j < 8; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void mp(long long a[8][8], long long c[8][8], long long m) {
	long long b[8][8];
	
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 일때 (ki는 0 또는 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(m > 0) { // kn -> k0 순서로 진행
		if(m % 2 == 1) { // ki가 0인지 1인지 확인  
			mm(a, c, b); // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하기  
			mc(b, c); // 연산 결과 복사  
		}
		mm(a, a, b); // 다음 t값 계산  
		mc(b, a); // 연산 결과 복사 
		m = m / 2;
	}
}

int main() {
	// 8x8 단위행렬 
	long long r[8][8] = {{1, 0, 0, 0, 0, 0, 0, 0},
						 {0, 1, 0, 0, 0, 0, 0, 0},
						 {0, 0, 1, 0, 0, 0, 0, 0},  
						 {0, 0, 0, 1, 0, 0, 0, 0},
						 {0, 0, 0, 0, 1, 0, 0, 0},
						 {0, 0, 0, 0, 0, 1, 0, 0},
						 {0, 0, 0, 0, 0, 0, 1, 0},
						 {0, 0, 0, 0, 0, 0, 0, 1}};
	// 캠퍼스 지도  
	long long m[8][8] = {{0, 1, 1, 0, 0, 0, 0, 0},
						 {1, 0, 1, 1, 0, 0, 0, 0},
						 {1, 1, 0, 1, 1, 0, 0, 0},  
						 {0, 1, 1, 0, 1, 1, 0, 0},
						 {0, 0, 1, 1, 0, 1, 0, 1},
						 {0, 0, 0, 1, 1, 0, 1, 0},
						 {0, 0, 0, 0, 0, 1, 0, 1},
						 {0, 0, 0, 0, 1, 0, 1, 0}};
	
	// 산책 시간 D  
	int d;
	
	// 입력  
	scanf("%d", &d);
	
	// r = m ^ d 계산  
	mp(m, r, d);
	
	// 정보과학관->...->정보과학관 경로수 출력  
	printf("%d", r[0][0] % 1000000007);
	
	return 0;
}
