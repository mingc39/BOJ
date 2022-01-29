#include <stdio.h>

int main() {
	// 이동 비용  
	int c[5][5] = {
		{0, 2, 2, 2, 2},
		{0, 1, 3, 4, 3},
		{0, 3, 1, 3, 4},
		{0, 4, 3, 1, 3},
		{0, 3, 4, 3, 1}
	};
	
	// 배열 선언 
	int a1[5][5];
	int a2[5][5];
	// 배열 내용 swap을 위해 포인터로 바꾸기  
	int (*a)[5] = a1;
	int (*b)[5] = a2;
	int (*t)[5];
	// 입력용 변수  
	int in;
	
	// 초기화  
	a1[0][0] = 0; a2[0][0] = 0;
	for(int i = 1; i < 25; i++) {
		a1[i / 5][i % 5] = -1;
		a2[i / 5][i % 5] = -1;
	}
	
	// 초기 입력 및 시작부터 0일때 던지기(?) 
	scanf("%d", &in);
	if(in == 0) { putchar('0'); return 0; }
	while(in) {
		// 배열 b초기화  
		for(int i = 0; i < 25; i++) b[i / 5][i % 5] = -1;
		// 왼발 이동
		for(int i = 0; i <= 4; i++) {
			b[in][i] = 100000000;
			for(int j = 0; j <= 4; j++) {
				if(a[j][i] < 0) continue;
				if(b[in][i] > a[j][i] + c[j][in]) b[in][i] = a[j][i] + c[j][in];
			}
		}
		// 오른발 이동
		for(int i = 0; i <= 4; i++) {
			b[i][in] = 100000000;
			for(int j = 0; j <= 4; j++) {
				if(a[i][j] < 0) continue;
				if(b[i][in] > a[i][j] + c[j][in]) b[i][in] = a[i][j] + c[j][in];
			}
		}
		// a<->b swap
		t = a;
		a = b;
		b = t;
		// 다음 입력 받기  
		scanf("%d", &in);
	}
	
	// 최소값 구하기(-1 제외) 
	in = 100000000;
	for(int i = 0; i < 25; i++) if(in > a[i / 5][i % 5] && a[i / 5][i % 5] > 0) in = a[i / 5][i % 5];
	
	// 출력  
	printf("%d", in);
	
	return 0;
}
