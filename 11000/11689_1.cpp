#include <stdio.h>
#include <math.h>
// �޸� �� ���Դ� �ڵ�  

int main() {
	int primes[78498];
	
	{ // �Ҽ� ���ϱ�  
		primes[0] = 2;
		for(int i = 1, n = 3; i < 78498; n += 2) {
			int k = 1, sroot = sqrt(n);
			for(int j = 0; j < i && primes[j] <= sroot; j++) if(n % primes[j] == 0) { k = 0; break; }
			if(k != 0) primes[i++] = n;
		}
	}
	
	int factors[78498], l = 0;
	long long num, lFactor = 0;
	
	// �Է� 
	scanf("%lld", &num);
	
	{ // ���μ� ����  
		lFactor = num;
		int i = 0; 
		
		while(i < 78497) {
			if(lFactor == 1) break;
			if(lFactor % primes[i] == 0) {
				factors[l++] = primes[i];
				while(lFactor % primes[i] == 0) lFactor /= primes[i];
			} else i++;
		}
	}
	
	{ // ���Ϸ� �� �Լ� ���ϱ�  
		for(int i = 0; i < l; i++) num = num / factors[i] * (factors[i] - 1);
		if(lFactor > 1) num = num / lFactor * (lFactor - 1);
	}
	
	printf("%lld", num);
	
	return 0;
}
