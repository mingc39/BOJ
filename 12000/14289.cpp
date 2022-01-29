#include <stdio.h> 

// 행렬 곱  
void mm(long long a[50][50], long long b[50][50], long long c[50][50]) {
	for(long long i = 0; i < 50; i++) {
		for(long long j = 0; j < 50; j++) {
			long long t = 0;
			for(long long k = 0; k < 50; k++) {
				t += a[i][k] * b[k][j];
			}
			c[i][j] = t % 1000000007;
		}
	}
}

// 행렬 복사  
void mc(long long src[50][50], long long dst[50][50]) {
	for(long long i = 0; i < 50; i++) {
		for(long long j = 0; j < 50; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void mp(long long a[50][50], long long c[50][50], long long m) {
	long long b[50][50];
	
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
	// 단위행렬 
	long long r[50][50] = {0,};
	// 캠퍼스 지도  
	long long a[50][50] = {0,};
	
	// 산책 시간 D  
	int d, n, m;
	
	// 건물, 길 개수 입력  
	scanf("%d %d", &n, &m);
	
	// 단위행렬 초기화  
	for(int i = 0; i < n; i++) r[i][i] = 1;
	
	// 캠퍼스 지도 입력  
	for(int i = 0; i < m; i++) {
		int t;
		scanf("%d %d", &d, &t);
		d--; t--;
		a[d][t] = 1;
		a[t][d] = 1;
	}
	
	// 이동 시간 입력  
	scanf("%d", &d);
	
	// r = m ^ d 계산  
	mp(a, r, d);
	
	// 정보과학관->...->정보과학관 경로수 출력  
	printf("%d", r[0][0] % 1000000007);
	
	return 0;
}
