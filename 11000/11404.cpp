#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

int main() {
	int n, m;
	int i, j, k;
	int max, sum;
	int a, b, c;
	int f[100][100];
	
	// 초기화  
	for(i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			f[i][j] = INF;
	for(i = 0; i < 100; i++)
		f[i][i] = 0;
	
	// 입력 받기  
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		if(f[a][b] > c) f[a][b] = c;
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
		for(j = 0; j < n; j++) {
			if(f[i][j] < INF) printf("%d ", f[i][j]);
			else {
				putchar('0');
				putchar(' ');
			}
		}
		putchar('\n');
	}
	
	return 0;
}
