#include <stdio.h>
#include <math.h>

int main() {
	
	int M, N;
	scanf("%d %d", &M, &N);
	
	int pn[80000], pc = 0;
	
	int np, sq;
	pn[0] = 2; pc = 1;
	for(int i = 3; i <= N; i += 2) {
		
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
			pc++;
		}
	}
	
	for(int i = 0; i < pc; i++) {
		if(pn[i] < M) continue;
		printf("%d\n", pn[i]);
	}
	
	return 0;
}