#include <stdio.h>
#include <stdlib.h>

#define INF 10000

int main() {
	int n, m, r;
	int i, j, k;
	int max, sum;
	int a, b, l;
	int f[100][100];
	int t[100];
	
	// 초기화  
	for(i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			f[i][j] = INF;
	for(i = 0; i < 100; i++)
		f[i][i] = 0;
	
	// 입력 받기  
	scanf("%d %d %d", &n, &m, &r);
	for(i = 0; i < n; i++) scanf("%d", &t[i]);
	for(i = 0; i < r; i++) {
		scanf("%d %d %d", &a, &b, &l);
		a--; b--;
		f[a][b] = l;
		f[b][a] = l;
	}
	
	// 플로이드-와샬(1389번에서 쓴거) 
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				if(f[j][k] > f[j][i] + f[i][k])
					f[j][k] = f[j][i] + f[i][k];
	}
	
	// 각 정점 별 얻을 수 있는 아이템 계산 및 최대값 구하기  
	max = 0;
	for(int i = 0; i < n; i++) {
		sum = 0;
		for(int j = 0; j < n; j++) {
			if(f[i][j] <= m) sum += t[j];
		}
		if(sum > max) max = sum;
	}
	
	// 출력 
	printf("%d", max);
	
	return 0;
}
