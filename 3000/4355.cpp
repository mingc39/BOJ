#include <stdio.h>
#include <math.h>

int main() {
	int primes[78498];
	
	{ // 소수 구하기  
		primes[0] = 2;
		for(int i = 1, n = 3; i < 78498; n += 2) {
			int k = 1, sroot = sqrt(n);
			for(int j = 0; j < i && primes[j] <= sroot; j++) if(n % primes[j] == 0) { k = 0; break; }
			if(k != 0) primes[i++] = n;
		}
	}
	
	long long factors[78498], l = 0;
	long long num;
	
INPUT: 
	// 입력 
	scanf("%lld", &num);
	if(num == 0) return 0;
	l = 0;
	
	{ // 소인수 분해  
		long long n = num;
		int i = 0; 
		
		while(i < 78497) {
			if(n == 1) break;
			if(n % primes[i] == 0) {
				factors[l++] = primes[i];
				while(n % primes[i] == 0) n /= primes[i];
			} else i++;
		}
		if(n != 1) factors[l++] = n;
	}
	
	{ // 오일러 피 함수 구하기  
		for(int i = 0; i < l; i++) num = num / factors[i] * (factors[i] - 1);
	}
	
	printf("%lld\n", num);
	
	goto INPUT; 
}
