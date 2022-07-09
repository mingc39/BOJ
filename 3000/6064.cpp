#include <stdio.h>

// 최소공배수 구하기
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
		// 나머지 연산 결과의 범위는 0 ~ (n - 1)인데 y 는 1 ~ n 범위로 입력됨 
		if(y == n) y = 0;
		
		int i, l = lcm(n, m);
		// i % m == x 을 만족하는 i은 x부터 m 간격으로 존재
		// <m, n>(마지막 년도)는 m, n의 최소공배수이므로 m, n의 최소 공배수까지만 확인하면 됨 
		for(i = x; i <= l; i += m) 
			// 해당 i가 i % n == y 만족하는지 확인 
			if(i % n == y) break;
		
		// 조건에 맞는 값이 없을 수 있음
		// 그런경우 break; 로 반복문을 빠져나오지 않고 i > l 이 되어 반복문이 종료 됨 
		if(i <= l) printf("%d\n", i);
		else printf("%d\n", -1);
	}
	return 0;
}
