#include <stdio.h>

int main() {
	int n, s[301]; // 계단 수, 각 계단의 점수 
	int m[301]; // 계단별 최대 점수  
	
	// 입력 받기  
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	
	// 초기값(m[0] = 바닥, m[1]~m[2] = 1~2번째 계단) 지정  
	m[0] = 0;
	m[1] = s[1];
	m[2] = s[2] + s[1];
	// 3번째 계단부터 최대 점수 계산  
	for(int i = 3; i <= n; i++) {
		if(m[i - 2] < m[i - 3] + s[i - 1]) m[i] = m[i - 3] + s[i - 1] + s[i];
		else m[i] = m[i - 2] + s[i];
	}
	
	// n번째 계단의 최대 점수 출력  
	printf("%d", m[n]);
	
	// 리턴 0 하고 끝!  
	return 0;
}
