#include <stdio.h>
#include <stdlib.h>

#define INF 10000

int main() {
	int n, m;
	int i, j, k;
	int min, idx;
	int f[100][100];
	
	// 초기화  
	for(i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			f[i][j] = INF;
	
	// 입력 받기  
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf("%d", &k);
			if(k > 0) f[i][j] = k; // 방향 있는 그래프이므로 (j,i)는 할 필요 없음!  
		}
	
	// 플로이드-와샬(1389번에서 쓴거) 
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				if(f[j][k] > f[j][i] + f[i][k])
					f[j][k] = f[j][i] + f[i][k];
	}
	
	// 출력 
	for(i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			printf("%d ", f[i][j] < INF ? 1 : 0); // 경로 길이가 아닌 경로 존재 여부만 출력해야함  
		putchar('\n');
	}
	
	return 0;
}
