#include <stdio.h>
  
long long p[60]; // p[n] = 2^n

// 0부터 n까지 1의 개수 세기  
long long c(long long n) {
	// 2^k - 1 >= n 을 만족하는 최소 k 구하기  
	int k = 0;
	while(p[k] - 1 < n) k++;
	// 2^k - 1 = n 인 경우 k*2^(k-1) 반환 
	/* 0으로 시작하는 경우를 포함한 k자리 2진수에서
	   어떤 자리에 1이 들어올 수 있는 경우는 2^(k-1)가지
	   1이 들어갈 수 있는 자리가 k개 있으므로 전체 1 개수는 k*2^(k-1)*/  
	if(p[k] - 1 == n) return p[k - 1] * k;
	// 2^k - 1 > n 인 경우 c(2^k-1) + (n-(p[k-1]-1)) + c(n-2^(k-1)) 반환
	/* 0부터 2^(k-1) - 1까지 1의 개수 + 2^(k-1)부터 n까지의 맨 앞의 1의 갯수
	   + 2^(k-1)부터 n까지의 맨 앞을 제외한 1의 갯수
	*/ 
	return n - (p[k - 1] - 1) + c(n - p[k - 1]) + c(p[k - 1] - 1);
}

int main() {
	// 2^n을 자주 계산해야 해서 필요한만큼(아마 n=54내외일듯) 미리 계산해서 저장  
	p[0] = 1;
	for(int i = 1; i < 60; i++) p[i] = p[i - 1] * 2;
	
	long long a, b;
	
	// 입력  
	scanf("%lld %lld", &a, &b);
	
	// 계산 및 출력  
	printf("%lld", c(b) - c(a - 1));
	
	return 0;
} 
