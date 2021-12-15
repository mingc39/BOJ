#include <stdio.h>

// 최소공약수 구하기
int lcm(int a, int b) {
	int l, s, t;
	if(a > b) { l = a; s = b; }
	else if(a < b)  { l = b; s = a; }
	else { l = a; s = 0; }
	while(s != 0) {
		t = s;
		s = l % s;
		l = t;
	}
	return a / l * b;
}

int main() {
	int T, n, m, x, y;
	for(scanf("%d", &T); T > 0; T--) {
		// k % m == x
		// k % n == y
		// 를 만족하는 k 값을 찾아야한다
		scanf("%d %d %d %d", &m, &n, &x, &y);
		// 나머지 연산 결과의 범위는 0 ~ (n - 1)인데 x, y 는 1 ~ n 범위로 입력됨 
		if(x == m) x = 0;
		if(y == n) y = 0;
		
		int i, r = -1;
		int l = lcm(n, m);
		// i % m == x 을 만족하는 i은 x부터 m 간격으로 존재
		// <m, n>(마지막 년도)는 m, n의 최소공배수이므로 m, n의 최소 공배수까지만 확인하면 됨 
		for(i = x; i <= l; i += m) {
			// 해당 i가 i % n == y 만족하는지 확인 
			if(i % n == y) {
				r = i;
				break;
			}
		}
		// 조건에 맞는 값이 없을 수 있음
		// 그런경우 { r = i; break; }가 수행되지 않아 r의 초기값 -1이 출력됨 
		printf("%d\n", r);
	}
	return 0;
}
