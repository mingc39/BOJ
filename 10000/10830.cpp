#include <stdio.h>

// 행렬 곱  
void mm(int a[5][5], int b[5][5], int c[5][5], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int t = 0;
			for(int k = 0; k < n; k++) {
				t += a[i][k] * b[k][j];
			}
			c[i][j] = t % 1000;
		}
	}
}

// 행렬 복사  
void mc(int src[5][5], int dst[5][5], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

// 행렬 출력  
void print(int src[5][5], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", src[i][j]);
		}
		putchar('\n');
	}
}

int main() {
	int size;
	long long m;
	int a[5][5]; // (원래 a)^(2^n) % 1000의 값을 저장
	int b[5][5]; // 임시 저장용 
	int c[5][5] = {	{1, 0, 0, 0, 0}, // 여기에 a^n을 계속 곱해나갈거에요 최종 결과도 여기에 저장돼요 
					{0, 1, 0, 0, 0}, // 행렬이니까 1 대신 단위행렬  
					{0, 0, 1, 0, 0},
					{0, 0, 0, 1, 0},
					{0, 0, 0, 0, 1}};
	
	// 입력  
	scanf("%d %lld", &size, &m);
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	// b = k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0 일때 (ki는 0 또는 1) 
	// a^b = a^(k0 * 2^n + k1 * 2^(n - 1) + ... + kn * 2^0)
	// = a^(k0 * 2^n) * a^(k1 * 2^(n - 1)) * ... * a^(kn * 2^0)
	while(m > 0) { // kn -> k0 순서로 진행
		if(m % 2 == 1) { // ki가 0인지 1인지 확인  
			mm(a, c, b, size); // ki가 1인경우 r에 t = a^(2^(n - i)) 곱하기  
			mc(b, c, size); // 연산 결과 복사  
		}
		mm(a, a, b, size); // 다음 t값 계산  
		mc(b, a, size); // 연산 결과 복사 
		m = m / 2;
	}
	
	// 출력  
	print(c, size);
	
	return 0;
}
