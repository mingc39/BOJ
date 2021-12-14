#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
	
	long long min, max;
	scanf("%lld %lld", &min, &max);
	
	// 소수 구하기
	int pu = sqrt(max);
	int pn[80000], pc = 0;
	long long pp[80000];
	
	int np, sq;
	pn[0] = 2; pp[0] = 4; pc = 1;
	for(int i = 3; i <= pu; i += 2) {
		
		np = 0; sq = sqrt(i);
		
		for(int j = 0; j < pc; j++) {
			if(i % pn[j] == 0) {
				np = 1;
				break;
			}
			if(sq < pn[j]) break;
		}
		
		if(np == 0) {
			pn[pc] = i;
			pp[pc] = (long long) i * i;
			pc++;
		}
	}
	
	// 제곱ㄴㄴ수 판별
	bool nums[1000010] = {0, };
	long re;
	for(int i = 0; i < pc; i++) {
		re = min % pp[i];
		if(re == 0) re = pp[i];
		for(int j = 1; min + pp[i] * (j - 1) <= max; j++) {
			if(pp[i] * j - re < 0 || pp[i] * j - re > max - min) continue;
			nums[pp[i] * j - re] = 1;
		}
	}

	int powss = (max - min) + 1;
	for(int i = 0; i <= max - min; i++) powss -= nums[i];
	
	// 결과출력
	printf("%d", powss);
	
	return 0;
}