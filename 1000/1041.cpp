#include <stdio.h>

int main() {
	int n, t;
	int a, b, c;
	
	scanf("%d", &n);
	
	// 주사위가 1개인 경우 
	if(n == 1) {
		// 다 더하고 제일 큰거 빼기 
		a = 0; b = 0;
		for(int i = 0; i < 6; i++) {
			scanf("%d", &c);
			a += c;
			if(b < c) b = c;
		}
		a -= b;
		printf("%d", a);
		
		return 0;
	}
	
	// 주사위가 많은 경우
	// 입력받아서 반대편에 있는 면끼리 최소값 구하기  
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &t);	if(c > t) c = t; // C <-> D
	scanf("%d", &t);	if(b > t) b = t; // B <-> E
	scanf("%d", &t);	if(a > t) a = t; // A <-> F
	
	// 오름차순으로 정렬 
	if(a > b) {
		t = a;
		a = b;
		b = t;
	} 
	if(b > c) {
		t = b;
		b = c;
		c = t;
	} 
	if(a > b) {
		t = a;
		a = b;
		b = t;
	} 
	
	// 값 계산 및 출력
	printf("%lld", a * ((long long) n * (5 * n - 8) + 4) + (b * 8 * (n - 1)) + (c * 4));
	
	return 0;
}
